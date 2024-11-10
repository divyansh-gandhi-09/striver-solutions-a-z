#include "chessboard.h"
#include <QtDebug>
#include "constants.h"

ChessBoard::ChessBoard(QWidget *parent) : QWidget(parent), selectedPiece(nullptr) {
    layout = new QGridLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    initialPosition = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    initializeBoard();
    setupInitialPosition();
}

void ChessBoard::initializeBoard() {
    squares.resize(ChessConstants::BOARD_SIZE, std::vector<QPushButton*>(ChessConstants::BOARD_SIZE));

    for (int row = 0; row < ChessConstants::BOARD_SIZE; row++) {
        for (int col = 0; col < ChessConstants::BOARD_SIZE; col++) {
            QPushButton *square = new QPushButton(this);
            square->setFixedSize(ChessConstants::SQUARE_SIZE, ChessConstants::SQUARE_SIZE);

            square->setProperty("row", row);
            square->setProperty("col", col);

            QString style = ((row + col) % 2 == 0) 
                ? "background-color: #EBECD0;" 
                : "background-color: #739552;";
            style += "font-size: 32px;";
            square->setStyleSheet(style);

            connect(square, &QPushButton::clicked, this, &ChessBoard::squareClicked);

            squares[row][col] = square;
            layout->addWidget(square, row, col);
        }
    }
}

void ChessBoard::setupInitialPosition() {
    for (int row = 0; row < ChessConstants::BOARD_SIZE; row++) {
        for (int col = 0; col < ChessConstants::BOARD_SIZE; col++) {
            char piece = initialPosition[row][col];
            squares[row][col]->setText(getPieceSymbol(piece));

            if (isupper(piece)) {
                squares[row][col]->setStyleSheet(squares[row][col]->styleSheet() + "color: black;");
            } else if (islower(piece)) {
                squares[row][col]->setStyleSheet(squares[row][col]->styleSheet() + "color: darkred;");
            }
        }
    }
}

QString ChessBoard::getPieceSymbol(char piece) {
    switch (piece) {
        case 'K': return "♔";
        case 'Q': return "♕";
        case 'R': return "♖";
        case 'B': return "♗";
        case 'N': return "♘";
        case 'P': return "♙";
        case 'k': return "♚";
        case 'q': return "♛";
        case 'r': return "♜";
        case 'b': return "♝";
        case 'n': return "♞";
        case 'p': return "♟";
        default: return "";
    }
}

void ChessBoard::squareClicked() {
    QPushButton *square = qobject_cast<QPushButton*>(sender());
    if (!square) return;

    if (!selectedPiece && !square->text().isEmpty()) {
        selectedPiece = square;
        square->setStyleSheet(square->styleSheet() + "background-color: #89CA43;");
    } else if (selectedPiece) {
        square->setText(selectedPiece->text());

        if (!square->text().isEmpty()) {
            square->setStyleSheet(square->styleSheet() +
                (square->text()[0].unicode() > 9812 ? "color: darkred;" : "color: black;"));
        }

        selectedPiece->setText("");

        int row = selectedPiece->property("row").toInt();
        int col = selectedPiece->property("col").toInt();
        QString style = ((row + col) % 2 == 0)
            ? "background-color: #EBECD0;" : "background-color: #739552;";
        style += "font-size: 32px;";
        selectedPiece->setStyleSheet(style);

        selectedPiece = nullptr;
    }
}
