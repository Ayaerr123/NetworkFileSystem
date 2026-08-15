#ifndef AUTHENTIFICATIONMANAGER_H
#define AUTHENTIFICATIONMANAGER_H

#include <QString>
#include "datamanager.h"

class authentificationManager
{
    DataManager& data;
public:
    explicit authentificationManager(DataManager&);
    bool login(QString,QString);//name password
    bool register_user(QString,QString,QString);//name password role
    bool is_admin(int);//check if admin id
    bool is_client(int);//check if client id
    authentificationManager();
};

#endif // AUTHENTIFICATIONMANAGER_H
