#ifndef ExponentialGenerator_H
#define ExponentialGenerator_H

#include "generator.h"
#include "lehmergenerator.h"

class ExponentialGenerator : public Generator
{
public:
	explicit ExponentialGenerator(BigReal intensity = DEFAULT_INTENSITY);

	void setIntensity(BigReal intensity);

	virtual void generateSample(int sampleSize = 0) override;
	virtual const Distribution& getSample() const override;

	inline static BigReal DEFAULT_INTENSITY = 1.0;

private:
	BigReal intensity;

	LehmerGenerator lehmerGenerator;
	Distribution sample;
};

#endif // ExponentialGenerator_H
