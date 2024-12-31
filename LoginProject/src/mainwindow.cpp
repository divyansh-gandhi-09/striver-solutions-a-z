#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "encryption.h"
#include <QMessageBox>

MainWindow::MainWindow(const QString &username, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    username(username) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_saveButton_clicked() {
    QString service = ui->serviceLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString encryptedPassword = Encryption::encrypt(password, username);
    if (db.savePassword(username, service, encryptedPassword)) {
        QMessageBox::information(this, "Success", "Password saved.");
    } else {
        QMessageBox::warning(this, "Error", "Failed to save password.");
    }
}
