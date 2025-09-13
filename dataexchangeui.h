// dataexchangeui.h
#ifndef DATAEXCHANGEUI_H
#define DATAEXCHANGEUI_H

#include <QObject>
#include <QStandardItemModel>
#include "analytics.h"
#include "categorymanager.h"
#include "databasemanager.h"

class DataExchangeUI : public QObject
{
    Q_OBJECT
public:
    explicit DataExchangeUI(Analytics& analyticsRef,
                            DataBaseManager* db = nullptr,
                            CategoryManager* cm = nullptr,
                            QObject* parent = nullptr);

    void firstAutomaticUnload(int i);
    void RowCountCounter();
    QStandardItemModel* createModelExpenseTable();
    QStandardItemModel* createModelProfitTable();
    void clearTable();

    std::unordered_map<int,int64_t> firstMap;
    std::vector<std::pair<int, qint64>> RowExpenseTable;
    std::vector<std::pair<int, qint64>> RowProfitTable;

private:
    DataBaseManager* dataBase;
    Analytics &analytics;
    CategoryManager* categoryManager;
};

#endif // DATAEXCHANGEUI_H
