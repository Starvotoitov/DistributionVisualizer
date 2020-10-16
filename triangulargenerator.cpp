#include "triangulargenerator.h"
#include <stdexcept>
#include <iterator>
#include <algorithm>

TriangularGenerator::TriangularGenerator():
	bottomLine(DEFAULT_BOTTOM_LINE),
	topLine(DEFAULT_TOP_LINE),
	lehmerGenerator(0, 1)
{
}

TriangularGenerator::TriangularGenerator(BigReal bottomLine, BigReal topLine):
	bottomLine(bottomLine),
	topLine(topLine),
	lehmerGenerator(0, 1)
{
}

void TriangularGenerator::setBottomLine(BigReal bottomLine)
{
	this->bottomLine = bottomLine;
}

void TriangularGenerator::setTopLine(BigReal topLine)
{
	this->topLine = topLine;
}

const Distribution& TriangularGenerator::getSample() const
{
	return sample;
}

void TriangularGenerator::generateSample(int sampleSize)
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
		lehmerGenerator.generateSample(sampleSize * 2);
		auto lehmerGeneratorIterator = lehmerGenerator.getSample().sample.begin();
		for (int i = 0; i < sampleSize; ++i)
		{
			auto nextLehmerValueIterator = std::next(lehmerGeneratorIterator);
			BigReal newSampleValue = bottomLine + (topLine - bottomLine) *
					std::max(*lehmerGeneratorIterator, *nextLehmerValueIterator);
			sample.sample.push_back(newSampleValue);
			lehmerGeneratorIterator = ++nextLehmerValueIterator;
		}
	}
}
