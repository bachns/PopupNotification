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
* File name:    PopupNotification/PopupNotification.h
* Date created: Tuesday, Jul 23, 2019
* Written by Bach Nguyen Sy
*/

#ifndef POPUPNOTIFICATION_H
#define POPUPNOTIFICATION_H

#include <QtWidgets/QMainWindow>
#include "ui_PopupNotification.h"

class PopupNotification : public QMainWindow, Ui::PopupNotificationClass
{
	Q_OBJECT

public:
	PopupNotification(QWidget *parent = Q_NULLPTR);

private:
};

#endif