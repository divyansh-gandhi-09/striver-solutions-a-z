#include <QApplication>
#include <QMainWindow>
#include "chessboard.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow window;
    ChessBoard *board = new ChessBoard(&window);
    window.setCentralWidget(board);
    window.setFixedSize(ChessConstants::WINDOW_SIZE, ChessConstants::WINDOW_SIZE);
    window.show();

    return app.exec();
}
