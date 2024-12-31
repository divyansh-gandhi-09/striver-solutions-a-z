#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <QString>

class Encryption {
public:
    static QString encrypt(const QString &plaintext, const QString &key);
    static QString decrypt(const QString &ciphertext, const QString &key);
};

#endif
