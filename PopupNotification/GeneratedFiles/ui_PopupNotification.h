/********************************************************************************
** Form generated from reading UI file 'PopupNotification.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPNOTIFICATION_H
#define UI_POPUPNOTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PopupNotificationClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PopupNotificationClass)
    {
        if (PopupNotificationClass->objectName().isEmpty())
            PopupNotificationClass->setObjectName(QStringLiteral("PopupNotificationClass"));
        PopupNotificationClass->resize(600, 400);
        menuBar = new QMenuBar(PopupNotificationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        PopupNotificationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PopupNotificationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PopupNotificationClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(PopupNotificationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PopupNotificationClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PopupNotificationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PopupNotificationClass->setStatusBar(statusBar);

        retranslateUi(PopupNotificationClass);

        QMetaObject::connectSlotsByName(PopupNotificationClass);
    } // setupUi

    void retranslateUi(QMainWindow *PopupNotificationClass)
    {
        PopupNotificationClass->setWindowTitle(QApplication::translate("PopupNotificationClass", "PopupNotification", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PopupNotificationClass: public Ui_PopupNotificationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPNOTIFICATION_H
