#include "gammagenerator.h"
#include <stdexcept>
#include <cmath>

GammaGenerator::GammaGenerator():
	eta(DEFAULT_ETA),
	lambda(DEFAULT_LAMBDA),
	lehmerGenerator(0, 1)
{
}

GammaGenerator::GammaGenerator(BigReal eta, BigReal lambda):
	eta(eta),
	lambda(lambda),
	lehmerGenerator(0, 1)
{
}

void GammaGenerator::setEta(BigReal eta)
{
	this->eta = eta;
}

void GammaGenerator::setLambda(BigReal lambda)
{
	this->lambda = lambda;
}

const Distribution& GammaGenerator::getSample() const
{
	return sample;
}

void GammaGenerator::generateSample(int sampleSize)
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
		lehmerGenerator.generateSample(sampleSize * (eta >= 1 ? eta : 1));
		auto lehmerSampleIterator = lehmerGenerator.getSample().sample.begin();
		for (int i = 0; i < sampleSize; ++i)
		{
			BigReal sum = 0;
			for (int j = 0; j < eta; ++j)
			{
				sum += std::log(*lehmerSampleIterator);
				lehmerSampleIterator++;
			}

			BigReal newSampleValue = -1 / lambda * sum;
			sample.sample.push_back(newSampleValue);
		}
	}
}
