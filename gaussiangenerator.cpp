#include "gaussiangenerator.h"
#include <stdexcept>
#include <cmath>

GaussianGenerator::GaussianGenerator(int summableValuesCount):
	expectedValue(DEFAULT_EXPECTED_VALUE),
	standardDeviation(DEFAULT_STANDARD_DEVIATION),
	summableValuesCount(summableValuesCount),
	lehmerGenerator(0, 1)
{
}

GaussianGenerator::GaussianGenerator(BigReal expectedValue, BigReal standardDeviation, int summableValuesCount):
	expectedValue(expectedValue),
	standardDeviation(standardDeviation),
	summableValuesCount(summableValuesCount),
	lehmerGenerator(0, 1)
{
}

void GaussianGenerator::setExpectedValue(BigReal expectedValue)
{
	this->expectedValue = expectedValue;
}

void GaussianGenerator::setStandardDeviation(BigReal standardDeviation)
{
	this->standardDeviation = standardDeviation;
}

const Distribution& GaussianGenerator::getSample() const
{
	return sample;
}

void GaussianGenerator::generateSample(int sampleSize)
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
		lehmerGenerator.generateSample(sampleSize * summableValuesCount);
		auto lehmerSampleIterator = lehmerGenerator.getSample().sample.begin();
		for (int i = 0; i < sampleSize; ++i)
		{
			BigReal sum = 0;
			for (int j = 0; j < summableValuesCount; ++j)
			{
				sum += *lehmerSampleIterator;
				lehmerSampleIterator++;
			}
			BigReal newSampleValue = expectedValue + standardDeviation * std::sqrt(12 / summableValuesCount) *
					(sum - summableValuesCount / 2);
			sample.sample.push_back(newSampleValue);
		}
	}
}
