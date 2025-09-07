#include "categorymanager.h"
#include "databasemanager.h"

CategoryManager::CategoryManager() {}

void CategoryManager::loadFromDb(DataBaseManager& db) {
    std::vector<Category> buffer = db.queryCategories();
    categories.clear();

    for( const auto& i: buffer){
        categories.emplace(i.getId(),i);
    }
}

 Category* CategoryManager::getById(int id) {
     auto it = categories.find(id);
     if(it == categories.end()) return nullptr;
     return &it->second;
}
