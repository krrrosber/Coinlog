#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "analytics.h"
#include "categorymanager.h"
#include "databasemanager.h"
#include "dataexchangeui.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void openCalendar();
    void refreshLists(int i);
private:
    Ui::MainWindow *ui;
    DataBaseManager dataBase;
    CategoryManager categoryManager;
    DataExchangeUI dataExchangeUI;
    Analytics analytics;
};

#endif // MAINWINDOW_H
