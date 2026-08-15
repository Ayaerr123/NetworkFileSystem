#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <QString>
#include <winsock2.h>
#include <ws2tcpip.h>

class socketClient
{
    SOCKET csocket;//client socket
public:
    socketClient();
    ~socketClient();
    bool connect(int port,QString ip);
    void send_data(QString);
    QString receive();
    void close();
};

#endif // SOCKETCLIENT_H
