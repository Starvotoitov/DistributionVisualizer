#ifndef GAMMACOMBOBOXITEM_H
#define GAMMACOMBOBOXITEM_H

#include "abstractcomboboxitem.h"
#include "gammagenerator.h"

class GammaComboBoxItem : public AbstractComboBoxItem
{
public:
	GammaComboBoxItem(QGridLayout *inputLayout, QGridLayout *outputLayout, std::shared_ptr<BarChart> chart);

	virtual void itemChoosed() override;
	virtual void showStatistic(int sampleSize) override;

private:
	inline static QString ETA_CAPTION = "Эта";
	inline static QString LAMBDA_CAPTION = "Лямбда";
	inline static QString EXPECTED_VALUE_CAPTION = "Математическое ожидание";
	inline static QString DISPERSION_CAPTION = "Дисперсия";
	inline static QString STANDART_DEVIATION_CAPTION = "Среднее квадратическое отклонение";
	inline static double MIN_ETA = -20000000;
	inline static double MAX_ETA = 20000000;
	inline static double MIN_LAMBDA = -20000000;
	inline static double MAX_LAMBDA = 20000000;

	GammaGenerator generator;
};

#endif // GAMMACOMBOBOXITEM_H
