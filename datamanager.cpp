#include <QSqlQuery>
#include <QSqlError>
#include "datamanager.h"

DataManager::DataManager() {}
bool DataManager::connect(){
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("DFSS.db");
    bool ok=db.open();
    if(ok){
        QSqlQuery query(db);
        bool userok=query.exec("CREATE TABLE IF NOT EXISTS users("
                                 "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                 "username TEXT UNIQUE NOT NULL, "
                                 "password_hash TEXT NOT NULL, "
                                 "role TEXT NOT NULL"
                                 ")");
        bool fileok=query.exec("CREATE TABLE IF NOT EXISTS files("
                                 "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                 "filename TEXT NOT NULL, "
                                 "path TEXT NOT NULL, "
                                 "owner_id INTEGER NOT NULL, "
                                 "size INTEGER NOT NULL"
                                 ")");
        if(userok&&fileok)
            return true;
    }
    else
        return false;
}
