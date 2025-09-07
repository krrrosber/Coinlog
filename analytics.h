#ifndef ANALYTICS_H
#define ANALYTICS_H

#include "databasemanager.h"
#include "transaction.h"
#include <unordered_map>
#include <vector>
#include <chrono>
class Analytics
{
public:
    Analytics() = default;

    std::unordered_map<int,int64_t> getDailySum(DataBaseManager& db);     //сумма за день
    std::unordered_map<int,int64_t> getWeekSum(DataBaseManager& db);     //сумма за неделю
    std::unordered_map<int,int64_t> getMonthSum(DataBaseManager& db);    //сумма за месяц
    std::unordered_map<int,int64_t> getPeriodSum(std::chrono::system_clock::time_point from, std::chrono::system_clock::time_point to);  //сумма за период


private:
    std::vector<Transaction> activities;            //список транзакций
};

#endif // ANALYTICS_H
