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
* File name:    /AlertWidget.h
* Date created: Tuesday, Jul 23, 2019
* Written by Bach Nguyen Sy
*/

#ifndef ALERTWIDGET_H
#define ALERTWIDGET_H

#include <QDialog>
#include "ui_AlertWidget.h"

class AlertWidget : public QDialog, Ui::AlertWidget
{
	Q_OBJECT

public:
	AlertWidget(QDialog *parent = Q_NULLPTR);
	~AlertWidget();

private:

};

#endif