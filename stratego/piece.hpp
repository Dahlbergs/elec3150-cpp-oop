#pragma once

#include <SFML/Graphics.hpp>

class Piece {
public:
    enum class Type : uint8_t  {
        EMPTY = 0x00,
        MARSHAL = 0x01,
        GENERAL = 0x02,
        COLONEL = 0x03,
        MAJOR = 0x04,
        CAPTAIN = 0x05,
        LIEUTENANT = 0x06,
        SERGEANT = 0x07,
        SAPPER = 0x08,
        SCOUT = 0x09,
        SPY = 0x0A,
        BOMB = 0x0B,
        FLAG = 0x0C,
    };

    enum class Color : uint8_t {
        NONE = 0x00,
        BLUE = 0x01,
        RED = 0x02
    };

    Piece();
    Piece(Type type, Color color);

    void CreateSprite(Type type, Color color);

    sf::Sprite GetSprite();

    void SetPosition(float x, float y);
    int GetPositionX();
    int GetPositionY();
    sf::Sprite sprite_;

private:
    Type type_;
    sf::Texture texture_;

    int pos_x_;
    int pos_y_;
};
