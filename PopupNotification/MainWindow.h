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
* File name:    PopupNotification/MainWindow.h
* Date created: Tuesday, Jul 23, 2019
* Written by Bach Nguyen Sy
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QTimer>
#include <QPoint>
#include "ui_MainWindow.h"
#include "NotificationDialog.h"
#include "WaitingSpinnerWidget.h"

class MainWindow : public QMainWindow, Ui::MainWindowClass
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private slots:
	void showDialog();
	void closeDialog();
	void startDialog();

private:
	NotificationDialog* m_notificationDlg = nullptr;
	WaitingSpinnerWidget* m_waitingSpinner = nullptr;
	QSystemTrayIcon* m_systemTrayIcon = nullptr;
	QTimer* m_timerShow = nullptr;
	QTimer* m_timerBg = nullptr;
	QMenu* m_menu = nullptr;
	QAction* m_showAct = nullptr;
	QAction* m_exitAct = nullptr;
	QPoint m_position;
};

#endif