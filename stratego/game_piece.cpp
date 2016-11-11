#include "game_piece.hpp"

#include <iostream>

GamePiece::GamePiece(Type type, Color color) {
    std::string path = color == BLUE ? "_blue.png": "_red.png";

    switch(type) {
    case SPY:
        CreateSpriteFromFile("spy" + path);
        break;
    case MARSHALL:
        CreateSpriteFromFile("one" + path);
        break;
    case GENERAL:
        CreateSpriteFromFile("two" + path);
        break;
    case COLONEL:
        CreateSpriteFromFile("three" + path);
        break;
    case MAJOR:
        CreateSpriteFromFile("four" + path);
        break;
    case CAPTAIN:
        CreateSpriteFromFile("five" + path);
        break;
    case LIEUTENANT:
        CreateSpriteFromFile("six" + path);
        break;
    case SERGEANT:
        CreateSpriteFromFile("seven" + path);
        break;
    case SAPPER:
        CreateSpriteFromFile("eight" + path);
        break;
    case SCOUT:
        CreateSpriteFromFile("nine" + path);
        break;
    case BOMB:
        CreateSpriteFromFile("bomb" + path);
        break;
    case FLAG:
        CreateSpriteFromFile("flag" + path);
        break;
    default:
        std::cout << "Invalid type" << std::endl;
    }
}

void GamePiece::CreateSpriteFromFile(std::string path) {
    if (!texture.loadFromFile("assets/" + path)) {
        std::cout << "Error in creating sprite from path:" << path << std::endl;
    }

    sprite.setTexture(texture);
}

sf::Sprite GamePiece::GetSprite() {
    return sprite;
}

int GamePiece::getPositionX() {
    return pos_x;
}

int GamePiece::getPositionY() {
    return pos_y;
}

void GamePiece::setPositionY(int y) {
    if (y < 0 && y > 10) {
        std::cout << "Invalid position" << std::endl;
        pos_y = -1;
    } else {
        pos_y = y;
    }
}

void GamePiece::setPositionX(int x) {
    if (x < 0 && x > 10) {
        std::cout << "Invalid position" << std::endl;
        pos_x = -1;
    } else {
        pos_x = x;
    }
}
