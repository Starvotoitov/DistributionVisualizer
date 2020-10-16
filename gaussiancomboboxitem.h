#ifndef GAUSSIANCOMBOBOXITEM_H
#define GAUSSIANCOMBOBOXITEM_H

#include "abstractcomboboxitem.h"
#include "gaussiangenerator.h"

class GaussianComboBoxItem : public AbstractComboBoxItem
{
public:
	GaussianComboBoxItem(QGridLayout *inputLayout, QGridLayout *outputLayout, std::shared_ptr<BarChart> chart);

	virtual void itemChoosed() override;
	virtual void showStatistic(int sampleSize) override;

private:
	inline static QString EXPECTED_VALUE_CAPTION = "Математическое ожидание";
	inline static QString DISPERSION_CAPTION = "Дисперсия";
	inline static QString STANDART_DEVIATION_CAPTION = "Среднее квадратическое отклонение";
	inline static double MIN_EXPECTED_VALUE = -20000000;
	inline static double MAX_EXPECTED_VALUE = 20000000;
	inline static double MIN_STANDART_DEVIATION = -20000000;
	inline static double MAX_STANDART_DEVIATION = 20000000;

	GaussianGenerator generator;
};

#endif // GAUSSIANCOMBOBOXITEM_H
