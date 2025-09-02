#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <cstdint>
#include<chrono>
#include <string>

struct Transaction
{
    Transaction(int64_t i, std::chrono::system_clock::time_point t,int64_t a, int c, std::string n):
        id(i),
        timestamp(t),
        amount(a),
        categoryId(c),
        note(n)
    {}
    const int64_t id;                                          // уникальный индефикатор
    const std::chrono::system_clock::time_point timestamp;    // время операции
    int64_t amount;                                     // сумма в копейках
    int categoryId;                                     // категория операции
    std::string note;                                   // заметка
};

#endif // TRANSACTION_H
