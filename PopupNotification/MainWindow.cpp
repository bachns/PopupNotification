/********************************************************************************
*   Copyright (C) 2018 by Bach Nguyen Sy                                       *
*   Unauthorized copying of this file via any medium is strictly prohibited    *
*                                                                              *
*   <bachns.dev@gmail.com>                                                     *
*   https://bachns.wordpress.com                                               *
*   https://www.facebook.com/bachns.dev                                        *
*                                                                              *
********************************************************************************/

/**
* File name:    PopupNotification/MainWindow.cpp
* Date created: Tuesday, Jul 23, 2019
* Written by Bach Nguyen Sy
*/


#include <QColorDialog>
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);
	m_notificationDlg = new NotificationDialog(this);
	m_waitingSpinner = m_notificationDlg->waitingSpinnerWidget();
	
	roundnessDsbx->setValue(m_waitingSpinner->roundness());
	opacityDsbx->setValue(m_waitingSpinner->minimumTrailOpacity());
	fadePercDsbx->setValue(m_waitingSpinner->trailFadePercentage());
	linesSbx->setValue(m_waitingSpinner->numberOfLines());
	lineLengthSbx->setValue(m_waitingSpinner->lineLength());
	lineWidthSbx->setValue(m_waitingSpinner->lineWidth());
	innerRadiusSbx->setValue(m_waitingSpinner->innerRadius());
	revDsbx->setValue(m_waitingSpinner->revolutionsPersSecond());
	
	QColor color = m_waitingSpinner->color();
	QString colorStr = QString("(%1, %2, %3)").arg(color.red()).arg(color.green()).arg(color.blue());
	colorLedr->setText(colorStr);

	connect(roundnessDsbx, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
		[=](double d) { m_waitingSpinner->setRoundness(d); });
	connect(opacityDsbx, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
		[=](double d) { m_waitingSpinner->setMinimumTrailOpacity(d); });
	connect(fadePercDsbx, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
		[=](double d) { m_waitingSpinner->setTrailFadePercentage(d); });
	connect(linesSbx, QOverload<int>::of(&QSpinBox::valueChanged),
		[=](int d) { m_waitingSpinner->setNumberOfLines(d); });
	connect(lineLengthSbx, QOverload<int>::of(&QSpinBox::valueChanged),
		[=](int d) { m_waitingSpinner->setLineLength(d); });
	connect(lineWidthSbx, QOverload<int>::of(&QSpinBox::valueChanged),
		[=](int d) { m_waitingSpinner->setLineWidth(d); });
	connect(innerRadiusSbx, QOverload<int>::of(&QSpinBox::valueChanged),
		[=](int d) { m_waitingSpinner->setInnerRadius(d); });
	connect(revDsbx, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
		[=](double d) { m_waitingSpinner->setRevolutionsPerSecond(d); });
	connect(colorBtn, &QAbstractButton::clicked,
		[=] {
		QColor color = QColorDialog::getColor(m_waitingSpinner->color(), this);
		m_waitingSpinner->setColor(color);
		QString colorStr = QString("(%1, %2, %3)").arg(color.red()).arg(color.green()).arg(color.blue());
		colorLedr->setText(colorStr);
	});

	connect(showBtn, &QAbstractButton::clicked, this, &MainWindow::showDialog);
	connect(hideBtn, &QAbstractButton::clicked, this, &MainWindow::closeDialog);
}

MainWindow::~MainWindow()
{
	closeDialog();
}

void MainWindow::showDialog()
{
	m_notificationDlg->show();
	m_waitingSpinner->start();
}

void MainWindow::closeDialog()
{
	m_waitingSpinner->stop();
	m_notificationDlg->close();
}
