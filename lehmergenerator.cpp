#include "lehmergenerator.h"
#include <stdexcept>
#include <algorithm>

LehmerGenerator::LehmerGenerator():
	bottomLine(DEFAULT_BOTTOM_LINE),
	topLine(DEFAULT_TOP_LINE),
	multiplier(DEFAULT_MULTIPLIER),
	startValue(DEFAULT_START_VALUE),
	module(DEFAULT_MODULE)
{
}

LehmerGenerator::LehmerGenerator(BigInt bottomLine, BigInt topLine):
	bottomLine(bottomLine),
	topLine(topLine),
	multiplier(DEFAULT_MULTIPLIER),
	startValue(DEFAULT_START_VALUE),
	module(DEFAULT_MODULE)
{
}

LehmerGenerator::LehmerGenerator(BigInt multiplier, BigInt startValue, BigInt module):
	bottomLine(DEFAULT_BOTTOM_LINE),
	topLine(DEFAULT_TOP_LINE),
	multiplier(multiplier),
	startValue(startValue),
	module(module)
{
}

LehmerGenerator::LehmerGenerator(BigInt bottomLine, BigInt topLine, BigInt multiplier, BigInt startValue, BigInt module):
	bottomLine(bottomLine),
	topLine(topLine),
	multiplier(multiplier),
	startValue(startValue),
	module(module)
{
}

void LehmerGenerator::setBottomLine(BigInt bottomLine)
{
	this->bottomLine = bottomLine;
}

void LehmerGenerator::setTopLine(BigInt topLine)
{
	this->topLine = topLine;
}

void LehmerGenerator::setMultiplier(BigInt multiplier)
{
	this->multiplier = multiplier;
}

void LehmerGenerator::setStartValue(BigInt startValue)
{
	this->startValue = startValue;
}

void LehmerGenerator::setModule(BigInt module)
{
	this->module = module;
}

const UniformDistribution& LehmerGenerator::getSample() const
{
	return uniformSample;
}

void LehmerGenerator::generateSample(int sampleSize)
{
	if (sampleSize < 0)
	{
		throw std::invalid_argument("");
	}

	uniformSample.sample.clear();

	if (sampleSize == 0)
	{
		BigInt currentValue = startValue;
		bool duplicateNotFound = true;
		do
		{
			BigInt newValue = multiplier * currentValue % module;
			BigReal newSampleValue = bottomLine + (topLine - bottomLine) * (static_cast<BigReal>(newValue) / module);
			duplicateNotFound = std::none_of(uniformSample.sample.begin(), uniformSample.sample.end(), [newSampleValue](auto prevValue)
			{
				return newSampleValue == prevValue;
			});

			if (duplicateNotFound)
			{
				uniformSample.sample.push_back(newSampleValue);
				currentValue = newValue;
			}
		}
		while (duplicateNotFound);
	}
	else
	{
		BigInt currentValue = startValue;
		for (int i = 0; i < sampleSize; ++i)
		{
			BigInt temp = multiplier * currentValue % module;
			BigReal R = static_cast<BigReal>(temp) / module;
			BigReal newValue = bottomLine + (topLine - bottomLine) * R;
			uniformSample.sample.push_back(newValue);
			currentValue = temp;
		}
	}
}
