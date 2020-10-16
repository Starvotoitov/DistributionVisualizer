#include "exponentialgenerator.h"
#include <stdexcept>
#include <cmath>

ExponentialGenerator::ExponentialGenerator(BigReal intensity):
	intensity(intensity),
	lehmerGenerator(0, 1)
{
}

void ExponentialGenerator::setIntensity(BigReal intensity)
{
	this->intensity = intensity;
}

const Distribution& ExponentialGenerator::getSample() const
{
	return sample;
}

void ExponentialGenerator::generateSample(int sampleSize)
{
	if (sampleSize < 0)
	{
		throw std::invalid_argument("");
	}

	if (sampleSize == 0)
	{

	}
	else
	{
		lehmerGenerator.generateSample(sampleSize);
		auto lehmerSampleIterator = lehmerGenerator.getSample().sample.begin();
		for (int i = 0; i < sampleSize; ++i)
		{
			BigReal newSampleValue = -1 / intensity * std::log(*lehmerSampleIterator);
			sample.sample.push_back(newSampleValue);
			lehmerSampleIterator++;
		}
	}
}
