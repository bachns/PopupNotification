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
* File name:    /NotificationDialog.h
* Date created: Tuesday, Jul 23, 2019
* Written by Bach Nguyen Sy
*/

#ifndef NOTIFICATIONDIALOG_H
#define NOTIFICATIONDIALOG_H

#include <QDialog>
#include "ui_NotificationDialog.h"

class NotificationDialog : public QDialog, Ui::NotificationDialog
{
	Q_OBJECT

public:
	NotificationDialog(QWidget *parent = Q_NULLPTR);
	~NotificationDialog();
	WaitingSpinnerWidget* waitingSpinnerWidget() const;

private:
};

#endif