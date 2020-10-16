#ifndef LEHMERCOMBOBOXITEM_H
#define LEHMERCOMBOBOXITEM_H

#include "abstractcomboboxitem.h"
#include "lehmergenerator.h"

class LehmerComboBoxItem : public AbstractComboBoxItem
{
public:
	LehmerComboBoxItem(QGridLayout *inputLayout, QGridLayout *outputLayout, std::shared_ptr<BarChart> chart);

	virtual void itemChoosed() override;
	virtual void showStatistic(int sampleSize) override;

private:
	inline static QString MULTIPLIER_CAPTION = "a";
	inline static QString START_VALUE_CAPTION = "R0";
	inline static QString MODULE_CAPTION = "m";
	inline static QString BOTTOM_LINE_CAPTION = "Граница a";
	inline static QString TOP_LINE_CAPTION = "Граница b";
	inline static QString EXPECTED_VALUE_CAPTION = "Математическое ожидание";
	inline static QString DISPERSION_CAPTION = "Дисперсия";
	inline static QString STANDARD_DEVIATION_CAPTION = "Среднеквадратическое отклонение";
	inline static QString INDERECT_SIGNS_CAPTION = "Косвенные признаки";
	inline static QString PERIOD_LENGTH_CAPTION = "Длина периода";
	inline static QString APERIODICITY_SECTION_LENGTH = "Длина отрезка апериодичности";
	inline static double MIN_BOTTOM_LINE = -20000000;
	inline static double MAX_BOTTOM_LINE = 20000000;
	inline static double MIN_TOP_LINE = -20000000;
	inline static double MAX_TOP_LINE = 20000000;

	LehmerGenerator generator;

};

#endif // LEHMERCOMBOBOXITEM_H
