#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include"transaction.h"
#include <vector>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDir>
#include <QStandardPaths>
#include <QCoreApplication>

class DataBaseManager
{
public:
    DataBaseManager();

    void open(QString path);                // открытие бд
    void close();                               // закрытие бд
    bool addTransaction(const Transaction &t);  // добавить транзакцию в бд
    std::vector<Transaction> queryTransaction(std::chrono::system_clock::time_point from, std::chrono::system_clock::time_point to ); //выборка транзакций
    void pruneOlderThan(std::chrono::system_clock::time_point t); //удалить старые записи
    void setPath(std::string s){
        dbPath=QString::fromStdString(s);
    }

    QString getPath(){
        return dbPath;
    }
private:
    //Transaction transaction; // объект транзакции
    QString dbPath;
    QString connectName;
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
