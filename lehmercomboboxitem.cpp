#include "lehmercomboboxitem.h"

LehmerComboBoxItem::LehmerComboBoxItem(QGridLayout *inputLayout, QGridLayout *outputLayout, std::shared_ptr<BarChart> chart):
	AbstractComboBoxItem(inputLayout, outputLayout, chart)
{
}

void LehmerComboBoxItem::itemChoosed()
{
	clear();

	addInputSpinBox(MULTIPLIER_CAPTION, 0);
	addInputSpinBox(START_VALUE_CAPTION, 1);
	addInputSpinBox(MODULE_CAPTION, 2);
	addInputDoubleSpinBox(BOTTOM_LINE_CAPTION, 3);
	addInputDoubleSpinBox(TOP_LINE_CAPTION, 4);

	addOutputLine(EXPECTED_VALUE_CAPTION, 0);
	addOutputLine(DISPERSION_CAPTION, 1);
	addOutputLine(STANDARD_DEVIATION_CAPTION, 2);
	addOutputLine(INDERECT_SIGNS_CAPTION, 3);
	addOutputLine(PERIOD_LENGTH_CAPTION, 4);
	addOutputLine(APERIODICITY_SECTION_LENGTH, 5);

	inputLayout->parentWidget()->findChild<QSpinBox*>("spinBoxa")->setValue(LehmerGenerator::DEFAULT_MULTIPLIER);
	inputLayout->parentWidget()->findChild<QSpinBox*>("spinBoxR0")->setValue(LehmerGenerator::DEFAULT_START_VALUE);
	inputLayout->parentWidget()->findChild<QSpinBox*>("spinBoxm")->setValue(LehmerGenerator::DEFAULT_MODULE);
	inputLayout->parentWidget()->findChild<QDoubleSpinBox*>("doubleSpinBoxГраница b")->setValue(1);

	inputLayout->parentWidget()->findChild<QDoubleSpinBox*>("doubleSpinBoxГраница a")->
			setRange(MIN_BOTTOM_LINE, MAX_BOTTOM_LINE);
	inputLayout->parentWidget()->findChild<QDoubleSpinBox*>("doubleSpinBoxГраница b")->
			setRange(MIN_TOP_LINE, MAX_TOP_LINE);
}

void LehmerComboBoxItem::showStatistic(int sampleSize)
{
	generator.setMultiplier(getInputSpinBoxValue(MULTIPLIER_CAPTION));
	generator.setStartValue(getInputSpinBoxValue(START_VALUE_CAPTION));
	generator.setModule(getInputSpinBoxValue(MODULE_CAPTION));
	generator.setBottomLine(getInputDoubleSpinBoxValue(BOTTOM_LINE_CAPTION));
	generator.setTopLine(getInputDoubleSpinBoxValue(TOP_LINE_CAPTION));

	generator.generateSample(sampleSize);
	const UniformDistribution &sample = generator.getSample();

	setOutputLineValue(EXPECTED_VALUE_CAPTION, sample.getExpectedValue());
	setOutputLineValue(DISPERSION_CAPTION, sample.getDispersion());
	setOutputLineValue(STANDARD_DEVIATION_CAPTION, sample.getStandardDeviation());
	setOutputLineValue(INDERECT_SIGNS_CAPTION, sample.getInderectSigns());
	setOutputLineValue(PERIOD_LENGTH_CAPTION, sample.getPeriodLength());
	setOutputLineValue(APERIODICITY_SECTION_LENGTH, sample.getAperiodicitySectionLength());

	chart->showDistribution(sample);
}
