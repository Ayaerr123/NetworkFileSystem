#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QVector>
#include <QString>
#include <QSqlDatabase>
#include "user.h"
#include "file.h"
//only communicate with sqlite
class DataManager
{
    QSqlDatabase db;
public:
    DataManager();
    bool connect();
    user get_user(QString name,user& out);
    bool save_user(const user&);
    bool save_file(const file&);
    QVector<file> get_files(int)const;//user files int->user id
    bool delete_file(int);//file id
};

#endif // DATAMANAGER_H
