#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

class Database {
public:
    Database();
    bool createUser(const QString &username, const QString &password);
    bool authenticateUser(const QString &username, const QString &password);
    bool savePassword(const QString &username, const QString &service, const QString &encryptedPassword);

private:
    QSqlDatabase db;
    void initialize();
};

#endif
