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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *expenses;
    QPushButton *changePeriod;
    QTextEdit *actualPeriod;
    QPushButton *addTransaction;
    QPushButton *addCategory;
    QWidget *profit;
    QTableView *tableExpenses;
    QTableView *tableProfit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1023, 733);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        expenses = new QWidget(centralwidget);
        expenses->setObjectName("expenses");
        expenses->setGeometry(QRect(630, 140, 381, 201));
        changePeriod = new QPushButton(centralwidget);
        changePeriod->setObjectName("changePeriod");
        changePeriod->setGeometry(QRect(20, 310, 141, 81));
        actualPeriod = new QTextEdit(centralwidget);
        actualPeriod->setObjectName("actualPeriod");
        actualPeriod->setGeometry(QRect(220, 10, 771, 51));
        addTransaction = new QPushButton(centralwidget);
        addTransaction->setObjectName("addTransaction");
        addTransaction->setGeometry(QRect(20, 80, 141, 81));
        addCategory = new QPushButton(centralwidget);
        addCategory->setObjectName("addCategory");
        addCategory->setGeometry(QRect(20, 520, 141, 81));
        profit = new QWidget(centralwidget);
        profit->setObjectName("profit");
        profit->setGeometry(QRect(240, 140, 371, 201));
        tableExpenses = new QTableView(centralwidget);
        tableExpenses->setObjectName("tableExpenses");
        tableExpenses->setGeometry(QRect(235, 391, 371, 281));
        tableProfit = new QTableView(centralwidget);
        tableProfit->setObjectName("tableProfit");
        tableProfit->setGeometry(QRect(630, 390, 381, 281));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1023, 22));
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
