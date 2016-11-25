#include "tile.hpp"

Tile::Tile()
    : piece_(new Piece()),
      pos_x_(0),
      pos_y_(0) {}

Tile::Tile(int pos_x, int pos_y)
    : piece_(new Piece()),
      pos_x_(pos_x),
      pos_y_(pos_y) {}

Tile::Tile(Piece *piece, int pos_x, int pos_y)
    : piece_(piece),
      pos_x_(pos_x),
      pos_y_(pos_y) {}


Tile::~Tile() {
    delete piece_;
}

void Tile::SetPosition(int x, int y) {
    pos_x_ = x;
    pos_y_ = y;

    piece_->SetPosition(static_cast<float>(x),
                       static_cast<float>(y));
}
