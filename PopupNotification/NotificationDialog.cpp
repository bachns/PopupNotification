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
* File name:    /NotificationDialog.cpp
* Date created: Tuesday, Jul 23, 2019
* Written by Bach Nguyen Sy
*/

#include "NotificationDialog.h"
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <QDesktopWidget>

NotificationDialog::NotificationDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	setAttribute(Qt::WA_ShowWithoutActivating);

	QDesktopWidget* desktop = QApplication::desktop();
	QRect rect = desktop->screenGeometry();
	move(rect.width() - width() - 50, rect.height() - height() - 50);
	
	//waitingSpinner->setColor(QColor("#FFFFFF"));
	//waitingSpinner->setLineLength(15);
	//waitingSpinner->start();
}

NotificationDialog::~NotificationDialog()
{
}

WaitingSpinnerWidget* NotificationDialog::waitingSpinnerWidget() const
{
	return waitingSpinner;
}
