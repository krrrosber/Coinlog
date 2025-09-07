#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "analytics.h"
#include "category.h"
#include "databasemanager.h"
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

private:
    Ui::MainWindow *ui;
    DataBaseManager dataBase;
    Analytics analytics;
};

#endif // MAINWINDOW_H
