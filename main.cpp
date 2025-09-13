#include <QCoreApplication>
#include <qapplication.h>
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
    Transaction g(100,std::chrono::system_clock::now(),962750,1,"Пятерочка");
    bool ok = b.addTransaction(g);
    b.close();
    return 0;*/

}
