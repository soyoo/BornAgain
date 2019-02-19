// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/RealSpaceWidgets/IPositionBuilder.h
//! @brief     Declares interface IPositionBuilder and subclasses
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef IPOSITIONBUILDER_H
#define IPOSITIONBUILDER_H

#include <vector>

class InterferenceFunction1DLattice;
class InterferenceFunction2DLattice;

class IPositionBuilder
{
public:
    virtual ~IPositionBuilder();

    virtual std::vector<std::vector<double>> generatePositions(double layer_size,
                                                               double density = 0.0) const = 0;
};

class RandomPositionBuilder : public IPositionBuilder
{
public:
    RandomPositionBuilder();
    ~RandomPositionBuilder() override;

    std::vector<std::vector<double>> generatePositions(double layer_size,
                                                       double density = 0.0) const override;
};

class Lattice1DPositionBuilder : public IPositionBuilder
{
public:
    Lattice1DPositionBuilder(const InterferenceFunction1DLattice* p_iff);
    ~Lattice1DPositionBuilder() override;

    std::vector<std::vector<double>> generatePositions(double layer_size,
                                                       double density = 0.0) const override;
private:
    const InterferenceFunction1DLattice* mp_iff;
};

class Lattice2DPositionBuilder : public IPositionBuilder
{
public:
    Lattice2DPositionBuilder(const InterferenceFunction2DLattice* p_iff);
    ~Lattice2DPositionBuilder() override;

    std::vector<std::vector<double>> generatePositions(double layer_size,
                                                       double density = 0.0) const override;
private:
    const InterferenceFunction2DLattice* mp_iff;
};

#endif // IPOSITIONBUILDER_H
