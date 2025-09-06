#include "analytics.h"

//сумма за день
std::unordered_map<int,int64_t> Analytics::getDailySum(){


    std::unordered_map<int,int64_t> totals;

    auto days= floor<std::chrono::days>(std::chrono::system_clock::now());
    std::chrono::year_month_day ymd{days};

    std::chrono::sys_days day_start{ymd};

    auto start_of_day =std::chrono::time_point_cast<std::chrono::milliseconds>(day_start);

    auto end_of_day = start_of_day + std::chrono::hours(24);

    for(const auto& tr:activities){
        if(tr.timestamp >= start_of_day && tr.timestamp < end_of_day ){
            totals[tr.categoryId] +=tr.amount;
        }
    }

    return totals;
}

 //сумма за неделю
std::unordered_map<int,int64_t> Analytics::getWeekSum(){
    std::unordered_map<int, int64_t> totals;
    auto days= floor<std::chrono::days>(std::chrono::system_clock::now());
    std::chrono::year_month_day ymd{days};

    std::chrono::sys_days day_start{ymd};

    std::chrono::weekday wd{day_start};
    auto days_since_monday = wd.c_encoding(); // wd.c_encoding(): 0 = Sunday, но ISO: 0 = Monday
    if(days_since_monday == 0) days_since_monday = 7; // корректируем Sunday -> 7

    // начало недели = понедельник
    auto start_of_week = time_point_cast<std::chrono::milliseconds>(day_start - std::chrono::days{days_since_monday - 1});
    auto end_of_week   = start_of_week + std::chrono::days(7); // 7 дней


    for(const auto& tr:activities){
        if(tr.timestamp >= start_of_week && tr.timestamp < end_of_week ){
            totals[tr.categoryId] +=tr.amount;
        }
    }

    return totals;
}

//сумма за месяц
std::unordered_map<int,int64_t> Analytics::getMonthSum(){
      std::unordered_map<int, int64_t> totals;

    auto days= floor<std::chrono::days>(std::chrono::system_clock::now());
    std::chrono::year_month_day ymd{days};

    std::chrono::year_month_day start_of_month{ymd.year(), ymd.month(), std::chrono::day{1}};
    std::chrono::sys_days month_start{start_of_month}; // time_point<system_clock, days>
    auto month_start_ms = time_point_cast<std::chrono::milliseconds>(month_start);
    //
    std::chrono::year_month_day start_of_next_month_ymd{ymd.year(), ymd.month() + std::chrono::months{1}, std::chrono::day{1}};
    std::chrono::sys_days start_of_next_month{start_of_next_month_ymd};
    auto end_of_month_ms = time_point_cast<std::chrono::milliseconds>(start_of_next_month);

    for(const auto& tr:activities){
        if(tr.timestamp >= month_start_ms && tr.timestamp < end_of_month_ms ){
            totals[tr.categoryId] +=tr.amount;
        }
    }

    return totals;

}
std::unordered_map<int,int64_t> Analytics::getPeriodSum(std::chrono::system_clock::time_point from, std::chrono::system_clock::time_point to){}  //сумма за период
