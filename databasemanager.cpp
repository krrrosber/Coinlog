#include "databasemanager.h"

DataBaseManager::DataBaseManager()
    : dbPath(),connectName("coinlog_connect"), db()
{

}

// открытие бд
void DataBaseManager::open(QString path){

    // 1) Подготовка пути
    QString qpath;
    if(!path.isEmpty()){
        // если путь передали в аргументе, используем его
        qpath = path;
    } else{
        // если путь не передали, формируем дефолтный путь:
        // папка приложения + /bd/Tran.sqbpro
        qpath = QCoreApplication::applicationDirPath()+QDir::separator() + "bd" + QDir::separator()+"Tran.db";
    }

    qDebug() << "Trying DB path:" << qpath;
    qDebug() << "Exists? " << QFile::exists(qpath);
    qDebug() << "Dir exists? " << QDir(QFileInfo(qpath).path()).exists();


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
    qDebug() << "Connection name:" << db.connectionName();
    qDebug() << "db.isValid():" << db.isValid();
    qDebug() << "db.isOpen():" << db.isOpen();


    if(!db.isOpen() || !db.isValid()) {
        qWarning() << "DB is not open!";
        return false;
    }

    QSqlQuery query(db);
    if(!query.prepare("INSERT INTO transactions (id, Time, Price, idCategory, note) VALUES (?, ?, ?, ?, ?)")) {
        qWarning() << "Prepare failed:" << query.lastError().text();
        return false;
    }

    qint64 id = static_cast<qint64>(t.id);
    qint64 ms = std::chrono::duration_cast<std::chrono::milliseconds>(t.timestamp.time_since_epoch()).count();
    qint64 amount = static_cast<qint64>(t.amount);
    int cat = t.categoryId;
    QString note = QString::fromStdString(t.note);

    query.bindValue(0, id);
    query.bindValue(1, ms);
    query.bindValue(2, amount);
    query.bindValue(3, cat);
    query.bindValue(4, note);

    if(!query.exec()) {
        qWarning() << "Insert failed:" << query.lastError().text();
        return false;
    }

    return true;
}



//выборка транзакций
std::vector<Transaction> DataBaseManager::queryTransaction(std::chrono::system_clock::time_point from, std::chrono::system_clock::time_point to ){

}

//удалить старые записи
void DataBaseManager::pruneOlderThan(std::chrono::system_clock::time_point t){

}
