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
	m_showAct = new QAction("Show", this);
	m_exitAct = new QAction("Exit", this);
	m_menu->addAction(m_showAct);
	m_menu->addAction(m_exitAct);
	connect(m_showAct, &QAction::triggered,
		[=] { m_timerBg->stop(); show(); });
	connect(m_exitAct, &QAction::triggered,
		[=] { close(); });
	m_systemTrayIcon->setContextMenu(m_menu);
	m_systemTrayIcon->show();

	m_notificationDlg = new NotificationDialog;
	m_position = m_notificationDlg->position();
	xSbx->setValue(m_position.x());
	ySbx->setValue(m_position.y());
	widthSbx->setValue(m_notificationDlg->width());
	heightSbx->setValue(m_notificationDlg->height());
	
	connect(xSbx, QOverload<int>::of(&QSpinBox::valueChanged),
		[=](int d) { m_position.setX(d); m_notificationDlg->move(m_position); });
	connect(ySbx, QOverload<int>::of(&QSpinBox::valueChanged),
		[=](int d) { m_position.setY(d); m_notificationDlg->move(m_position); });
	connect(widthSbx, QOverload<int>::of(&QSpinBox::valueChanged),
		[=](int d) { m_notificationDlg->setFixedWidth(d); });
	connect(heightSbx, QOverload<int>::of(&QSpinBox::valueChanged),
		[=](int d) { m_notificationDlg->setFixedHeight(d); });
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
	QString styleSheet = QString("background-color: rgb(%1, %2, %3)").arg(color.red()).arg(color.green()).arg(color.blue());
	colorBtn->setStyleSheet(styleSheet);

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
		if (color.isValid())
		{
			m_waitingSpinner->setColor(color);
			QString styleSheet = QString("background-color: rgb(%1, %2, %3)").arg(color.red()).arg(color.green()).arg(color.blue());
			colorBtn->setStyleSheet(styleSheet);
		}
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
	delete m_notificationDlg;
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
	showDialog();
	m_timerShow->start();
	m_timerBg->start();
}