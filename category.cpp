#include "category.h"

Category::Category(int i, std::string s, Type t):
    id(i), name(s), type(t)
{}

// установить id
void Category::setId(int i){
    id = i;
}

// получить id
int Category::getId(){
    return id;
}

// установить название
void Category::setName(std::string s){
    name = s;
}

// получить название
std::string Category::getName(){
    return name;
}

// установить тип
void Category::setType(Type t){
    type = t ;
}

// получить тип
Category::Type Category::getType(){
    return type;
}


// создать категорию
void Category::createCategory(int i, std::string s, Category::Type t){
    Category c(i,s,t);
}

// удалить категорию
void Category::deleteCategory(){
    delete this;
}

