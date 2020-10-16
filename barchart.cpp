#include "barchart.h"

BarChart::BarChart(QCustomPlot *customPlot):
	customPlot(customPlot),
	sampleBar(std::make_unique<QCPBars>(customPlot->xAxis, customPlot->yAxis))
{
}


#include <iostream>

void BarChart::showDistribution(const Distribution &sample)
{
	sampleBar->setName(BAR_NAME);

	QLocale locale;
	QVector<double> ticks;
	QVector<double> data;
	QVector<QString> labels;

	double intervalLength = (sample.getMaximumValue() - sample.getMinimumValue()) / NUMBER_OF_INTERVALS;
	double intervalStart = sample.getMinimumValue();
	double intervalEnd = intervalStart + intervalLength;
	int maxCount = 0;
	for (int i = 0; i < NUMBER_OF_INTERVALS; ++i)
	{
		ticks << i + 1;
		labels << "[" + locale.toString(intervalStart) + ", " + locale.toString(intervalEnd) + ")";
		int currentIntervalCount = sample.countInRange(intervalStart, intervalEnd);
		data << currentIntervalCount;

		std::cout << i + 1 << " " << currentIntervalCount << std::endl;

		if (currentIntervalCount > maxCount)
		{
			maxCount = currentIntervalCount;
		}
		intervalStart = intervalEnd;
		intervalEnd += intervalLength;
	}

	QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
	textTicker->addTicks(ticks, labels);
	customPlot->xAxis->setTicker(textTicker);
	customPlot->xAxis->setTickLabelRotation(LABEL_ROTATION);
	customPlot->xAxis->setSubTicks(false);
	customPlot->xAxis->setRange(0, NUMBER_OF_INTERVALS + 1);

	customPlot->yAxis->setRange(0, maxCount + 1);
	customPlot->yAxis->setPadding(10);

	sampleBar->setData(ticks, data);
	customPlot->replot();
}

void BarChart::clear()
{
	QVector<double> empty;
	sampleBar->setData(empty, empty);
	customPlot->replot();
}
