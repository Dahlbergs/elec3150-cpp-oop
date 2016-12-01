#include "tile.hpp"

TextureManager Tile::texture_manager_ = TextureManager();

Tile::Tile()
    : pos_x_(0),
      pos_y_(0),
      type_(Type::EMPTY),
      color_(Color::NONE) {}

Tile::Tile(int pos_x, int pos_y)
    : pos_x_(pos_x),
      pos_y_(pos_y),
      type_(Type::EMPTY),
      color_(Color::NONE) {}

Tile::~Tile() {}

void Tile::SetTileType(Type type, Color color) {
    type_ = type;
    color_ = color;
    sprite_.setTexture(texture_manager_.GetTexture(type, color));
}

void Tile::SetEmpty() {
    type_ = Type::EMPTY;
    color_ = Color::NONE;
    sprite_.setTexture(texture_manager_.GetEmptyTexture());
}
void Tile::SetImpassable() {
    type_ = Type::IMPASSABLE;
    color_ = Color::NONE;
    sprite_.setTexture(texture_manager_.GetImpassableTexture());
}

void Tile::SetPosition(int x, int y) {
    pos_x_ = x;
    pos_y_ = y;
    sprite_.setPosition(static_cast<float>(x), static_cast<float>(y));
}

sf::Vector2i Tile::GetPosition() {
    return sf::Vector2i(sprite_.getPosition());
}

bool Tile::IsEmpty() {
    return type_ == Type::EMPTY;
}
