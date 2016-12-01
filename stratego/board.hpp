#pragma once

#include <SFML/Graphics.hpp>

#include "tile.hpp"

class Board {
public:
    Board(int height, int width, sf::RenderWindow *window);
    ~Board();

    sf::Sprite GetSprite();

    Tile GetTileAtMouse();

    void SelectPieceAtPosition();
    void MoveSelectedPiece();

    void SwapSelectedTile();
    void ResetSelectedTile();
    void ReplaceSelectedTile();
    void KillSelectedTile();
    void KillAndResetTile();
    
    void CompareTiles();
    void Draw();

private:
    void InitializeBlue();
    void InitializeRed();
    void InitializeImpassable();

    int map_width_;
    int map_height_;

    sf::RenderWindow *window_;

    sf::Vector2i mouse_selected_origin_position_;

    Tile mouse_selected_copy_;

    Tile* mouse_selected_;
    Tile* mouse_selected_origin_;

    Tile map_[10][10];

    sf::Texture texture_;
    sf::Sprite sprite_;
};

