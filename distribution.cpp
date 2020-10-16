#include "distribution.h"
#include <cmath>
#include <algorithm>

BigReal Distribution::getExpectedValue() const
{
	BigReal sum = 0.0;
	for (auto currentValue : sample)
	{
		sum += (currentValue / sample.size());
	}
	return sum;
}

BigReal Distribution::getDispersion() const
{
	BigReal expectedValue = getExpectedValue();
	BigReal sum = 0;
	for (auto currentValue : sample)
	{
		sum += std::pow(currentValue - expectedValue, 2);
	}
	return sum / sample.size();
}

BigReal Distribution::getStandardDeviation() const
{
	return std::sqrt(getDispersion());
}

BigReal Distribution::getMinimumValue() const
{
	return *std::min_element(sample.begin(), sample.end());
}

BigReal Distribution::getMaximumValue() const
{
	return *std::max_element(sample.begin(), sample.end());
}

BigInt Distribution::getPeriodLength() const
{
	BigInt periodLenght = 0;
	bool wasFound = false;
	auto currentValue = sample.begin();
	while (currentValue != sample.end() && !wasFound)
	{
		auto prevValue = std::find(sample.begin(), currentValue, *currentValue);
		if (prevValue != currentValue)
		{
			wasFound = true;
			periodLenght = std::distance(prevValue, currentValue);
		}
		currentValue++;
	}

	if (wasFound)
	{
		return periodLenght;
	}
	else
	{
		return sample.size();
	}
}

BigInt Distribution::getAperiodicitySectionLength() const
{
	BigInt aperiodicitySection = 0;
	bool wasFound = false;
	auto currentValue = sample.begin();
	while (currentValue != sample.end() && !wasFound)
	{
		auto prevValue = std::find(sample.begin(), currentValue, *currentValue);
		if (prevValue != currentValue)
		{
			wasFound = true;
			aperiodicitySection = std::distance(sample.begin(), currentValue);
		}
		currentValue++;
	}

	if (wasFound)
	{
		return aperiodicitySection;
	}
	else
	{
		return sample.size();
	}
}

BigInt Distribution::countInRange(double rangeStart, double rangeEnd) const
{
	return std::count_if(sample.begin(), sample.end(), [rangeStart, rangeEnd](auto currentValue){
		return currentValue < rangeEnd && currentValue >= rangeStart;
	});
}
