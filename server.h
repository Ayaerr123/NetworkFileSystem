#ifndef SERVER_H
#define SERVER_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include "clienthandler.h"
class server
{
    SOCKET ssocket;//server socket
    QVector<ClientHandler*> clients;
public:
    server();
    void start();
    void accept_client();
    void close();
};

#endif // SERVER_H
