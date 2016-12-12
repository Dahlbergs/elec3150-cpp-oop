#pragma once

#include <SFML/Graphics.hpp>

#include "tile.hpp"
#include "button_tile.hpp"

class Board {
public:
    enum class GameState {
        SETUP,
        PLAYING,
        PLAYER_TURN,
        COMPUTER_TURN,
        WINNER_CONFIRMED
    };

    GameState game_state_;

    Board(int height, int width, sf::RenderWindow *window);
    ~Board();

    sf::Sprite GetSprite();

    /* Utility functions */
    Tile GetTileAtMouse();
    ButtonTile ClickButtonAtPosition();

    /* Event triggered functions */
    void SelectPieceAtPosition();
    void MoveSelectedPiece();
    void CheckValidMovement();

    /* Movement handlers */
    void SwapSelectedTile();
    void ResetSelectedTile();
    void ReplaceSelectedTile();
    void KillSelectedTile();
    void KillAndResetTile();

    /* Game state based updaters */
    void SetupCompareTiles();
    void CompareTiles();

    /* Sprite drawing subroutine */
    void Draw();

private:
    /* Sprite initialization functions */
    void InitializeBlue();
    void InitializeRed();
    void InitializeImpassable();
    void InitializeButtons();

    /* Private member data */
    int map_width_;
    int map_height_;

    sf::RenderWindow *window_;

    sf::Vector2i mouse_selected_origin_position_;

    Tile mouse_selected_copy_;

    Tile* mouse_selected_;
    Tile* mouse_selected_origin_;

    Tile map_[10][10];

    ButtonTile button_menu_[1];

    sf::Texture texture_;
    sf::Sprite sprite_;
};

