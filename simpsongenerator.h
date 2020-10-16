#ifndef SIMPSONGENERATOR_H
#define SIMPSONGENERATOR_H

#include "generator.h"
#include "distribution.h"
#include "lehmergenerator.h"

class SimpsonGenerator : public Generator
{
public:
	SimpsonGenerator();
	SimpsonGenerator(BigReal bottomLine, BigReal topLine);

	void setBottomLine(BigReal bottomLine);
	void setTopLine(BigReal topLine);

	virtual const Distribution & getSample() const override;
	virtual void generateSample(int sampleSize = 0) override;

	inline static BigReal DEFAULT_BOTTOM_LINE = 0.0;
	inline static BigReal DEFAULT_TOP_LINE = 2.0;

private:
	BigReal bottomLine;
	BigReal topLine;

	LehmerGenerator lehmerGenerator;
	Distribution sample;
};

#endif // SIMPSONGENERATOR_H
