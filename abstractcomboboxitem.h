#ifndef ABSTRACTCOMBOBOXITEM_H
#define ABSTRACTCOMBOBOXITEM_H

#include "distribution.h"
#include "barchart.h"
#include <QGridLayout>
#include <QLocale>

class AbstractComboBoxItem
{
public:
	AbstractComboBoxItem(QGridLayout *inputLayout, QGridLayout *outputLayout, std::shared_ptr<BarChart> chart);
	virtual void itemChoosed() = 0;
	virtual void showStatistic(int sampleSize) = 0;

protected:
	QGridLayout *inputLayout;
	QGridLayout *outputLayout;
	std::shared_ptr<BarChart> chart;
	void clear();

	void addInputSpinBox(QString name, int column);
	void addInputDoubleSpinBox(QString name, int column);
	void addOutputLine(QString name, int row);

	int getInputSpinBoxValue(QString name);
	double getInputDoubleSpinBoxValue(QString name);
	void setOutputLineValue(QString name, BigInt value);
	void setOutputLineValue(QString name, BigReal value);
private:
	QLocale locale;
};

#endif // ABSTRACTCOMBOBOXITEM_H
