// dataexchangeui.cpp
#include "dataexchangeui.h"
#include <QDebug>

DataExchangeUI::DataExchangeUI(DataBaseManager* db,
                               CategoryManager* cm,
                               QObject* parent)
    : QObject(parent),
    firstMap(),
    RowExpenseTable(),
    RowProfitTable(),
    dataBase(db),
    analytics(),       // analytics можно оставить по умолчанию
    categoryManager(cm)
{
    // безопасная инициализация: очистить векторы и карты
    RowExpenseTable.clear();
    RowProfitTable.clear();
    firstMap.clear();
}




void DataExchangeUI::firstAutomaticUnload(){
    firstMap = analytics.getMonthSum(*dataBase);
}

void DataExchangeUI::RowCountCounter(){
    for(const auto& i:firstMap){
        qDebug() << "DataExchangeUI: firstMap size =" << firstMap.size();
        const Category *cat = categoryManager->getById(i.first);
        if(!cat) continue;

        if( cat->getType()  == Category::Type::Expense){
            RowExpenseTable.emplace_back(i.first,i.second);
        }
        else{
            RowProfitTable.emplace_back(i.first,i.second);
        }
    }
    qDebug() << "DataExchangeUI: RowExpenseTable =" << RowExpenseTable;
}

QStandardItemModel* DataExchangeUI::createModelExpenseTable(){
    QStandardItemModel *model = new QStandardItemModel(RowExpenseTable.size(),2,this);
    model->setHeaderData(0,Qt::Horizontal,"Категория");
    model->setHeaderData(1,Qt::Horizontal,"Сумма");

    int r=0;
    for(const auto&p : RowExpenseTable){
        qDebug() << "DataExchangeUI: firstMap size =" << RowExpenseTable.size();
        int catId = p.first;
        qint64 amount = p.second;
        auto catPtr = categoryManager->getById(catId);

        if (!catPtr) {
            // Пропускаем
            continue;
        }

        if (catPtr->getType() != Category::Type::Expense) {
            // если модель только для расходов — пропускаем доходы
            continue;
        }

        QString cName = " ";

        if(auto cat = categoryManager->getById(catId)){
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

    return model;
}

QStandardItemModel* DataExchangeUI::createModelProfitTable(){
    QStandardItemModel *model = new QStandardItemModel(RowProfitTable.size(),2,this);
    model->setHeaderData(0,Qt::Horizontal,"Категория");
    model->setHeaderData(1,Qt::Horizontal,"Сумма");

    int r=0;
    for(const auto&p : RowProfitTable){
        qDebug() << "DataExchangeUI: RowProfitTable size =" << RowProfitTable.size();
        int catId = p.first;
        qint64 amount = p.second;
        auto catPtr = categoryManager->getById(catId);

        if (!catPtr) {
            // Пропускаем
            continue;
        }

        if (catPtr->getType() != Category::Type::Income) {
            // если модель только для расходов — пропускаем доходы
            continue;
        }

        QString cName = " ";

        if(auto cat = categoryManager->getById(catId)){
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

    return model;
}
