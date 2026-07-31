#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QObject>
#include <QString>
#include "user.h"
#include <winsock2.h>
#include <ws2tcpip.h>
//handles one connected user so the server wouldnt get stuck while more users are connected at the same time
class ClientHandler
{
    Q_OBJECT
    SOCKET socket;
    user current;
public:
    explicit ClientHandler(SOCKET);
    ~ClientHandler();
    void handle_requests();
    void process_commands(QString command);
};

#endif // CLIENTHANDLER_H
