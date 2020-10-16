#include "simpsongenerator.h"
#include <stdexcept>
#include <iterator>

SimpsonGenerator::SimpsonGenerator():
	bottomLine(DEFAULT_BOTTOM_LINE),
	topLine(DEFAULT_TOP_LINE),
	lehmerGenerator(DEFAULT_BOTTOM_LINE / 2, DEFAULT_TOP_LINE / 2)
{
}

SimpsonGenerator::SimpsonGenerator(BigReal bottomLine, BigReal topLine):
	bottomLine(bottomLine),
	topLine(topLine),
	lehmerGenerator(bottomLine / 2, topLine / 2)
{
}

void SimpsonGenerator::setBottomLine(BigReal bottomLine)
{
	this->bottomLine = bottomLine;
}

void SimpsonGenerator::setTopLine(BigReal topLine)
{
	this->topLine = topLine;
}

const Distribution& SimpsonGenerator::getSample() const
{
	return sample;
}

void SimpsonGenerator::generateSample(int sampleSize)
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
		lehmerGenerator.setBottomLine(bottomLine / 2);
		lehmerGenerator.setTopLine(topLine / 2);
		lehmerGenerator.generateSample(sampleSize * 2);

		auto currentLehmerValueIterator = lehmerGenerator.getSample().sample.begin();
		for (int i = 0; i < sampleSize; ++i)
		{
			auto nextLehmerValueIterator = std::next(currentLehmerValueIterator);
			BigReal newSampleValue = *currentLehmerValueIterator + *nextLehmerValueIterator;
			sample.sample.push_back(newSampleValue);
			currentLehmerValueIterator = ++nextLehmerValueIterator;
		}
	}
}
