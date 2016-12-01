#include "piece.hpp"

#include <iostream>

Piece::Piece()
    : type_(Type::EMPTY) {}

void Piece::CreateSprite(Type type, Color color, sf::Texture* texture) {
    sprite_.setTexture(*texture);
    type_ = type;
    color_ = color;
}

void Piece::SetPosition(float x, float y) {
    sprite_.setPosition(x, y);
}


