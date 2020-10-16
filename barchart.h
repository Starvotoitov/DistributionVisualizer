#ifndef BARCHART_H
#define BARCHART_H

#include "qcustomplot.h"
#include "distribution.h"
#include <memory>

class BarChart
{
public:
	BarChart(QCustomPlot *customPlot);
	void showDistribution(const Distribution &sample);
	void clear();

private:
	inline static int NUMBER_OF_INTERVALS = 20;
	inline static double LABEL_ROTATION = 45;
	inline static QString BAR_NAME = "Гистограмма";

	QCustomPlot *customPlot;
	std::unique_ptr<QCPBars> sampleBar;
};

#endif // BARCHART_H
