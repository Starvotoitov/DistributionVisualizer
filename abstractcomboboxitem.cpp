#include "abstractcomboboxitem.h"
#include <QWidget>

AbstractComboBoxItem::AbstractComboBoxItem(QGridLayout *inputLayout, QGridLayout *outputLayout, std::shared_ptr<BarChart> chart):
	inputLayout(inputLayout),
	outputLayout(outputLayout),
	chart(chart)
{
}

void AbstractComboBoxItem::clear()
{
	QLayoutItem *item;
	while ((item = inputLayout->takeAt(0)) != 0)
	{
		if (item->widget() != nullptr)
		{
			delete item->widget();
		}
	}

	while ((item = outputLayout->takeAt(0)) != 0)
	{
		if (item->widget() != nullptr)
		{
			delete item->widget();
		}
	}

	chart->clear();
}

void AbstractComboBoxItem::addInputSpinBox(QString name, int column)
{
	QLabel *newLabel = new QLabel(name);
	newLabel->setObjectName("label" + name);
	QSpinBox *newSpinBox = new QSpinBox();
	newSpinBox->setMaximum(2147483647);
	newSpinBox->setObjectName("spinBox" + name);
	inputLayout->addWidget(newLabel, 0, column);
	inputLayout->addWidget(newSpinBox, 1, column);
}

void AbstractComboBoxItem::addInputDoubleSpinBox(QString name, int column)
{
	QLabel *newLabel = new QLabel(name);
	newLabel->setObjectName("label" + name);
	QDoubleSpinBox *newSpinBox = new QDoubleSpinBox();
	newSpinBox->setMaximum(2147483647.0);
	newSpinBox->setObjectName("doubleSpinBox" + name);
	inputLayout->addWidget(newLabel, 0, column);
	inputLayout->addWidget(newSpinBox, 1, column);
}

void AbstractComboBoxItem::addOutputLine(QString name, int row)
{
	QLabel *newLabel = new QLabel(name);
	newLabel->setObjectName("output" + name);
	outputLayout->addWidget(newLabel, row, 0);
	newLabel = new QLabel();
	newLabel->setObjectName("value" + name);
	outputLayout->addWidget(newLabel, row, 1);
}

int AbstractComboBoxItem::getInputSpinBoxValue(QString name)
{
	return inputLayout->parentWidget()->findChild<QSpinBox*>("spinBox" + name)->value();
}

double AbstractComboBoxItem::getInputDoubleSpinBoxValue(QString name)
{
	return inputLayout->parentWidget()->findChild<QDoubleSpinBox*>("doubleSpinBox" + name)->value();
}

void AbstractComboBoxItem::setOutputLineValue(QString name, BigInt value)
{
	outputLayout->parentWidget()->findChild<QLabel*>("value" + name)->setText(locale.toString(value));
}

void AbstractComboBoxItem::setOutputLineValue(QString name, BigReal value)
{
	outputLayout->parentWidget()->findChild<QLabel*>("value" + name)->setText(locale.toString(value));
}
