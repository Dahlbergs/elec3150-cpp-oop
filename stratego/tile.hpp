#pragma once

#include "piece.hpp"

class Tile {
public:
    Tile();
    Tile(int x, int y);
    Tile(Piece *piece);
    Tile(Piece *piece, int x, int y);

    ~Tile();

    /* Setters */
    void SetPiece(Piece *piece) { piece_ = piece; }
    void SetPosition(int x, int y);

    /* Getters */
    Piece* GetPiece() { return piece_; }
    int GetPositionX() { return pos_x_; }
    int GetPositionY() { return pos_y_; }

private:
    Piece* piece_;
    int pos_x_;
    int pos_y_;
};

