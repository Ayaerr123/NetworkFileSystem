#ifndef CLIENT_H
#define CLIENT_H

#include "user.h"
#include "socketclient.h"

class client
{
    socketClient socket;
    user current;
public:
    client();
    void upload_file(QString path);
    void download_file(QString filename);
    void move_file(QString filename,QString destination);
    void copy_file(QString filename,QString destination);
    void send_file(QString filename,QString destination);
    void delete_file();
};

#endif // CLIENT_H
