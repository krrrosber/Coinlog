#include "mainwindow.h"
#include "categorymanager.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dataBase(),
    analytics()
{
    ui->setupUi(this);

    dataBase.setPath("D:/c++/project/Coinlog/bd/Tran.db");

    dataBase.open(dataBase.getPath());
    CategoryManager cm;
    cm.loadFromDb(dataBase);
    auto firstInfo = analytics.getDailySum(dataBase);

    int RowProfitTable = 0;
    int RowExpenseTable = 0;
    for(const auto& i:firstInfo){
        std::cout<<i.first<<"\t"<<i.second;
        if(cm.getById(i.first)->getType() == Category::Type::Expense){
            RowExpenseTable++;
        }
        else{
            RowProfitTable++;
        }
    }

    QStandardItemModel *model = new QStandardItemModel(RowExpenseTable,2,this);
    model->setHeaderData(0,Qt::Horizontal,"Категория");
    model->setHeaderData(1,Qt::Horizontal,"Сумма");

    int r=0;
    for(const auto&p : firstInfo){
        int catId = p.first;
        std::cout<<p.first;
        qint64 amount = p.second;

        std::cout<<p.second;

        auto catPtr = cm.getById(catId);
        if (!catPtr) {
            // Пропускаем или ставим "<Неизвестно>"
            continue;
        }

        if (catPtr->getType() != Category::Type::Expense) {
            // если модель только для расходов — пропускаем доходы
            continue;
        }
        QString cName = " ";

        if(auto cat = cm.getById(catId)){
            cName = QString::fromStdString(catPtr->getName());
        }

        QStandardItem *item0 = new QStandardItem(cName);
        double rub = double(amount)/100.0;
        QString sumStr = QString::number(rub, 'f', 2);

        QStandardItem *item1 = new QStandardItem(sumStr);
        item1->setTextAlignment(Qt::AlignVCenter);

        model->setItem(r,0,item0);
        model->setItem(r,1,item1);
        ++r;
    }

    ui->tableProfit->setModel(model);
    ui->tableProfit->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
