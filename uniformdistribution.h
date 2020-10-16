#ifndef UNIFORMDISTRIBUTION_H
#define UNIFORMDISTRIBUTION_H

#include "distribution.h"

class UniformDistribution : public Distribution
{
	friend class LehmerGenerator;

public:
	BigReal getInderectSigns() const;
};

#endif // UNIFORMDISTRIBUTION_H
