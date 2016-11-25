#include "piece.hpp"

#include <iostream>

Piece::Piece()
    : type_(Type::EMPTY) {
    if (!texture_.loadFromFile("assets/empty.png")) {
        std::cout << "Could not load empty texture" << std::endl;
    }

    sprite_.setTexture(texture_);
}

Piece::Piece(Type type, Color color)
    : type_(type) {
    CreateSprite(type, color);
}

sf::Sprite Piece::GetSprite() {
    return sprite_;
}

void Piece::CreateSprite(Type type, Color color) {
    std::string path = "";
    std::string team = "";

    if (color == Color::RED) {
        team = "_red";
    } else if (color == Color::BLUE) {
        team = "_blue";
    }

    switch (type) {
    case Type::EMPTY:
        path = "empty";
        break;
    case Type::MARSHAL:
        path = "one";
        break;
    case Type::GENERAL:
        path = "two";
        break;
    case Type::COLONEL:
        path = "three";
        break;
    case Type::MAJOR:
        path = "four";
        break;
    case Type::CAPTAIN:
        path = "five";
        break;
    case Type::LIEUTENANT:
        path = "six";
        break;
    case Type::SERGEANT:
        path = "seven";
        break;
    case Type::SAPPER:
        path = "eight";
        break;
    case Type::SCOUT:
        path = "nine";
        break;
    case Type::SPY:
        path = "spy";
        break;
    case Type::BOMB:
        path = "bomb";
        break;
    case Type::FLAG:
        path = "flag";
        break;
    }

    if (!texture_.loadFromFile("assets/" + path + team + ".png")) {
        std::cout << "Failed to load texture" << std::endl;
    }

    sprite_.setTexture(texture_);
}

void Piece::SetPosition(float x, float y) {
    pos_x_ = x;
    pos_y_ = y;
    sprite_.setPosition(x, y);
}

int Piece::GetPositionX() {
    return pos_x_;
}

int Piece::GetPositionY() {
    return pos_y_;
}


