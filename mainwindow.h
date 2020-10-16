#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "lehmergenerator.h"
#include "barchart.h"
#include "abstractcomboboxitem.h"
#include <memory>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_calculateButton_clicked();

	void on_chooseComboBox_currentIndexChanged(int index);

private:
	inline static QString UNIFORM_DISTRIBUTION_CAPTION = "Равномерное распределение";
	inline static QString EXPONENTIAL_DISTRIBUTION_CAPTION = "Экспоненциальное распределение";
	inline static QString GAMMA_DISTRIBUTION_CAPTION = "Гамма-распределение";
	inline static QString GAUSSIAN_DISTRIBUTION_CAPTION = "Гауссовское распределение";
	inline static QString SIMPSON_DISTRIBUTION_CAPTION = "Распределение Симпсона";
	inline static QString TRIANGULAR_DISTRIBUTION_CAPTION = "Треугольное распределение";

	Ui::MainWindow *ui;
	LehmerGenerator generator;
	std::shared_ptr<BarChart> barChart;

	void addComboBoxItem(QString itemName, AbstractComboBoxItem *newItem);
};
#endif // MAINWINDOW_H
