#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include "datatypes.h"
#include <vector>

class Distribution
{
	friend class GaussianGenerator;
	friend class ExponentialGenerator;
	friend class GammaGenerator;
	friend class TriangularGenerator;
	friend class SimpsonGenerator;

public:
	BigReal getExpectedValue() const;
	BigReal getDispersion() const;
	BigReal getStandardDeviation() const;
	BigReal getMinimumValue() const;
	BigReal getMaximumValue() const;
	BigInt getPeriodLength() const;
	BigInt getAperiodicitySectionLength() const;
	BigInt countInRange(BigReal rangeStart, BigReal rangeEnd) const;
protected:
	std::vector<BigReal> sample;
};

#endif // DISTRIBUTION_H
