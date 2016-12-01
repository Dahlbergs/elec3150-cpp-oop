#pragma once

#include <SFML/Graphics.hpp>
#include "texture_manager.hpp"

class Tile {
public:
    Tile();
    Tile(int x, int y);

    ~Tile();

    /* Setters */
    void SetTileType(Type type, Color color);
    void SetWindow(sf::Window *window) { window_ = window; }
    void SetPosition(int x, int y);

    void SetEmpty();
    void SetImpassable();

    bool IsEmpty();

    /* Getters */
    sf::Sprite GetSprite() { return sprite_; }
    sf::Vector2i GetPosition();
    int GetPosX() { return pos_x_; }
    int GetPosY() { return pos_y_; }

    Type GetType() { return type_; }
    Color GetColor() { return color_; }

private:
    sf::Window* window_;
    static TextureManager texture_manager_;

    int pos_x_;
    int pos_y_;
    Type type_;
    Color color_;
    sf::Sprite sprite_;
};
