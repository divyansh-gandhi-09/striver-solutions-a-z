#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <vector>

class ChessBoard : public QWidget {
    Q_OBJECT

public:
    explicit ChessBoard(QWidget *parent = nullptr);

private:
    std::vector<std::vector<QPushButton*>> squares; // 8x8 grid of squares
    QPushButton *selectedPiece; // Currently selected square
    QGridLayout *layout; // Layout for the chessboard
    std::vector<std::vector<char>> initialPosition; // Initial chessboard state

    void initializeBoard(); // Create chessboard layout
    void setupInitialPosition(); // Set up initial positions of pieces
    QString getPieceSymbol(char piece); // Map piece character to symbol

private slots:
    void squareClicked(); // Handle square clicks
};

#endif
