#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#include <QObject>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <QVector>
#include "clienthandler"

class socketServer
{
    Q_OBJECT
    SOCKET socket;
vector<Clie

public:
    socketServer();
};

#endif // SOCKETSERVER_H
