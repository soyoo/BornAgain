// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Export/ExportToPython.cpp
//! @brief     Implements class ExportToPython.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "ExportToPython.h"
#include "Beam.h"
#include "ConvolutionDetectorResolution.h"
#include "Crystal.h"
#include "Distributions.h"
#include "GISASSimulation.h"
#include "HomogeneousMaterial.h"
#include "IFormFactor.h"
#include "InterferenceFunctions.h"
#include "Layer.h"
#include "LayerInterface.h"
#include "LayerRoughness.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "MainComputation.h"
#include "Particle.h"
#include "ParticleComposition.h"
#include "ParticleCoreShell.h"
#include "ParticleDistribution.h"
#include "ParticleLayout.h"
#include "PythonFormatting.h"
#include "RectangularDetector.h"
#include "ResolutionFunction2DGaussian.h"
#include "SampleLabelHandler.h"
#include "SphericalDetector.h"
#include "StringUtils.h"
#include "RegionOfInterest.h"
#include "BornAgainNamespace.h"
#include <iomanip>
#include <set>
#include <functional>

class IFormFactor;
class LayerRoughness;

using namespace PythonFormatting;

namespace {

    const std::string preamble =
        "import numpy\n"
        "import bornagain as ba\n"
        "from bornagain import deg, angstrom, nm, kvector_t\n\n";

    const std::string defineSimulate =
        "def run_simulation():\n"
        "    # Run Simulation\n"
        "    sample = getSample()\n"
        "    simulation = getSimulation()\n"
        "    simulation.setSample(sample)\n"
        "    simulation.runSimulation()\n"
        "    return simulation.getIntensityData()\n"
        "\n\n";

    const std::string mainProgram =
        "if __name__ == '__main__': \n"
        "    result = run_simulation()\n"
        "    ba.plot_intensity_data(result)\n";

    //! Returns a function that converts a coordinate to a Python code snippet with appropiate unit
    std::function<std::string(double)> printFunc(const IDetector2D* detector)
    {
        if (detector->getDefaultAxesUnits() == IDetector2D::MM)
            return PythonFormatting::printDouble;
        if (detector->getDefaultAxesUnits() == IDetector2D::RADIANS)
            return PythonFormatting::printDegrees;
        throw Exceptions::RuntimeErrorException(
            "ExportToPython::defineMasks() -> Error. Unknown detector units.");
    }

} // namespace

ExportToPython::ExportToPython(const MultiLayer& multilayer)
    : m_label(new SampleLabelHandler())
{
    for( auto x: multilayer.containedMaterials() )
        m_label->insertMaterial(x);
    for( auto x: multilayer.containedSubclass<Layer>() )
        m_label->insertLayer(x);
    for( auto x: multilayer.containedSubclass<LayerRoughness>() )
        m_label->insertRoughness(x);
    for( auto x: multilayer.containedSubclass<MultiLayer>() )
        m_label->insertMultiLayer(x);
    for( auto x: multilayer.containedSubclass<IFormFactor>() )
        m_label->insertFormFactor(x);
    for( auto x: multilayer.containedSubclass<IInterferenceFunction>() )
        m_label->insertInterferenceFunction(x);
    for( auto x: multilayer.containedSubclass<Particle>() )
        m_label->insertParticle(x);
    for( auto x: multilayer.containedSubclass<ParticleCoreShell>() )
        m_label->insertParticleCoreShell(x);
    for( auto x: multilayer.containedSubclass<ParticleComposition>() )
        m_label->insertParticleComposition(x);
    for( auto x: multilayer.containedSubclass<ParticleDistribution>() )
        m_label->insertParticleDistribution(x);
    for( auto x: multilayer.containedSubclass<ILayout>() )
        m_label->insertLayout(x);
    for( auto x: multilayer.containedSubclass<IRotation>() )
        m_label->insertRotation(x);
    if( multilayer.containedSubclass<MesoCrystal>().size() )
        throw Exceptions::NotImplementedException(
            "ExportToPython: class MesoCrystal not yet supported!");
}

ExportToPython::~ExportToPython()
{
    delete m_label;
}

//! Returns a Python script that sets up a simulation and runs it if invoked as main program.

std::string ExportToPython::simulationToPythonLowlevel(const GISASSimulation* simulation)
{
    return preamble
        + defineGetSample()
        + defineGetSimulation(simulation)
        + defineSimulate
        + mainProgram;
}

std::string ExportToPython::defineGetSimulation(const GISASSimulation* simulation) const
{
    std::ostringstream result;
    result << "def getSimulation():\n";
    //    result << indent() << "# Creating and returning GISAXS simulation\n";
    result << indent() << "simulation = ba.GISASSimulation()\n";
    result << defineDetector(simulation);
    result << defineDetectorResolutionFunction(simulation);
    result << defineBeam(simulation);
    result << defineParameterDistributions(simulation);
    result << defineMasks(simulation);
    result << defineSimulationOptions(simulation);
    result << indent() << "return simulation\n\n\n";
    return result.str();
}

std::string ExportToPython::defineGetSample() const
{
    return "def getSample():\n"
        + defineMaterials()
        + defineLayers()
        + defineFormFactors()
        + defineParticles()
        + defineCoreShellParticles()
        + defineParticleCompositions()
        + defineParticleDistributions()
        + defineInterferenceFunctions()
        + defineParticleLayouts()
        + defineRoughnesses()
        + addLayoutsToLayers()
        + defineMultiLayers()
        + "\n";
}

std::string ExportToPython::defineMaterials() const
{
    const auto themap = m_label->getMaterialMap();
    if (themap->size() == 0)
        return "# No Materials.\n\n";
    std::ostringstream result;
    result << std::setprecision(12);
    result << indent() << "# Defining Materials\n";
    std::set<std::string> visitedMaterials;
    for (auto it=themap->begin(); it!=themap->end(); ++it) {
        if (visitedMaterials.find(it->second) != visitedMaterials.end())
            continue;
        visitedMaterials.insert(it->second);
        const HomogeneousMaterial* p_material = it->first;
        complex_t ri = p_material->refractiveIndex();
        double delta = 1.0 - std::real(ri);
        double beta = std::imag(ri);
        if (p_material->isScalarMaterial()) {
            result << indent() << m_label->getLabelMaterial(p_material)
                   << " = ba.HomogeneousMaterial(\"" << p_material->getName()
                   << "\", " << printDouble(delta) << ", "
                   << printDouble(beta) << ")\n";
        } else {
            kvector_t magnetic_field = p_material->magneticField();
            result << indent() << "magnetic_field = kvector_t(" << magnetic_field.x() << ", "
                   << magnetic_field.y() << ", " << magnetic_field.z() << ", "
                   << ")\n";
            result << indent() << m_label->getLabelMaterial(p_material)
                   << " = ba.HomogeneousMaterial(\"" << p_material->getName();
            result << "\", " << printDouble(delta) << ", "
                   << printDouble(beta) << ", "
                   << "magnetic_field)\n";
        }
    }
    return result.str();
}

std::string ExportToPython::defineLayers() const
{
    const auto themap = m_label->getLayerMap();
    if (themap->size() == 0)
        return "# No Layers.\n\n";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Defining Layers\n";
    for (auto it=themap->begin(); it != themap->end(); ++it) {
        const Layer* layer = it->first;
        result << indent() << it->second << " = ba.Layer(" <<
            m_label->getLabelMaterial(layer->material());
        if (layer->thickness() != 0)
            result << ", " << layer->thickness();
        result << ")\n";
        if (layer->numberOfSlices()!=1)
            result << indent() << it->second << ".setNumberOfSlices("
                   << layer->numberOfSlices() << ")\n";
    }
    return result.str();
}

std::string ExportToPython::defineFormFactors() const
{
    const auto themap = m_label->getFormFactorMap();
    if (themap->size() == 0)
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Defining Form Factors\n";
    for (auto it=themap->begin(); it!=themap->end(); ++it) {
        const IFormFactor* p_ff = it->first;
        result << indent() << it->second << " = ba.FormFactor" << p_ff->getName() << "("
               << argumentList(p_ff) << ")\n";
    }
    return result.str();
}

std::string ExportToPython::defineParticles() const
{
    const auto themap = m_label->getParticleMap();
    if (themap->size() == 0)
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Defining Particles\n";
    for (auto it=themap->begin(); it!=themap->end(); ++it) {
        const Particle* p_particle = it->first;
        std::string particle_name = it->second;
        result << indent() << particle_name << " = ba.Particle("
               << m_label->getLabelMaterial(p_particle->material()) << ", "
               << m_label->getLabelFormFactor(p_particle->formFactor()) << ")\n";
        setRotationInformation(p_particle, particle_name, result);
        setPositionInformation(p_particle, particle_name, result);
    }
    return result.str();
}

std::string ExportToPython::defineCoreShellParticles() const
{
    const auto themap = m_label->getParticleCoreShellMap();
    if (themap->size() == 0)
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Defining Core Shell Particles\n";
    for (auto it=themap->begin(); it!=themap->end(); ++it) {
        const ParticleCoreShell* p_coreshell = it->first;
        result << "\n" << indent() << it->second << " = ba.ParticleCoreShell("
               << m_label->getLabelParticle(p_coreshell->shellParticle()) << ", "
               << m_label->getLabelParticle(p_coreshell->coreParticle()) << ")\n";
        std::string core_shell_name = it->second;
        setRotationInformation(p_coreshell, core_shell_name, result);
        setPositionInformation(p_coreshell, core_shell_name, result);
    }
    return result.str();
}

std::string ExportToPython::defineParticleDistributions() const
{
    const auto themap = m_label->getParticleDistributionsMap();
    if (themap->size() == 0)
        return "";

    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Defining particles with parameter following a distribution\n";

    int index(1);
    for (auto it=themap->begin(); it!=themap->end(); ++it) {
        ParameterDistribution par_distr = it->first->parameterDistribution();

        // building distribution functions
        std::stringstream s_distr;
        s_distr << "distr_" << index;
        result << indent() << s_distr.str() << " = "
               << representDistribution(par_distr) << "\n";

        // building parameter distribution
        std::stringstream s_par_distr;
        s_par_distr << "par_distr_" << index;

        result << indent() << s_par_distr.str() << " = ba.ParameterDistribution("
               << "\"" << par_distr.getMainParameterName() << "\""
               << ", " << s_distr.str() << ", " << par_distr.getNbrSamples() << ", "
               << printDouble(par_distr.getSigmaFactor()) << ")\n";

        // linked parameters
        std::vector<std::string> linked_pars = par_distr.getLinkedParameterNames();
        if(linked_pars.size()) {
            result << indent() << s_par_distr.str();
            for(size_t i=0; i<linked_pars.size(); ++i)
                result << ".linkParameter(\"" << linked_pars[i] << "\")";
            result << "\n";
        }

        result << indent() << it->second << " = ba.ParticleDistribution("
               << m_label->getLabelParticle(it->first->particle())
               << ", " << s_par_distr.str() << ")\n";
        index++;
    }
    return result.str();
}

std::string ExportToPython::defineParticleCompositions() const
{
    const auto themap = m_label->getParticleCompositionMap();
    if (themap->size() == 0)
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Defining composition of particles at specific positions\n";
    for (auto it=themap->begin(); it!=themap->end(); ++it) {
        const ParticleComposition* p_particle_composition = it->first;
        std::string particle_composition_name = it->second;
        result << indent() << particle_composition_name << " = ba.ParticleComposition()\n";
        for (size_t i = 0; i < p_particle_composition->nbrParticles(); ++i) {
            result << indent() << particle_composition_name << ".addParticle("
                   << m_label->getLabelParticle(p_particle_composition->particle(i))
            << ")\n";
        }
        setRotationInformation(p_particle_composition, particle_composition_name, result);
        setPositionInformation(p_particle_composition, particle_composition_name, result);
    }
    return result.str();
}

std::string ExportToPython::defineInterferenceFunctions() const
{
    const auto themap = m_label->getInterferenceFunctionMap();
    if (themap->size() == 0)
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Defining Interference Functions\n";
    for (auto it=themap->begin(); it!=themap->end(); ++it) {
        const IInterferenceFunction* interference = it->first;

        if (dynamic_cast<const InterferenceFunctionNone*>(interference))
            result << indent() << it->second << " = ba.InterferenceFunctionNone()\n";

        else if (const auto* oneDLattice
                 = dynamic_cast<const InterferenceFunction1DLattice*>(interference)) {
            const Lattice1DParameters latticeParameters = oneDLattice->getLatticeParameters();
            result << indent() << it->second << " = ba.InterferenceFunction1DLattice("
                   << printNm(latticeParameters.m_length) << ", "
                   << printDegrees(latticeParameters.m_xi) << ")\n";

            const IFTDecayFunction1D* pdf = oneDLattice->decayFunction();

            if (pdf->decayLength() != 0.0)
                result << indent() << it->second << "_pdf  = ba." << pdf->getName()
                       << "(" << argumentList(pdf) << ")\n"
                       << indent() << it->second << ".setDecayFunction(" << it->second << "_pdf)\n";
        }

        else if (const auto* oneDParaCrystal
                 = dynamic_cast<const InterferenceFunctionRadialParaCrystal*>(interference)) {
            result << indent() << it->second << " = ba.InterferenceFunctionRadialParaCrystal("
                   << printNm(oneDParaCrystal->peakDistance()) << ", "
                   << printNm(oneDParaCrystal->dampingLength()) << ")\n";

            if (oneDParaCrystal->kappa() != 0.0)
                result << indent() << it->second << ".setKappa("
                       << printDouble(oneDParaCrystal->kappa()) << ")\n";

            if (oneDParaCrystal->domainSize() != 0.0)
                result << indent() << it->second << ".setDomainSize("
                       << printDouble(oneDParaCrystal->domainSize()) << ")\n";

            const IFTDistribution1D* pdf = oneDParaCrystal->probabilityDistribution();

            if (pdf->omega() != 0.0)
                result << indent() << it->second << "_pdf  = ba." << pdf->getName()
                       << "(" << argumentList(pdf) << ")\n"
                       << indent() << it->second << ".setProbabilityDistribution(" << it->second
                       << "_pdf)\n";
        }

        else if (const auto* twoDLattice
                 = dynamic_cast<const InterferenceFunction2DLattice*>(interference)) {
            const Lattice2D& lattice = twoDLattice->lattice();
            result << indent() << it->second << " = ba.InterferenceFunction2DLattice("
                   << printNm(lattice.length1()) << ", "
                   << printNm(lattice.length2()) << ", "
                   << printDegrees(lattice.latticeAngle()) << ", "
                   << printDegrees(lattice.rotationAngle()) << ")\n";

            const IFTDecayFunction2D* pdf = twoDLattice->decayFunction();

            result << indent() << it->second << "_pdf  = ba." << pdf->getName()
                   << "(" << argumentList(pdf) << ")\n"
                   << indent() << it->second << ".setDecayFunction(" << it->second << "_pdf)\n";
        }

        else if (const auto* twoDParaCrystal
                 = dynamic_cast<const InterferenceFunction2DParaCrystal*>(interference)) {
            std::vector<double> domainSize = twoDParaCrystal->domainSizes();
            const Lattice2D& lattice = twoDParaCrystal->lattice();

            if(lattice.getName() == BornAgain::SquareLatticeType) {
                result << indent() << it->second
                       << " = ba.InterferenceFunction2DParaCrystal.createSquare("
                       << printNm(lattice.length1())
                       << ", "
                       << printNm(twoDParaCrystal->dampingLength()) << ", "
                       << printNm(domainSize[0]) << ", "
                       << printNm(domainSize[1]) << ")\n";

            }

            else if(lattice.getName() == BornAgain::HexagonalLatticeType) {
                result << indent() << it->second
                       << " = ba.InterferenceFunction2DParaCrystal.createHexagonal("
                       << printNm(lattice.length1())
                       << ", "
                       << printNm(twoDParaCrystal->dampingLength()) << ", "
                       << printNm(domainSize[0]) << ", "
                       << printNm(domainSize[1]) << ")\n";

            }

            else {
                result << indent() << it->second << " = ba.InterferenceFunction2DParaCrystal("
                       << printNm(lattice.length1())
                       << ", "
                       << printNm(lattice.length2())
                       << ", "
                       << printDegrees(lattice.latticeAngle())
                       << ", "
                       << printDegrees(lattice.rotationAngle())
                       << ", "
                       << printNm(twoDParaCrystal->dampingLength()) << ")\n";

                if (domainSize[0] != 0 || domainSize[1] != 0)
                    result << indent() << it->second << ".setDomainSizes("
                           << printNm(domainSize[0]) << ", "
                           << printNm(domainSize[1]) << ")\n";

                if (twoDParaCrystal->integrationOverXi() == true)
                    result << indent() << it->second << ".setIntegrationOverXi(True)\n";
            }

            std::vector<const IFTDistribution2D*> pdf_vector
                = twoDParaCrystal->probabilityDistributions();
            const IFTDistribution2D* pdf = pdf_vector[0];

            result << indent() << it->second << "_pdf_1  = ba." << pdf->getName()
                   << "(" << argumentList(pdf) << ")\n";

            pdf = pdf_vector[1];

            result << indent() << it->second << "_pdf_2  = ba." << pdf->getName()
                   << "(" << argumentList(pdf) << ")\n";

            result << indent() << it->second << ".setProbabilityDistributions(" << it->second
                   << "_pdf_1, " << it->second << "_pdf_2)\n";
        }

        else
            throw Exceptions::NotImplementedException(
                "Bug: ExportToPython::defineInterferenceFunctions() called with unexpected "
                "IInterferenceFunction " + interference->getName());
    }
    return result.str();
}

std::string ExportToPython::defineParticleLayouts() const
{
    const auto themap = m_label->getParticleLayoutMap();
    if (themap->size() == 0)
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Defining Particle Layouts and adding Particles\n";
    for (auto it=themap->begin(); it!=themap->end(); ++it) {
        const ILayout* iLayout = it->first;
        if (const ParticleLayout* particleLayout = dynamic_cast<const ParticleLayout*>(iLayout)) {
            result << indent() << it->second << " = ba.ParticleLayout()\n";
            size_t numberOfParticles = particleLayout->numberOfParticles();
            size_t particleIndex = 0;

            while (particleIndex != numberOfParticles) {
                const IAbstractParticle* p_particle = particleLayout->particle(particleIndex);
                double abundance = particleLayout->abundanceOfParticle(particleIndex);
                result << indent() << it->second << ".addParticle("
                       << m_label->getLabelParticle(p_particle) << ", "
                       << printDouble(abundance) << ")\n";
                particleIndex++;
            }

            if( const IInterferenceFunction* p_iff = particleLayout->interferenceFunction() )
                result << indent() << it->second << ".setInterferenceFunction("
                       << m_label->getLabelInterferenceFunction(p_iff) << ")\n";

            switch (particleLayout->getApproximation()) {
            case ILayout::DA:
                break;
            case ILayout::SSCA:
                result << indent() << it->second << ".setApproximation(ba.ILayout.SSCA)\n";
                break;
            }
            result << indent() << it->second << ".setTotalParticleSurfaceDensity("
                   << it->first->totalParticleSurfaceDensity() << ")\n";
        }
    }
    return result.str();
}

std::string ExportToPython::defineRoughnesses() const
{
    const auto themap = m_label->getLayerRoughnessMap();
    if (themap->size() == 0)
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Defining Roughness Parameters\n";
    for (auto it=themap->begin(); it!=themap->end(); ++it)
        result << indent() << it->second << " = ba.LayerRoughness("
               <<  argumentList(it->first) << ")\n";
    return result.str();
}

std::string ExportToPython::addLayoutsToLayers() const
{
    if (m_label->getParticleLayoutMap()->size() == 0)
        return "";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Adding layouts to layers";
    const auto layermap = m_label->getLayerMap();
    for (auto it=layermap->begin(); it!=layermap->end(); ++it) {
        const Layer* layer = it->first;
        for (auto p_layout : layer->layouts())
            result << "\n" << indent() << it->second << ".addLayout("
                   << m_label->getLabelLayout(p_layout) << ")\n";
    }
    return result.str();
}

std::string ExportToPython::defineMultiLayers() const
{
    const auto themap = m_label->getMultiLayerMap();
    if (themap->size() == 0)
        return "# No MultiLayers.\n\n";
    std::ostringstream result;
    result << std::setprecision(12);
    result << "\n" << indent() << "# Defining Multilayers\n";
    for (auto it=themap->begin(); it!=themap->end(); ++it) {
        result << indent() << it->second << " = ba.MultiLayer()\n";
        double ccl = it->first->crossCorrLength();
        if (ccl > 0.0)
            result << indent() << it->second << ".setCrossCorrLength(" << ccl << ")\n";

        size_t numberOfLayers = it->first->numberOfLayers();

        if (numberOfLayers) {
            result << indent() << it->second << ".addLayer("
                   << m_label->getLabelLayer(it->first->layer(0)) << ")\n";

            size_t layerIndex = 1;
            while (layerIndex != numberOfLayers) {
                const LayerInterface* layerInterface = it->first->layerInterface(layerIndex - 1);
                if (m_label->getLayerRoughnessMap()->find(layerInterface->getRoughness())
                    == m_label->getLayerRoughnessMap()->end())
                    result << indent() << it->second << ".addLayer("
                           << m_label->getLabelLayer(it->first->layer(layerIndex)) << ")\n";
                else
                    result << indent() << it->second << ".addLayerWithTopRoughness("
                           << m_label->getLabelLayer(it->first->layer(layerIndex)) << ", "
                           << m_label->getLabelRoughness(layerInterface->getRoughness()) << ")\n";
                layerIndex++;
            }
        }
        result << indent() << "return " << it->second << "\n";
    }
    return result.str();
}

std::string ExportToPython::defineDetector(const GISASSimulation* simulation) const
{
    const IDetector2D* iDetector = simulation->getInstrument().getDetector();

    if (iDetector->getDimension() != 2)
        throw Exceptions::RuntimeErrorException("ExportToPython::defineDetector: "
                                                "detector must be two-dimensional for GISAS");

    std::ostringstream result;
    result << std::setprecision(12);

    if(auto detector = dynamic_cast<const SphericalDetector*>(iDetector)) {
        result << indent() << "simulation.setDetectorParameters(";
        for(size_t index=0; index<detector->getDimension(); ++index) {
            if (index != 0) result << ", ";
            result << detector->getAxis(index).size() << ", "
                   << printDegrees(detector->getAxis(index).getMin()) << ", "
                   << printDegrees(detector->getAxis(index).getMax());
        }
        result << ")\n";

    } else if(auto detector = dynamic_cast<const RectangularDetector*>(iDetector)) {
        result << indent() << "\n";
        result << indent() << "detector = ba.RectangularDetector("
               << detector->getNbinsX() << ", "
               << printDouble(detector->getWidth()) << ", "
               << detector->getNbinsY() << ", "
               << printDouble(detector->getHeight()) << ")\n";
        if(detector->getDetectorArrangment() == RectangularDetector::GENERIC) {
            result << indent() << "detector.setPosition("
                   << printKvector(detector->getNormalVector()) << ", "
                   << printDouble(detector->getU0()) << ", "
                   << printDouble(detector->getV0());
            if(!isDefaultDirection(detector->getDirectionVector()))
                result << ", " << printKvector(detector->getDirectionVector());
            result << ")\n";

        } else if (detector->getDetectorArrangment()
                   == RectangularDetector::PERPENDICULAR_TO_SAMPLE) {
            result << indent() << "detector.setPerpendicularToSampleX("
                   << printDouble(detector->getDistance()) << ", "
                   << printDouble(detector->getU0()) << ", "
                   << printDouble(detector->getV0()) << ")\n";

        } else if (detector->getDetectorArrangment()
                   == RectangularDetector::PERPENDICULAR_TO_DIRECT_BEAM) {
            result << indent() << "detector.setPerpendicularToDirectBeam("
                   << printDouble(detector->getDistance()) << ", "
                   << printDouble(detector->getU0()) << ", "
                   << printDouble(detector->getV0()) << ")\n";

        } else if (detector->getDetectorArrangment()
                   == RectangularDetector::PERPENDICULAR_TO_REFLECTED_BEAM) {
            result << indent() << "detector.setPerpendicularToReflectedBeam("
                   << printDouble(detector->getDistance()) << ", "
                   << printDouble(detector->getU0()) << ", "
                   << printDouble(detector->getV0()) << ")\n";


        } else if (detector->getDetectorArrangment()
                   == RectangularDetector::PERPENDICULAR_TO_REFLECTED_BEAM_DPOS) {
            result << indent() << "detector.setPerpendicularToReflectedBeam("
                   << printDouble(detector->getDistance()) << ")\n";
            result << indent() << "detector.setDirectBeamPosition("
                   << printDouble(detector->getDirectBeamU0()) << ", "
                   << printDouble(detector->getDirectBeamV0()) << ")\n";

        } else
            throw Exceptions::RuntimeErrorException(
                "ExportToPython::defineDetector: unknown alignment");

        result << indent() << "simulation.setDetector(detector)\n";

    } else
        throw Exceptions::RuntimeErrorException("ExportToPython::defineDetector: unknown detector");

    if(iDetector->regionOfInterest()) {
        result << indent() << "simulation.setRegionOfInterest("
               << printFunc(iDetector)(iDetector->regionOfInterest()->getXlow()) << ", "
               << printFunc(iDetector)(iDetector->regionOfInterest()->getYlow()) << ", "
               << printFunc(iDetector)(iDetector->regionOfInterest()->getXup()) << ", "
               << printFunc(iDetector)(iDetector->regionOfInterest()->getYup()) << ")\n";
    }
    result << indent() << "\n";

    return result.str();
}

std::string ExportToPython::defineDetectorResolutionFunction(
    const GISASSimulation* simulation) const
{
    std::ostringstream result;
    const IDetector2D* detector = simulation->getInstrument().getDetector();

    if (const IDetectorResolution* p_resfunc = detector->detectorResolution()) {
        if ( auto* p_convfunc = dynamic_cast<const ConvolutionDetectorResolution*>(p_resfunc)) {
            if (auto* resfunc = dynamic_cast<const ResolutionFunction2DGaussian*>(
                    p_convfunc->getResolutionFunction2D())) {
                result << indent() << "simulation.setDetectorResolutionFunction(";
                result << "ba.ResolutionFunction2DGaussian(";
                result << printFunc(detector)(resfunc->getSigmaX()) << ", ";
                result << printFunc(detector)(resfunc->getSigmaY()) << "))\n";
            } else
                throw Exceptions::RuntimeErrorException(
                    "ExportToPython::defineDetectorResolutionFunction() -> Error. "
                    "Unknown detector resolution function");
        } else
            throw Exceptions::RuntimeErrorException(
                "ExportToPython::defineDetectorResolutionFunction() -> Error. "
                "Not a ConvolutionDetectorResolution function");
    }

    return result.str();
}

std::string ExportToPython::defineBeam(const GISASSimulation* simulation) const
{
    std::ostringstream result;
    result << std::setprecision(12);
    // result << indent() << "# Defining Beam Parameters\n";
    const Beam& beam = simulation->getInstrument().getBeam();
    result << indent() << "simulation.setBeamParameters("
           << printNm(beam.getWavelength()) << ", "
           << printDegrees(beam.getAlpha()) << ", "
           << printDegrees(beam.getPhi()) << ")\n";
    double beam_intensity = beam.getIntensity();
    if(beam_intensity > 0.0)
        result << indent() << "simulation.setBeamIntensity("
               << printScientificDouble(beam_intensity) << ")\n";
    return result.str();
}

std::string ExportToPython::defineParameterDistributions(const GISASSimulation* simulation) const
{
    std::ostringstream result;
    const std::vector<ParameterDistribution>& distributions =
            simulation->getDistributionHandler().getDistributions();
    if (distributions.size()==0) return "";
    for (size_t i=0; i<distributions.size(); ++i) {
        std::string main_par_name = distributions[i].getMainParameterName();
        size_t nbr_samples = distributions[i].getNbrSamples();
        double sigma_factor = distributions[i].getSigmaFactor();

        std::stringstream s_distr;
        s_distr << "distr_" << (i+1);
        result << indent() << s_distr.str() << " = "
               << representDistribution(distributions[i]) << "\n";

        result << indent() << "simulation.addParameterDistribution(\"" << main_par_name << "\", "
               << s_distr.str() << ", " << nbr_samples << ", "
               << printDouble(sigma_factor) << ")\n";
    }
    return result.str();
}

std::string ExportToPython::defineMasks(const GISASSimulation* simulation) const
{
    std::ostringstream result;
    result << std::setprecision(12);

    const IDetector2D* detector = simulation->getInstrument().getDetector();
    const DetectorMask* detectorMask = detector->getDetectorMask();
    if(detectorMask && detectorMask->numberOfMasks()) {
        result << "\n";
        for(size_t i_mask=0; i_mask<detectorMask->numberOfMasks(); ++i_mask) {
            bool mask_value(false);
            const IShape2D* shape = detectorMask->getMaskShape(i_mask, mask_value);
            result << representShape2D(indent(), shape, mask_value, printFunc(detector));
        }
        result << "\n";
    }

    return result.str();
}

std::string ExportToPython::defineSimulationOptions(const GISASSimulation* simulation) const
{
    std::ostringstream result;
    result << std::setprecision(12);

    const SimulationOptions& options = simulation->getOptions();
    if (options.getHardwareConcurrency() != options.getNumberOfThreads())
        result << indent() << "simulation.getOptions().setNumberOfThreads("
               << options.getNumberOfThreads() << ")\n";
    if (options.isIntegrate())
        result << indent() << "simulation.getOptions().setMonteCarloIntegration(True, "
               << options.getMcPoints() << ")\n";
    if (options.useAvgMaterials())
        result << indent() << "simulation.getOptions().setUseAvgMaterials(True)\n";
    if (options.includeSpecular())
        result << indent() << "simulation.getOptions().setIncludeSpecular(True)\n";
    return result.str();
}

std::string ExportToPython::indent() const
{
    return "    ";
}

void ExportToPython::setRotationInformation(
    const IParticle* p_particle, std::string name, std::ostringstream& result) const
{
    if (p_particle->rotation()) {
        switch (p_particle->rotation()->getTransform3D().getRotationType()) {
        case Transform3D::EULER:
        {
            double alpha, beta, gamma;
            p_particle->rotation()->getTransform3D().calculateEulerAngles(&alpha, &beta, &gamma);
            result << indent() << name << "_rotation = ba.RotationEuler("
                   << printDegrees(alpha) << ", " << printDegrees(beta)
                   << ", " << printDegrees(gamma) << ")\n";
            break;
        }
        case Transform3D::XAXIS:
        {
            double alpha = p_particle->rotation()->getTransform3D().calculateRotateXAngle();
            result << indent() << name << "_rotation = ba.RotationX("
                   << printDegrees(alpha) << ")\n";
            break;
        }
        case Transform3D::YAXIS:
        {
            double alpha = p_particle->rotation()->getTransform3D().calculateRotateYAngle();
            result << indent() << name << "_rotation = ba.RotationY("
                   << printDegrees(alpha) << ")\n";
            break;
        }
        case Transform3D::ZAXIS:
        {
            double alpha = p_particle->rotation()->getTransform3D().calculateRotateZAngle();
            result << indent() << name << "_rotation = ba.RotationZ("
                   << printDegrees(alpha) << ")\n";
            break;
        }
        }
        result << indent() << name << ".setRotation(" << name << "_rotation)\n";
    }
}

void ExportToPython::setPositionInformation(
    const IParticle* p_particle, std::string name, std::ostringstream& result) const
{
    kvector_t pos = p_particle->position();
    bool has_position_info = (pos != kvector_t());

    if (has_position_info) {
        result << indent() << name
               << "_position = kvector_t("
               << printNm(pos.x()) << ", "
               << printNm(pos.y()) << ", "
               << printNm(pos.z()) << ")\n";

        result << indent()
               << name << ".setPosition("
               << name << "_position)\n";
    }
}
