#include<QString>
#include
#include "file.h"
file::file():file_id(-1),filename(""),path(""),owner_id(-1),size(0) {}
file::file(int id, QString name, QString path, int owner, long size):
    file_id(id),filename(name),path(path),owner_id(owner),size(size){}
QString file::get_filename()const{return filename;}
int file::get_file_id()const{return file_id;}
int file::get_owner_id()const{return owner_id;}
QString file::get_path()const{return path;}
long file::get_size()const{return size;}
void file::set_filename(QString name){filename=name;}
void file::set_file_id(int id){file_id=id;}
void file::set_owner(int oid){owner_id=oid;}
void file::set_path(QString p){path=p;}
void file::set_size(long s){size=s;}
void file::show_infos()const{}