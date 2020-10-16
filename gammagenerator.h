#ifndef GammaGenerator_H
#define GammaGenerator_H

#include "generator.h"
#include "distribution.h"
#include "lehmergenerator.h"

class GammaGenerator : public Generator
{
public:
	GammaGenerator();
	GammaGenerator(BigReal eta, BigReal lambda);

	void setEta(BigReal eta);
	void setLambda(BigReal lambda);

	virtual const Distribution& getSample() const override;
	virtual void generateSample(int sampleSize = 0) override;

	inline static BigReal DEFAULT_ETA = 2.0;
	inline static BigReal DEFAULT_LAMBDA = 2.0;

private:
	BigReal eta;
	BigReal lambda;

	LehmerGenerator lehmerGenerator;
	Distribution sample;
};

#endif // GammaGenerator_H
