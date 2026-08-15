#include "user.h"

user::user():user_id(-1),username(""),password(""),role("") {}
user::user(int id,QString name,QString pw,QString role):
    user_id(id),username(name),password(pw),role(role){}
QString user::get_password()const{return password;}
QString user::get_role()const{return role;}
QString user::get_username()const{return username;}
int user::get_user_id()const{return user_id;}
void user::set_password(QString pw){password=pw;}
void user::set_role(QString r){role=r;}
void user::set_username(QString name){username=name;}
void user::set_user_id(int id){user_id=id;}