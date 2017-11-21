// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Instrument/IDetector2D.h
//! @brief     Defines interface IDetector2D.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef IDETECTOR2D_H
#define IDETECTOR2D_H

#include "IDetector.h"
#include "Beam.h"
#include "DetectorMask.h"
#include <memory>

class IPixel;
class IShape2D;

//! Abstract 2D detector interface.
//! @ingroup simulation

class BA_CORE_API_ IDetector2D : public IDetector
{
public:

    IDetector2D();

    virtual IDetector2D* clone() const =0;

    virtual ~IDetector2D();

    //! Inits detector with the beam settings
    virtual void init(const Beam&) {}

    //! Sets detector parameters using angle ranges
    void setDetectorParameters(size_t n_x, double x_min, double x_max,
                               size_t n_y, double y_min, double y_max);

    //! Sets detector parameters using axes
    void setDetectorAxes(const IAxis& axis0, const IAxis& axis1);

    //! Removes all masks from the detector
    void removeMasks();

    //! Adds mask of given shape to the stack of detector masks. The mask value 'true' means
    //! that the channel will be excluded from the simulation. The mask which is added last
    //! has priority.
    //! @param shape The shape of mask (Rectangle, Polygon, Line, Ellipse)
    //! @param mask_value The value of mask
    void addMask(const IShape2D& shape, bool mask_value = true);

    //! Put the mask for all detector channels (i.e. exclude whole detector from the analysis)
    void maskAll();

    const DetectorMask* detectorMask() const;

    size_t numberOfMaskedChannels() const;

    bool isMasked(size_t index) const;

    //! return true if has masks
    bool hasMasks() const;

#ifndef SWIG
    //! Create a vector of SimulationElement objects according to the detector and its mask
    std::vector<SimulationElement> createSimulationElements(const Beam& beam);

    //! Creates single simulation element.
    SimulationElement getSimulationElement(size_t index, const Beam& beam) const;
#endif

    //! Returns region of  interest if exists.
    virtual const RegionOfInterest* regionOfInterest() const override;

    //! Sets rectangular region of interest with lower left and upper right corners defined.
    void setRegionOfInterest(double xlow, double ylow, double xup, double yup);

    //! Resets region of interest making whole detector plane available for the simulation.
    void resetRegionOfInterest();

    //! Returns number of simulation elements.
    size_t numberOfSimulationElements() const;

protected:
    IDetector2D(const IDetector2D& other);

    //! Create an IPixel for the given OutputData object and index
    virtual IPixel* createPixel(size_t index) const=0;

    //! Calculates axis range from original detector axes in given units (mm, rad, etc)
    virtual void calculateAxisRange(size_t axis_index, const Beam& beam, AxesUnits units,
                                    double &amin, double &amax) const override;

    //! Calculate global index from two axis indices
    size_t getGlobalIndex(size_t x, size_t y) const;

    //! Returns index of pixel that contains the specular wavevector.
    //! If no pixel contains this specular wavevector, the number of pixels is
    //! returned. This corresponds to an overflow index.
    virtual size_t getIndexOfSpecular(const Beam& beam) const=0;

    DetectorMask m_detector_mask;

private:
    virtual void
    setDataToDetectorMap(OutputData<double>& detectorMap,
                         const std::vector<SimulationElement>& elements) const override;

    std::unique_ptr<RegionOfInterest> m_region_of_interest;
};

#endif // IDETECTOR2D_H
