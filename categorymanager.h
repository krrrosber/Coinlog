#ifndef CATEGORYMANAGER_H
#define CATEGORYMANAGER_H

#include "category.h"
#include "databasemanager.h"
#include <qsqldatabase.h>
#include <unordered_map>

struct CategoryManager
{
public:
    CategoryManager();

    void loadFromDb(DataBaseManager& db);
    Category* getById(int id);

    std::unordered_map<int,Category> categories;
};

#endif // CATEGORYMANAGER_H
