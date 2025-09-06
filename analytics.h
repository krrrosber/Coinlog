#ifndef ANALYTICS_H
#define ANALYTICS_H

#include "transaction.h"
#include <unordered_map>
#include <vector>
#include <chrono>
class Analytics
{
public:
    Analytics(std::vector<Transaction> data):
        activities(std::move(data)){}

    std::unordered_map<int,int64_t> getDailySum();     //сумма за день
    std::unordered_map<int,int64_t> getWeekSum();     //сумма за неделю
    std::unordered_map<int,int64_t> getMonthSum();    //сумма за месяц
    std::unordered_map<int,int64_t> getPeriodSum(std::chrono::system_clock::time_point from, std::chrono::system_clock::time_point to);  //сумма за период


private:
    std::vector<Transaction> activities;            //список транзакций
    //std::unordered_map<int,int64_t> totals;         //суммы по категориям
};

#endif // ANALYTICS_H
