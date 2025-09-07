#include <QCoreApplication>
#include <iostream>
#include <qapplication.h>
#include "analytics.h"
#include"databasemanager.h"
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    /*DataBaseManager b;
    b.setPath("D:/c++/project/Coinlog/bd/Tran.db");

    b.open(b.getPath());
    //Transaction g(4,std::chrono::system_clock::now(),32,1,"омега");
    //b.addTransaction(g);
   // bool ok = b.addTransaction(g);
   //std::cout << "Transaction added: " << ok << std::endl;
    //auto trwe = std::chrono::system_clock::now();
    //std::cout<<trwe;
    /*auto qwer = b.testSelect();
    for(auto i:qwer){
        std::cout<<i;
    }
    auto f = std::chrono::system_clock::now() - std::chrono::days(1);
    auto t =std::chrono::system_clock::now();

    Analytics an;

    auto anali = an.getWeekSum(b);
    for(auto i:anali){
        std::cout<<i.first<<" "<<i.second<<"\n";
    }

    //b.fres();
    b.close();
    return 0;*/

}
