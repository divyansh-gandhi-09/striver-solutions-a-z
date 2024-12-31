#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login) {
    ui->setupUi(this);
}

Login::~Login() {
    delete ui;
}

void Login::on_loginButton_clicked() {
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    if (db.authenticateUser(username, password)) {
        MainWindow *mainWindow = new MainWindow(username);
        mainWindow->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void Login::on_signupButton_clicked() {
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    if (db.createUser(username, password)) {
        QMessageBox::information(this, "Signup Successful", "User created successfully.");
    } else {
        QMessageBox::warning(this, "Signup Failed", "User already exists.");
    }
}
