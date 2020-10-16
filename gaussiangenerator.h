#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "generator.h"
#include "lehmergenerator.h"
#include "distribution.h"

class GaussianGenerator : public Generator
{
public:
	GaussianGenerator(int summableValuesCount = DEFAULT_SUMMABLE_VALUES_COUNT);
	GaussianGenerator(BigReal expectedValue, BigReal standardDeviation, int summableValuesCount = DEFAULT_SUMMABLE_VALUES_COUNT);

	void setExpectedValue(BigReal expectedValue);
	void setStandardDeviation(BigReal standardDeviation);

	virtual const Distribution& getSample() const override;
	virtual void generateSample(int sampleSize = 0) override;

	inline static BigReal DEFAULT_EXPECTED_VALUE = 0.0;
	inline static BigReal DEFAULT_STANDARD_DEVIATION = 1.0;
	inline static int DEFAULT_SUMMABLE_VALUES_COUNT = 6;

private:
	BigReal expectedValue;
	BigReal standardDeviation;
	int summableValuesCount;

	LehmerGenerator lehmerGenerator;
	Distribution sample;
};

#endif // GAUSSIANGENERATOR_H
