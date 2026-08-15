#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QString>
#include <QVector>
#include "user.h"
#include "file.h"
class fileManager
{
public:
    fileManager();
    bool upload(const user&,const file&);
    bool download(const user&,const file&);
    bool send(const user&,const user&,const file&);
    bool move(const user&,const file&,const QString&);
    bool copy(const user&,const file&,const QString&);
    bool delete_file(const user&,const file&);
    QVector<file> get_files(const user&)const;
};

#endif // FILEMANAGER_H
