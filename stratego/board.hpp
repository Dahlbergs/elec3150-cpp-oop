#pragma once

#include <SFML/Graphics.hpp>

#include "tile.hpp"

class Board {
public:
    Board(int height, int width, sf::RenderWindow *window);
    ~Board();

    sf::Sprite GetSprite();

    void GetPieceAtPosition(int x, int y);
    void PlacePieceAtPosition(int x, int y);
    void MoveSelectedPiece();

    void Draw();

private:
    int map_width_;
    int map_height_;

    sf::RenderWindow *window_;

    Tile map_[10][10];
    Piece* mouse_selected_;

    sf::Texture texture_;
    sf::Sprite sprite_;
};

