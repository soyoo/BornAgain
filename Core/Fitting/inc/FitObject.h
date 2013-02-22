#ifndef FITOBJECT_H
#define FITOBJECT_H
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   FitObject.h
//! @brief  Definition of FitObject class
//! @author Scientific Computing Group at FRM II
//! @date   21.11.2012

#include "IParameterized.h"
#include "Simulation.h"
#include "OutputData.h"
#include "ChiSquaredModule.h"


//- -------------------------------------------------------------------
//! @class FitObject
//! @brief Class to hold single simulation description, real data and chi2 module
//! Used by FitSuite
//- -------------------------------------------------------------------
class FitObject : public IParameterized
{
public:
    FitObject(const Simulation &simulation, const OutputData<double > &real_data, const IChiSquaredModule &chi2_module=ChiSquaredModule(), double weight = 1.0);
    ~FitObject();

    //! get simulation
    const Simulation *getSimulation() const { return m_simulation; }
    Simulation *getSimulation() { return m_simulation; }
    //! set simulation
    void setSimulation(const Simulation &simulation) { delete m_simulation; m_simulation = simulation.clone(); }

    //! get real data
    const OutputData<double > *getRealData() const { return m_real_data; }
    //! set real data
    void setRealData(const OutputData<double > &real_data);

    //! get simulated data
    const OutputData<double > *getSimulationData() const { return m_simulation->getOutputData(); }

    //! get chi2 module
    const IChiSquaredModule *getChiSquaredModule() const {return m_chi2_module; }
    IChiSquaredModule *getChiSquaredModule() {return m_chi2_module; }
    //! set chi2 module
    void setChiSquaredModule(const IChiSquaredModule &chi2_module) { delete m_chi2_module; m_chi2_module = chi2_module.clone(); }

    //! calculate chi squared value
    double calculateChiSquared();

    //! add parameters from local pool to external pool and call recursion over direct children
    virtual std::string addParametersToExternalPool(std::string path, ParameterPool *external_pool, int copy_number=-1) const;

    //! return weight of data set in chi2 calculations
    double getWeight() const { return m_weight; }

    //! return size of data
    size_t getSizeOfData() const { return m_real_data->getAllocatedSize(); }

protected:
    //! initialize pool parameters, i.e. register some of class members for later access via parameter pool
    virtual void init_parameters();

private:
    FitObject(const FitObject &);
    FitObject &operator=(const FitObject &);

    Simulation *m_simulation; //! external simulation (not owned by this)
    OutputData<double > *m_real_data; //! real data
    IChiSquaredModule *m_chi2_module; //! chi2 module
    double m_weight; //! weight of data set in chi2 calculations

};

#endif // FITOBJECT_H