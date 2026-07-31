#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
class user
{
    Q_OBJECT
    int user_id;
    QString username;
    QString password;
    QString role;
   
public:
    user();
    virtual ~user()=default;
    bool login(QString name,QString password);
    void logout();
    user(int id,QString name,QString pw,QString role):
        user_id(id),username(name),password(pw),role(role){}
    void show_infos()const;
    void set_user_id(int);
    void set_username(QString);
    void set_password(QString);
    void set_role(QString);
    int get_user_id()const;
    QString get_username()const;
    QString get_password()const;
    QString get_role()const;
};

#endif // USER_H
