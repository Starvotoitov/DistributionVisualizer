#ifndef GENERATOR_H
#define GENERATOR_H

#include "distribution.h"

class Generator
{
public:
	virtual void generateSample(int sampleSize = 0) = 0;
	virtual const Distribution& getSample() const = 0;
};

#endif // GENERATOR_H
