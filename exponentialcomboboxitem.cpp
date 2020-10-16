#include "exponentialcomboboxitem.h"

ExponentialComboBoxItem::ExponentialComboBoxItem(QGridLayout *inputLayout, QGridLayout *outputLayout, std::shared_ptr<BarChart> chart):
	AbstractComboBoxItem(inputLayout, outputLayout, chart)
{
}

void ExponentialComboBoxItem::itemChoosed()
{
	clear();

	addInputDoubleSpinBox(LAMBDA_CAPTION, 0);

	addOutputLine(EXPECTED_VALUE_CAPTION, 0);
	addOutputLine(DISPERSION_CAPTION, 1);
	addOutputLine(STANDART_DEVIATION_CAPTION, 2);

inputLayout->parentWidget()->findChild<QDoubleSpinBox*>("doubleSpinBoxЛямбда")->setRange(MIN_LAMBDA, MAX_LAMBDA);
}

void ExponentialComboBoxItem::showStatistic(int sampleSize)
{
	generator.setIntensity(getInputDoubleSpinBoxValue(LAMBDA_CAPTION));

	generator.generateSample(sampleSize);
	const Distribution &sample = generator.getSample();

	setOutputLineValue(EXPECTED_VALUE_CAPTION, sample.getExpectedValue());
	setOutputLineValue(DISPERSION_CAPTION, sample.getDispersion());
	setOutputLineValue(STANDART_DEVIATION_CAPTION, sample.getStandardDeviation());

	chart->showDistribution(sample);
}
