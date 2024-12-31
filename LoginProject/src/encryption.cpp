#include "encryption.h"
#include <QCryptographicHash>
#include <QByteArray>

QString Encryption::encrypt(const QString &plaintext, const QString &key) {
    QByteArray data = plaintext.toUtf8();
    QByteArray hashedKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Sha256);
    for (int i = 0; i < data.size(); ++i) {
        data[i] = data[i] ^ hashedKey[i % hashedKey.size()];
    }
    return data.toBase64();
}

QString Encryption::decrypt(const QString &ciphertext, const QString &key) {
    QByteArray data = QByteArray::fromBase64(ciphertext.toUtf8());
    QByteArray hashedKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Sha256);
    for (int i = 0; i < data.size(); ++i) {
        data[i] = data[i] ^ hashedKey[i % hashedKey.size()];
    }
    return QString::fromUtf8(data);
}
