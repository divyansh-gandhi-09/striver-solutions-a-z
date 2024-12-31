#include "database.h"
#include <QSqlError>
#include <QCryptographicHash>

Database::Database() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("password_storage.db");

    if (!db.open()) {
        qFatal("Failed to open database.");
    }
    initialize();
}

void Database::initialize() {
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users (username TEXT PRIMARY KEY, password TEXT)");
    query.exec("CREATE TABLE IF NOT EXISTS passwords (username TEXT, service TEXT, encrypted_password TEXT)");
}

bool Database::createUser(const QString &username, const QString &password) {
    QSqlQuery query;
    QString hashedPassword = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
    query.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(hashedPassword);
    return query.exec();
}

bool Database::authenticateUser(const QString &username, const QString &password) {
    QSqlQuery query;
    QString hashedPassword = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
    query.prepare("SELECT username FROM users WHERE username = ? AND password = ?");
    query.addBindValue(username);
    query.addBindValue(hashedPassword);
    return query.exec() && query.next();
}

bool Database::savePassword(const QString &username, const QString &service, const QString &encryptedPassword) {
    QSqlQuery query;
    query.prepare("INSERT INTO passwords (username, service, encrypted_password) VALUES (?, ?, ?)");
    query.addBindValue(username);
    query.addBindValue(service);
    query.addBindValue(encryptedPassword);
    return query.exec();
}
