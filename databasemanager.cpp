#include "databasemanager.h"

DataBaseManager::DataBaseManager()
    : dbPath(),connectName("coinlog_connect"), db()
{

}

// открытие бд
void DataBaseManager::open(std::string path){

    // 1) Подготовка пути
    QString qpath;
    if(!path.empty()){
        // если путь передали в аргументе, используем его
        qpath = QString::fromStdString(path);
    } else{
        // если путь не передали, формируем дефолтный путь:
        // папка приложения + /bd/Tran.sqbpro
        qpath = QCoreApplication::applicationDirPath()+QDir::separator() + "bd" + QDir::separator()+"Tran.sqbpro";
    }

    // 2) Если уже есть соединение с таким именем — корректно закрыть и удалить его
    if(QSqlDatabase::contains(connectName)){
        QSqlDatabase old = QSqlDatabase::database(connectName);
        if(old.isOpen()) old.close();
        QSqlDatabase::removeDatabase(connectName);
    }

    // 3) Создать новое подключение и сохранить в поле db
    db = QSqlDatabase::addDatabase("QSQLITE", connectName);
    db.setDatabaseName(qpath);

    // 4) Открыть базу и проверить результат
    if(!db.open()){
        qWarning()<<"DB open error:"<<db.lastError().text();
        return;
    }

    // 5) Сохранить путь в поле
    dbPath = qpath;

}

// закрытие бд
void DataBaseManager::close(){
    if(!db.isValid()) return;

    QString connect = db.connectionName();
    if(db.isOpen()) db.close();

    db=QSqlDatabase();

    QSqlDatabase::removeDatabase(connect);
}

// добавить транзакцию в бд
bool DataBaseManager::addTransaction(const Transaction &t){

}

//выборка транзакций
std::vector<Transaction> DataBaseManager::queryTransaction(std::chrono::system_clock::time_point from, std::chrono::system_clock::time_point to ){

}

//удалить старые записи
void DataBaseManager::pruneOlderThan(std::chrono::system_clock::time_point t){

}
