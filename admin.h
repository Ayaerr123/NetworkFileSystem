#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>
#include <QString>
#include "user.h"

class admin : public user
{
    Q_OBJECT
public:
    admin();
    void view_logs();
    void view_history();
    void view_activity(const user&);
    void creat_user(int,QString,QString,QString);
    void delete_user(user);
    void reset_password(user);
};

#endif // ADMIN_H
