#include <QApplication>
#include "login.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Login loginWindow;
    loginWindow.show();

    return app.exec();
}
