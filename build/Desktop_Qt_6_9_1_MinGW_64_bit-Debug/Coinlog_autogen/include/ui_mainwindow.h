/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *changePeriod;
    QTextEdit *actualPeriod;
    QListView *listView;
    QListView *listView_2;
    QPushButton *addTransaction;
    QPushButton *addCategory;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(480, 640);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(230, 10, 241, 201));
        changePeriod = new QPushButton(centralwidget);
        changePeriod->setObjectName("changePeriod");
        changePeriod->setGeometry(QRect(40, 170, 141, 41));
        actualPeriod = new QTextEdit(centralwidget);
        actualPeriod->setObjectName("actualPeriod");
        actualPeriod->setGeometry(QRect(10, 230, 461, 51));
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(0, 300, 231, 281));
        listView_2 = new QListView(centralwidget);
        listView_2->setObjectName("listView_2");
        listView_2->setGeometry(QRect(240, 300, 231, 281));
        addTransaction = new QPushButton(centralwidget);
        addTransaction->setObjectName("addTransaction");
        addTransaction->setGeometry(QRect(40, 30, 141, 41));
        addCategory = new QPushButton(centralwidget);
        addCategory->setObjectName("addCategory");
        addCategory->setGeometry(QRect(40, 100, 141, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 480, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        changePeriod->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        addTransaction->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        addCategory->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
