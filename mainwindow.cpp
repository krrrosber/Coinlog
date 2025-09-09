#include "mainwindow.h"
#include "categorymanager.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dataBase(),
    categoryManager(),
    dataExchangeUI(&dataBase, &categoryManager,this)
{
    ui->setupUi(this);

    dataBase.setPath("D:/c++/project/Coinlog/bd/Tran.db");  //каталог нахождения бд

    dataBase.open(dataBase.getPath());   //открываем бд

    categoryManager.loadFromDb(dataBase);

    dataExchangeUI.firstAutomaticUnload();
    dataExchangeUI.RowCountCounter();
    auto modelExpenseTable  = dataExchangeUI.createModelExpenseTable();
    auto modelProfitTable  = dataExchangeUI.createModelProfitTable();

    ui->tableExpenses->setModel(modelExpenseTable);
    ui->tableProfit->setModel(modelProfitTable);
    ui->tableExpenses->horizontalHeader()->setStretchLastSection(true);
    ui->tableProfit->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
