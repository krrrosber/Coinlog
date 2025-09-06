#include <QCoreApplication>
#include <iostream>
#include"databasemanager.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DataBaseManager b;
    b.setPath("D:/c++/project/Coinlog/bd/Tran.db");

    b.open(b.getPath());
    //Transaction g(27,std::chrono::system_clock::now(),45078,1,"trufwl");
    //b.addTransaction(g);
    //bool ok = b.addTransaction(g);
   // std::cout << "Transaction added: " << ok << std::endl;
    //auto trwe = std::chrono::system_clock::now();
    //std::cout<<trwe;
    /*auto qwer = b.testSelect();
    for(auto i:qwer){
        std::cout<<i;
    }*/
    auto f = std::chrono::system_clock::now() - std::chrono::hours(2);
    auto t =std::chrono::system_clock::now();
    auto trywert = b.queryTransaction(f,t);

    for(auto i: trywert){
        std::cout<<i.id<<"/n ";
    }
    //b.fres();
    b.close();
    return 0;
    //return a.exec();
}
