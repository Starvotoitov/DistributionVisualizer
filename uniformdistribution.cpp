#include "uniformdistribution.h"
#include <cmath>

BigReal UniformDistribution::getInderectSigns() const
{
	BigReal pairsCount = 0.0;
	auto currentValue = sample.begin();
	while (currentValue != sample.end())
	{
		auto nextValue = std::next(currentValue);
		if (nextValue != sample.end())
		{
			if (std::pow(*currentValue, 2) + std::pow(*nextValue, 2) < 1)
			{
				++pairsCount;
			}
			currentValue = ++nextValue;
		}
		else
		{
			currentValue = nextValue;
		}
	}
	return 2 * pairsCount / sample.size();
}
