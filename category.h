#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
class Category
{
public:

    enum class Type{Expense,Income};

    Category(int i, std::string s, Type t);

    void setId(int id);                                             // установить id
    int getId();                                                    // получить id
    void setName(std::string);                                      // установить название
    std::string getName();                                          // получить название
    void setType(Type t);                                           // установить тип
    Type getType();                                                 // получить тип
    void createCategory(int i, std::string s, Category::Type t);    // создать категорию
    void deleteCategory();                                          // удалить категорию

private:
    int id;                                                         // уникальный индефикатор категории
    std::string name;                                               // название категории
    Type type;                                                      // тип категории (Расход или Доход)
};


#endif // CATEGORY_H
