#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QString>

class file
{
    Q_OBJECT
    int file_id;
    QString filename;
    QString path;
    int owner_id;
    long size;
public:
    file();
    file(int id,QString name,QString path,int owner,long size):
        file_id(id),filename(name),path(path),owner_id(owner),size(size){}
    void show_infos()const;
    void set_file_id(int);
    void set_filename(QString);
    void set_path(QString);
    void set_owner(int);
    void set_size(long);
    int get_file_id()const;
    QString get_filename()const;
    QString get_path()const;
    int get_owner_id()const;
    long get_size()const;
};

#endif // FILE_H
