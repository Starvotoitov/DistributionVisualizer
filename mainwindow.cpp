#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "lehmercomboboxitem.h"
#include "exponentialcomboboxitem.h"
#include "gammacomboboxitem.h"
#include "gaussiancomboboxitem.h"
#include "simpsoncomboboxitem.h"
#include "triangularcomboboxitem.h"

#include <memory>

Q_DECLARE_METATYPE(std::shared_ptr<AbstractComboBoxItem>)

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
	, generator(0, 1)
{
	ui->setupUi(this);
	barChart = std::make_shared<BarChart>(ui->barChart);

	addComboBoxItem(UNIFORM_DISTRIBUTION_CAPTION, new LehmerComboBoxItem(ui->inputLayout, ui->resultLayout, barChart));
	addComboBoxItem(EXPONENTIAL_DISTRIBUTION_CAPTION, new ExponentialComboBoxItem(ui->inputLayout, ui->resultLayout, barChart));
	addComboBoxItem(GAMMA_DISTRIBUTION_CAPTION, new GammaComboBoxItem(ui->inputLayout, ui->resultLayout, barChart));
	addComboBoxItem(GAUSSIAN_DISTRIBUTION_CAPTION, new GaussianComboBoxItem(ui->inputLayout, ui->resultLayout, barChart));
	addComboBoxItem(SIMPSON_DISTRIBUTION_CAPTION, new SimpsonComboBoxItem(ui->inputLayout, ui->resultLayout, barChart));
	addComboBoxItem(TRIANGULAR_DISTRIBUTION_CAPTION, new TriangularComboBoxItem(ui->inputLayout, ui->resultLayout, barChart));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::addComboBoxItem(QString itemName, AbstractComboBoxItem *newItem)
{
	std::shared_ptr<AbstractComboBoxItem> itemSmartPtr(newItem);
	ui->chooseComboBox->addItem(itemName, QVariant::fromValue(itemSmartPtr));
}

void MainWindow::on_calculateButton_clicked()
{
	auto item = ui->chooseComboBox->currentData().value<std::shared_ptr<AbstractComboBoxItem>>();
	item->showStatistic(ui->countSpinBox->value());
}

void MainWindow::on_chooseComboBox_currentIndexChanged(int index)
{
	auto item = ui->chooseComboBox->itemData(index).value<std::shared_ptr<AbstractComboBoxItem>>();
	item->itemChoosed();
}
