#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(const QString &username, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
    Database db;
    QString username;
};

#endif
