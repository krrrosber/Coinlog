#include "category.h"
#include <stdexcept>

Category::Category(int i, std::string s, Type t):
    id(i), name(s), type(t)
{}

// установить id
void Category::setId(int i){
    id = i;
}

// получить id
const int Category::getId() const {
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


  Category::Type Category::parseToType(int i){
    if(i==0) return Category::Type::Expense;
    if(i==1)return Category::Type::Income;
    throw std::invalid_argument("Unknown category type");//в будущем нужно ловить исключение, выводить окно для ввода правильного типа
  }
