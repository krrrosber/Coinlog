#include "mainwindow.h"
#include "categorymanager.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include<QCalendarWidget>
#include <qgridlayout.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dataBase(),
    categoryManager(),
    dataExchangeUI(analytics, &dataBase, &categoryManager,this),
    analytics()
{
    ui->setupUi(this);

    dataBase.setPath("D:/c++/project/Coinlog/bd/Tran.db");  //каталог нахождения бд

    dataBase.open(dataBase.getPath());   //открываем бд

    refreshLists(1);

    connect(ui->changePeriod,&QPushButton::clicked, this, &MainWindow::openCalendar);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openCalendar(){

    QWidget *calendarWidget = new QWidget(nullptr);
    calendarWidget->resize(600,500);
    calendarWidget->setAttribute(Qt::WA_DeleteOnClose);
    calendarWidget->setWindowTitle(QString("Календарь"));
    QCalendarWidget *calendar = new QCalendarWidget(calendarWidget);
    calendar->setGridVisible(true);

    connect(calendar, &QCalendarWidget::clicked,this,[this](const QDate &date){
        analytics.setTime(date);
    });

    QGridLayout *layout = new QGridLayout(calendarWidget);

    QPushButton *selectChangePeriod =new QPushButton("Выбранный период", calendarWidget);
    QPushButton *selectDailyPeriod =new QPushButton("Данный день", calendarWidget);
    QPushButton *selectWeekPeriod =new QPushButton("Данная неделя", calendarWidget);
    QPushButton *selectMonthPeriod =new QPushButton("Данный месяц", calendarWidget);

     selectDailyPeriod->setFixedSize(120,50);
     selectWeekPeriod->setFixedSize(120,50);
     selectMonthPeriod->setFixedSize(120,50);
    selectChangePeriod->setFixedSize(120,50);
     calendar->setFixedSize(500,300);

    layout->addWidget(calendar,0,0,1,4);
    layout->addWidget(selectDailyPeriod,1,0);
    layout->addWidget(selectWeekPeriod,1,1);
    layout->addWidget(selectMonthPeriod,1,2);
    layout->addWidget(selectChangePeriod,1,3);

    connect(selectDailyPeriod,&QPushButton::clicked,this,[this](){
        refreshLists(1);
    });
    connect(selectWeekPeriod,&QPushButton::clicked,this,[this](){
        refreshLists(2);
    });
    connect(selectMonthPeriod,&QPushButton::clicked,this,[this](){
        refreshLists(3);
    });
    connect(selectChangePeriod,&QPushButton::clicked,this,[this](){
        refreshLists(4);
    });

    calendarWidget->show();
}

void MainWindow::refreshLists(int i){

    dataExchangeUI.clearTable();
    categoryManager.loadFromDb(dataBase);
    dataExchangeUI.firstAutomaticUnload(i);
    dataExchangeUI.RowCountCounter();
    auto modelExpenseTable  = dataExchangeUI.createModelExpenseTable();
    auto modelProfitTable  = dataExchangeUI.createModelProfitTable();

    ui->tableExpenses->setModel(modelExpenseTable);
    ui->tableProfit->setModel(modelProfitTable);
    ui->tableExpenses->horizontalHeader()->setStretchLastSection(true);
    ui->tableProfit->horizontalHeader()->setStretchLastSection(true);
}
