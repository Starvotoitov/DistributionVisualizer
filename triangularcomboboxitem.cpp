#include "triangularcomboboxitem.h"

TriangularComboBoxItem::TriangularComboBoxItem(QGridLayout *inputLayout, QGridLayout *outputLayout, std::shared_ptr<BarChart> chart):
	AbstractComboBoxItem(inputLayout, outputLayout, chart)
{
}

void TriangularComboBoxItem::itemChoosed()
{
	clear();

	addInputDoubleSpinBox(BOTTOM_LINE_CAPTION, 3);
	addInputDoubleSpinBox(TOP_LINE_CAPTION, 4);

	inputLayout->parentWidget()->findChild<QDoubleSpinBox*>("doubleSpinBoxГраница a")->
			setRange(MIN_BOTTOM_LINE, MAX_BOTTOM_LINE);
	inputLayout->parentWidget()->findChild<QDoubleSpinBox*>("doubleSpinBoxГраница b")->
			setRange(MIN_TOP_LINE, MAX_TOP_LINE);


	addOutputLine(EXPECTED_VALUE_CAPTION, 0);
	addOutputLine(DISPERSION_CAPTION, 1);
	addOutputLine(STANDARD_DEVIATION_CAPTION, 2);
}

void TriangularComboBoxItem::showStatistic(int sampleSize)
{
	generator.setBottomLine(getInputDoubleSpinBoxValue(BOTTOM_LINE_CAPTION));
	generator.setTopLine(getInputDoubleSpinBoxValue(TOP_LINE_CAPTION));

	generator.generateSample(sampleSize);
	const Distribution &sample = generator.getSample();

	setOutputLineValue(EXPECTED_VALUE_CAPTION, sample.getExpectedValue());
	setOutputLineValue(DISPERSION_CAPTION, sample.getDispersion());
	setOutputLineValue(STANDARD_DEVIATION_CAPTION, sample.getStandardDeviation());

	chart->showDistribution(sample);
}
