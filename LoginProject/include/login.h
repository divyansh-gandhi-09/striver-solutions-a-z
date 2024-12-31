#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include "database.h"

namespace Ui {
class Login;
}

class Login : public QWidget {
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_loginButton_clicked();
    void on_signupButton_clicked();

private:
    Ui::Login *ui;
    Database db;
};

#endif
