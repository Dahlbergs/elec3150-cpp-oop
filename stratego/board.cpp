#include "board.hpp"

#include <iostream>

/* @param height The height of the board in pixels
   @param width The width of the board in pixel */
Board::Board(int height, int width, sf::RenderWindow *window)
    : map_height_(height),
      map_width_(width),
      window_(window),
      mouse_selected_(nullptr) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map_[i][j].SetPosition((j * 64), (i * 64));
        }
    }

    map_[0][0].GetPiece()->CreateSprite(Piece::Type::MARSHAL, Piece::Color::BLUE);
    map_[0][1].GetPiece()->CreateSprite(Piece::Type::SAPPER, Piece::Color::BLUE);
    map_[1][0].GetPiece()->CreateSprite(Piece::Type::GENERAL, Piece::Color::BLUE);
    map_[1][1].GetPiece()->CreateSprite(Piece::Type::SCOUT, Piece::Color::BLUE);

    if(!texture_.loadFromFile("assets/map.png")) {
        std::cout << "Error loading map image" << std::endl;
    }

    sprite_.setTexture(texture_);
}

Board::~Board() {

}

sf::Sprite Board::GetSprite() {
    return sprite_;
}

void Board::GetPieceAtPosition(int x, int y) {
    std::cout << "GetPieceAtPosition" << std::endl;
    int pos_x = x / 64;
    int pos_y = y / 64;

    if (pos_x < 0 || pos_y < 0 ||
        pos_x > 9 || pos_y > 9) {
        std::cout << "No piece at mouse" << std::endl;
    } else {
        std::cout << "Mouse pos: (" << pos_x << ", " << pos_y << ")" << std::endl;
        mouse_selected_ = map_[pos_x][pos_y].GetPiece();
    }
}

void Board::MoveSelectedPiece() {
    std::cout << "MoveSelectedPiece" << std::endl;
    if (mouse_selected_ != nullptr) {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition();
        mouse_selected_->SetPosition(mouse_pos.x, mouse_pos.y);
    }
}

void Board::PlacePieceAtPosition(int x, int y) {
    int pos_x = x / 64;
    int pos_y = y / 64;

    if (pos_x < 0 || pos_y < 0 ||
        pos_x > 9 || pos_y > 9) {
        std::cout << "No piece at mouse" << std::endl;
    } else {
        if (mouse_selected_ != nullptr) {
            map_[pos_x][pos_y].SetPiece(mouse_selected_);
            mouse_selected_ = nullptr;
        }
    }
}

void Board::Draw() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            window_->draw(map_[i][j].GetPiece()->GetSprite());
        }
    }
}
