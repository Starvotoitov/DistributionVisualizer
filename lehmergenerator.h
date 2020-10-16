#ifndef LEHMERGENERATOR_H
#define LEHMERGENERATOR_H

#include "generator.h"
#include "uniformdistribution.h"

class LehmerGenerator : public Generator
{
public:
	LehmerGenerator();
	LehmerGenerator(BigInt bottomLine, BigInt topLine);
	LehmerGenerator(BigInt multiplier, BigInt startValue, BigInt module);
	LehmerGenerator(BigInt bottomLine, BigInt topLine, BigInt multiplier, BigInt startValue, BigInt module);

	void setBottomLine(BigInt bottomLine);
	void setTopLine(BigInt topLine);
	void setMultiplier(BigInt multiplier);
	void setStartValue(BigInt startValue);
	void setModule(BigInt module);

	virtual const UniformDistribution& getSample() const override;
	virtual void generateSample(int sampleSize = 0) override;


	inline static BigInt DEFAULT_BOTTOM_LINE = 0;
	inline static BigInt DEFAULT_TOP_LINE = 1;
	inline static BigInt DEFAULT_MULTIPLIER = 16807;
	inline static BigInt DEFAULT_START_VALUE = 2782874;
	inline static BigInt DEFAULT_MODULE = 21474837;

private:
	BigInt bottomLine;
	BigInt topLine;
	BigInt multiplier;
	BigInt startValue;
	BigInt module;

	UniformDistribution uniformSample;
};

#endif // LEHMERGENERATOR_H
