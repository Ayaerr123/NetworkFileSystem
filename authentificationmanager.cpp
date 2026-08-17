#include "authentificationmanager.h"
#include<QCryptographicHash>
authentificationManager::authentificationManager(DataManager& d):data(d){}
bool authentificationManager::register_user(QString name, QString password, QString role){
    user newUser(-1,name,password,role);
    return data.save_user(newUser);
}
bool authentificationManager::login(QString name, QString pw){
    QString hashed=QCryptographicHash::hash(pw.toUtf8(),QCryptographicHash::Sha256).toHex();
    user foundUser;
    bool result= data.get_user(name,foundUser);
    if(!result)
        return false;
    return foundUser.get_password()==hashed;
}
bool authentificationManager::is_admin(int id){
    user u;
    bool result=data.get_user(id,u);
    if(!result)
        return false;
    return u.get_role()=="admin";
}
bool authentificationManager::is_client(int id){
    user u;
    bool result=data.get_user(id,u);
    if(!result)
        return false;
    return u.get_role()=="client";
}
