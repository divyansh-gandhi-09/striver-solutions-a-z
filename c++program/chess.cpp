#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

// Chessboard dimensions
const int BOARD_SIZE = 8;
const int TILE_SIZE = 100;

// Initialize pieces with their Unicode symbols
std::string initialBoard[8] = {
    "rnbqkbnr",
    "pppppppp",
    "........",
    "........",
    "........",
    "........",
    "PPPPPPPP",
    "RNBQKBNR"
};

// Helper to map piece characters to textures
std::map<char, sf::Texture> loadPieceTextures() {
    std::map<char, sf::Texture> textures;
    const std::map<char, std::string> pieceFiles = {
        {'P', "white_pawn.png"}, {'R', "white_rook.png"}, {'N', "white_knight.png"},
        {'B', "white_bishop.png"}, {'Q', "white_queen.png"}, {'K', "white_king.png"},
        {'p', "black_pawn.png"}, {'r', "black_rook.png"}, {'n', "black_knight.png"},
        {'b', "black_bishop.png"}, {'q', "black_queen.png"}, {'k', "black_king.png"}
    };

    for (const auto& [piece, filename] : pieceFiles) {
        sf::Texture texture;
        if (!texture.loadFromFile("assets/" + filename)) {
            std::cerr << "Failed to load " << filename << std::endl;
        }
        textures[piece] = texture;
    }
    return textures;
}

// Draw the chessboard
void drawBoard(sf::RenderWindow& window) {
    sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            tile.setPosition(col * TILE_SIZE, row * TILE_SIZE);
            tile.setFillColor((row + col) % 2 == 0 ? sf::Color::White : sf::Color(100, 100, 100));
            window.draw(tile);
        }
    }
}

// Render pieces on the board
void drawPieces(sf::RenderWindow& window, const std::string board[8], const std::map<char, sf::Texture>& textures) {
    sf::Sprite sprite;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            char piece = board[row][col];
            if (piece != '.') {
                sprite.setTexture(textures.at(piece));
                sprite.setPosition(col * TILE_SIZE, row * TILE_SIZE);
                window.draw(sprite);
            }
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(BOARD_SIZE * TILE_SIZE, BOARD_SIZE * TILE_SIZE), "C++ Chess");

    // Load textures for chess pieces
    auto textures = loadPieceTextures();

    // Game state variables
    std::string board[8];
    std::copy(std::begin(initialBoard), std::end(initialBoard), std::begin(board));

    sf::Vector2i selected(-1, -1);  // No piece selected initially

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int col = event.mouseButton.x / TILE_SIZE;
                    int row = event.mouseButton.y / TILE_SIZE;

                    if (selected == sf::Vector2i(-1, -1)) {
                        // Select piece
                        if (board[row][col] != '.') {
                            selected = sf::Vector2i(col, row);
                        }
                    } else {
                        // Move piece
                        int srcCol = selected.x, srcRow = selected.y;
                        board[row][col] = board[srcRow][srcCol];
                        board[srcRow][srcCol] = '.';
                        selected = sf::Vector2i(-1, -1);
                    }
                }
            }
        }

        window.clear();
        drawBoard(window);
        drawPieces(window, board, textures);
        window.display();
    }

    return 0;
}
