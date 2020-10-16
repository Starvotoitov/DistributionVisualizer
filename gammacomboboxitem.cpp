#include "gammacomboboxitem.h"

GammaComboBoxItem::GammaComboBoxItem(QGridLayout *inputLayout, QGridLayout *outputLayout, std::shared_ptr<BarChart> chart):
	AbstractComboBoxItem(inputLayout, outputLayout, chart)
{
}

void GammaComboBoxItem::itemChoosed()
{
	clear();

	addInputDoubleSpinBox(ETA_CAPTION, 0);
	addInputDoubleSpinBox(LAMBDA_CAPTION, 1);

	addOutputLine(EXPECTED_VALUE_CAPTION, 0);
	addOutputLine(DISPERSION_CAPTION, 1);
	addOutputLine(STANDART_DEVIATION_CAPTION, 2);

	inputLayout->parentWidget()->findChild<QDoubleSpinBox*>("doubleSpinBoxЭта")->setRange(MIN_ETA, MAX_ETA);
	inputLayout->parentWidget()->findChild<QDoubleSpinBox*>("doubleSpinBoxЛямбда")->setRange(MIN_LAMBDA, MAX_LAMBDA);

}

void GammaComboBoxItem::showStatistic(int sampleSize)
{
	generator.setEta(getInputDoubleSpinBoxValue(ETA_CAPTION));
	generator.setLambda(getInputDoubleSpinBoxValue(LAMBDA_CAPTION));

	generator.generateSample(sampleSize);
	const Distribution &sample = generator.getSample();

	setOutputLineValue(EXPECTED_VALUE_CAPTION, sample.getExpectedValue());
	setOutputLineValue(DISPERSION_CAPTION, sample.getDispersion());
	setOutputLineValue(STANDART_DEVIATION_CAPTION, sample.getStandardDeviation());
	chart->showDistribution(sample);
}
