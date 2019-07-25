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
* File name:    /AlertWidget.cpp
* Date created: Tuesday, Jul 23, 2019
* Written by Bach Nguyen Sy
*/

#include "AlertWidget.h"

AlertWidget::AlertWidget(QString title, QString body, QPixmap image, int duration)
	: QDialog(Q_NULLPTR)
{
	setupUi(this);
	setStyleSheet("background-color:#999999");
}

AlertWidget::~AlertWidget()
{
}
