#ifndef TRIANGULARCOMBOBOXITEM_H
#define TRIANGULARCOMBOBOXITEM_H

#include "abstractcomboboxitem.h"
#include "triangulargenerator.h"

class TriangularComboBoxItem : public AbstractComboBoxItem
{
public:
	TriangularComboBoxItem(QGridLayout *inputLayout, QGridLayout *outputLayout, std::shared_ptr<BarChart> chart);

	virtual void itemChoosed() override;
	virtual void showStatistic(int sampleSize) override;

private:
	inline static QString BOTTOM_LINE_CAPTION = "Граница a";
	inline static QString TOP_LINE_CAPTION = "Граница b";
	inline static QString EXPECTED_VALUE_CAPTION = "Математическое ожидание";
	inline static QString DISPERSION_CAPTION = "Дисперсия";
	inline static QString STANDARD_DEVIATION_CAPTION = "Среднеквадратическое отклонение";
	inline static double MIN_BOTTOM_LINE = -20000000;
	inline static double MAX_BOTTOM_LINE = 20000000;
	inline static double MIN_TOP_LINE = -20000000;
	inline static double MAX_TOP_LINE = 20000000;

	TriangularGenerator generator;
};

#endif // TRIANGULARCOMBOBOXITEM_H
