#include <QSqlQuery>
#include <QSqlError>
#include "datamanager.h"
#include <QCryptographicHash>

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
bool DataManager::get_user(QString name, user &out){
    QSqlQuery query(db);
    query.prepare("SELECT id,username,password_hash,role FROM users WHERE username=:name");
    query.bindValue(":name",name);
    bool result=query.exec();
    if(!result){
        qDebug()<<"get user failed "<<query.lastError().text();
        return false;
    }
    if(query.next()){
        out.set_user_id(query.value("id").toInt());
        out.set_username(query.value("username").toString());
        out.set_role(query.value("role").toString());
        out.set_password(query.value("password_hash").toString());
        return true;
    }
    else
        return false;
}
bool DataManager::get_user(int id, user &out){
    QSqlQuery query(db);
    query.prepare("SELECT id,username,password_hash,role FROM users WHERE id=:id");
    query.bindValue(":id",id);
    bool result=query.exec();
    if(!result){
        qDebug()<<"get user failed "<<query.lastError().text();
        return false;
    }
    if(query.next()){
        out.set_user_id(query.value("id").toInt());
        out.set_username(query.value("username").toString());
        out.set_role(query.value("role").toString());
        out.set_password(query.value("password_hash").toString());
        return true;
    }
    else
        return false;
}
bool DataManager::save_user(const user & u){
    QSqlQuery query(db);
    query.prepare("INSERT INTO users (username,password_hash,role)"
                  "VALUES(:username,:password_hash,:role) "
                  "ON CONFLICT(username) DO UPDATE SET "
                  "password_hash=:password_hash,"
                  "role=:role"
                  "");
    query.bindValue(":username",u.get_username());
    QString hashed=QCryptographicHash::hash(u.get_password().toUtf8(),QCryptographicHash::Sha256).toHex();
    query.bindValue(":password_hash",hashed);
    query.bindValue(":role",u.get_role());
    bool result=query.exec();
    if(!result){
        qDebug()<<"save user failed "<<query.lastError().text();
        return false;
    }
    return true;
}
bool DataManager::save_file(const file & f){
    QSqlQuery query(db);
    query.prepare("INSERT INTO files (filename,path,owner_id,size)"
                  "VALUES(:filename,:path,:owner_id,:size"
                  "");
    query.bindValue(":filename",f.get_filename());
    query.bindValue(":path",f.get_path());
    query.bindValue(":owner_id",f.get_owner_id());
    bool result=query.exec();
    if(!result){
        qDebug()<<"save file failed "<<query.lastError().text();
        return false;
    }
    return true;
}
QVector<file> DataManager::get_files(int userId) const{
    QSqlQuery query(db);
    query.prepare("SELECT id,filename,path,owner_id,size FROM files WHERE owner_id=:userId");
    query.bindValue(":userId",userId);
    bool result=query.exec();
    if(!result){
        qDebug()<<"get files saved"<<query.lastError().text();
        return QVector<file>();
    }
    QVector<file> files;
    while(query.next()){
        file f;
        f(query.value("id").toInt(),
          query.value("filename").toString(),
          query.value("path").toString(),
          query.value("owner_id").toInt(),
          query.value("size").toLongLong());
        files.append(f);
    }
    return files;
}
bool DataManager::delete_file(int fileId){
    QSqlQuery query(db);
    query.prepare("DELETE FROM files WHERE id=:fileId");
    query.bindValue(":fileId",fileId);
    bool result=query.exec();
    if(!result){
        qDebug()<<"delete file failed "<<query.lastError().text();
        return false;
    }
    return true;
}
bool DataManager::delete_file(QString name){
    QSqlQuery query(db);
    query.prepare("DELETE FROM files WHERE filename=:name");
    query.bindValue(":fileId",fileId);
    bool result=query.exec();
    if(!result){
        qDebug()<<"delete file failed "<<query.lastError().text();
        return false;
    }
    return true;
}
bool DataManager::delete_file(QString path){
    QSqlQuery query(db);
    query.prepare("DELETE FROM files WHERE path=:path");
    query.bindValue(":path",path);
    bool result=query.exec();
    if(!result){
        qDebug()<<"delete file failed "<<query.lastError().text();
        return false;
    }
    return true;
}