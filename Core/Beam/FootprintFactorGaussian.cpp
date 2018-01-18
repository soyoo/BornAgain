#include "FootprintFactorGaussian.h"
#include "MathConstants.h"
#include "MathFunctions.h"

FootprintFactorGaussian::FootprintFactorGaussian(double width_ratio) : IFootprintFactor(width_ratio)
{
    initialize();
}

FootprintFactorGaussian* FootprintFactorGaussian::clone() const
{
    return new FootprintFactorGaussian(*this);
}

double FootprintFactorGaussian::calculate(double alpha) const
{
    if (alpha > M_PI || alpha < 0.0)
        throw std::runtime_error("Error in FootprintFactorGaussian::calculate: "
                                 "incident angle is out of range");
    if (widthRatio() == 0.0)
        return 1.0;
    const double arg = std::sin(alpha) * M_SQRT1_2 / widthRatio();
    return MathFunctions::erf(arg);
}

FootprintFactorGaussian::FootprintFactorGaussian(const FootprintFactorGaussian& other)
    : IFootprintFactor(other)
{
    initialize();
}

void FootprintFactorGaussian::initialize()
{
    setName(BornAgain::GaussianFootprintFactorType);
}

static_assert(!std::is_copy_constructible<FootprintFactorGaussian>::value,
              "FootprintFactorGaussian should not be copy constructable");
static_assert(!std::is_copy_assignable<FootprintFactorGaussian>::value,
              "FootprintFactorGaussian should not be copy assignable");
