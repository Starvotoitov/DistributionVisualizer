#ifndef TRIANGULARDISTRIBUTION_H
#define TRIANGULARDISTRIBUTION_H

#include "generator.h"
#include "distribution.h"
#include "lehmergenerator.h"

class TriangularGenerator : public Generator
{
public:
	TriangularGenerator();
	TriangularGenerator(BigReal bottomLine, BigReal topLine);

	void setBottomLine(BigReal bottomLine);
	void setTopLine(BigReal topLine);

	virtual const Distribution & getSample() const override;
	virtual void generateSample(int sampleSize = 0) override;

	inline static BigReal DEFAULT_BOTTOM_LINE = 0.0;
	inline static BigReal DEFAULT_TOP_LINE = 1.0;

private:
	BigReal bottomLine;
	BigReal topLine;

	LehmerGenerator lehmerGenerator;
	Distribution sample;
};

#endif // TRIANGULARDISTRIBUTION_H
