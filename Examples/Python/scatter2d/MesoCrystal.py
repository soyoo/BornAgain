"""
Cylindrical mesocrystal on a substrate
"""
import numpy, sys
import bornagain as ba
from bornagain import angstrom, deg, micrometer, nm, nm2, kvector_t


def get_sample():
    """
    Returns a sample with a cylindrically shaped mesocrystal on a substrate.
    """

    # Define materials
    material_Particle = ba.HomogeneousMaterial("Particle", 0.0006, 2e-08)
    material_Substrate = ba.HomogeneousMaterial("Substrate", 6e-06, 2e-08)
    material_Vacuum = ba.HomogeneousMaterial("Vacuum", 0.0, 0.0)

    # Define form factors
    ff_1 = ba.FormFactorFullSphere(2.0*nm)
    ff_2 = ba.FormFactorCylinder(20.0*nm, 50.0*nm)

    # Define particles
    particle_1 = ba.Particle(material_Particle, ff_1)

    # Define 3D lattices
    lattice = ba.Lattice3D(ba.kvector_t(5.0*nm, 0.0*nm, 0.0*nm),
                           ba.kvector_t(0.0*nm, 5.0*nm, 0.0*nm),
                           ba.kvector_t(0.0*nm, 0.0*nm, 5.0*nm))

    # Define crystals
    crystal = ba.Crystal(particle_1, lattice)

    # Define mesocrystals
    particle_2 = ba.MesoCrystal(crystal, ff_2)

    # Define particle layouts
    layout = ba.ParticleLayout()
    layout.addParticle(particle_2, 1.0)
    layout.setWeight(1)
    layout.setTotalParticleSurfaceDensity(0.01)

    # Define layers
    layer_1 = ba.Layer(material_Vacuum)
    layer_1.addLayout(layout)
    layer_2 = ba.Layer(material_Substrate)

    # Define sample
    sample = ba.MultiLayer()
    sample.addLayer(layer_1)
    sample.addLayer(layer_2)

    return sample


def get_simulation():
    beam = ba.Beam(1.0, 0.1*nm, ba.Direction(0.2*deg, 0.0*deg))
    nx = 200
    ny = 200
    detector = ba.SphericalDetector(nx, -2.0*deg, 2.0*deg, ny, 0.0*deg, 2.0*deg)

    simulation = ba.GISASSimulation(beam, get_sample(), detector)
    return simulation


def run_simulation():
    simulation = get_simulation()
    simulation.runSimulation()
    return simulation.result()


if __name__ == '__main__':
    result = run_simulation()
    ba.plot_simulation_result(result, cmap='jet', aspect='auto')