#include "gaussiancomboboxitem.h"

GaussianComboBoxItem::GaussianComboBoxItem(QGridLayout *inputLayout, QGridLayout *outputLayout, std::shared_ptr<BarChart> chart):
	AbstractComboBoxItem(inputLayout, outputLayout, chart)
{
}

void GaussianComboBoxItem::itemChoosed()
{
	clear();

	addInputDoubleSpinBox(EXPECTED_VALUE_CAPTION, 0);
	addInputDoubleSpinBox(STANDART_DEVIATION_CAPTION, 1);

	inputLayout->parentWidget()->findChild<QDoubleSpinBox*>("doubleSpinBoxМатематическое ожидание")->
			setRange(MIN_EXPECTED_VALUE, MAX_EXPECTED_VALUE);
	inputLayout->parentWidget()->findChild<QDoubleSpinBox*>("doubleSpinBoxСреднеквадратическое отклонение")->
			setRange(MIN_STANDART_DEVIATION, MAX_STANDART_DEVIATION);

	addOutputLine(EXPECTED_VALUE_CAPTION, 0);
	addOutputLine(DISPERSION_CAPTION, 1);
	addOutputLine(STANDART_DEVIATION_CAPTION, 2);
}

void GaussianComboBoxItem::showStatistic(int sampleSize)
{
	generator.setExpectedValue(getInputDoubleSpinBoxValue(EXPECTED_VALUE_CAPTION));
	generator.setStandardDeviation(getInputDoubleSpinBoxValue(STANDART_DEVIATION_CAPTION));

	generator.generateSample(sampleSize);
	const Distribution &sample = generator.getSample();

	setOutputLineValue(EXPECTED_VALUE_CAPTION, sample.getExpectedValue());
	setOutputLineValue(DISPERSION_CAPTION, sample.getDispersion());
	setOutputLineValue(STANDART_DEVIATION_CAPTION, sample.getStandardDeviation());

	chart->showDistribution(sample);
}
