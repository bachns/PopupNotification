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
	m_timerShow = new QTimer(this);
	m_timerShow->setInterval(2 * 1000);
	connect(m_timerShow, &QTimer::timeout, [=] {
		closeDialog();
		m_timerShow->stop();
	});
	connect(timeSbx, QOverload<int>::of(&QSpinBox::valueChanged),
		[=] (int d) {
		m_timerShow->setInterval(d*1000);
	});

	m_timerBg = new QTimer(this);
	m_timerBg->setInterval(10 * 1000);
	connect(m_timerBg, &QTimer::timeout, [=]{
		showDialog();
		m_timerShow->start();
	});
	connect(stepSbx, QOverload<int>::of(&QSpinBox::valueChanged),
		[=](int d) {
		m_timerBg->setInterval(d*1000);
	});

	m_systemTrayIcon = new QSystemTrayIcon(this);
	m_systemTrayIcon->setIcon(QIcon(":/Resources/bachns.svg"));
	m_menu = new QMenu(this);
	m_closeAct = new QAction("Close", this);
	m_hideAct = new QAction("Hide", this);
	m_hideAct->setCheckable(true);
	m_hideAct->setChecked(false);
	m_menu->addAction(m_hideAct);
	m_menu->addAction(m_closeAct);
	m_systemTrayIcon->setContextMenu(m_menu);
	connect(m_hideAct, &QAction::triggered,
		[=] {
		if (m_hideAct->isChecked())
		{
			hide();
		}
		else
		{
			m_timerBg->stop();
			show();
		}
	});
	connect(m_closeAct, &QAction::triggered,
		[=] {
		close();
	});

	m_notificationDlg = new NotificationDialog;
	m_waitingSpinner = m_notificationDlg->waitingSpinnerWidget();
	
	roundnessDsbx->setValue(m_waitingSpinner->roundness());
	opacityDsbx->setValue(m_waitingSpinner->minimumTrailOpacity());
	fadePercDsbx->setValue(m_waitingSpinner->trailFadePercentage());
	linesSbx->setValue(m_waitingSpinner->numberOfLines());
	lineLengthSbx->setValue(m_waitingSpinner->lineLength());
	lineWidthSbx->setValue(m_waitingSpinner->lineWidth());
	innerRadiusSbx->setValue(m_waitingSpinner->innerRadius());
	revDsbx->setValue(m_waitingSpinner->revolutionsPersSecond());
	timeSbx->setValue(m_timerShow->interval() / 1000);
	stepSbx->setValue(m_timerBg->interval() / 1000);
	
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

	connect(showBtn, &QAbstractButton::clicked,
		[=] {
		showDialog();
	});
	connect(hideBtn, &QAbstractButton::clicked,
		[=] {
		closeDialog();
	});
	connect(startBtn, &QAbstractButton::clicked, this, &MainWindow::startDialog);
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

void MainWindow::startDialog()
{
	hide();
	m_hideAct->setChecked(true);
	showDialog();
	m_timerShow->start();
	m_timerBg->start();
}
