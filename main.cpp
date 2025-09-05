#include <QCoreApplication>
#include <iostream>
#include"databasemanager.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DataBaseManager b;
    b.setPath("D:/c++/project/Coinlog/bd/Tran.db");

    b.open(b.getPath());
    Transaction g(89,std::chrono::system_clock::now(),4507,3,"ячзо");
    //b.addTransaction(g);
    bool ok = b.addTransaction(g);
    std::cout << "Transaction added: " << ok << std::endl;
    auto trwe = std::chrono::system_clock::now();
    std::cout<<trwe;
    b.close();
    return 0;
    //return a.exec();
}
