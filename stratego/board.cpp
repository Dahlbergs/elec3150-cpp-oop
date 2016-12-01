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

    InitializeBlue();
    InitializeRed();
    InitializeImpassable();

    if(!texture_.loadFromFile("assets/map.png")) {
        std::cout << "Error loading map image" << std::endl;
    }

    sprite_.setTexture(texture_);
}

Board::~Board() {}

sf::Sprite Board::GetSprite() {
    return sprite_;
}

Tile Board::GetTileAtMouse() {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window_);

    if (mouse_pos.x > 640 || mouse_pos.y < 0 ||
        mouse_pos.x > 640 || mouse_pos.y < 0) {
        std::cout << "Invalid tile" << std::endl;
        return Tile();
    } else {
        return map_[mouse_pos.y / 64][mouse_pos.x / 64];
    }
}

void Board::SelectPieceAtPosition() {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window_);

    int pos_x = mouse_pos.x / 64;
    int pos_y = mouse_pos.y / 64;

    if (pos_x < 0 || pos_y < 0 ||
        pos_x > 9 || pos_y > 9) {
        std::cout << "No piece at mouse" << std::endl;
    } else {
        Type select_type = map_[pos_y][pos_x].GetType();

        if ( select_type == Type::EMPTY ||
             select_type == Type::IMPASSABLE ||
             select_type == Type::FLAG ||
             select_type == Type::BOMB) {
            mouse_selected_ = nullptr;
            mouse_selected_origin_ = nullptr;

        } else {
            std::cout << "Mouse pos: (" << pos_x << ", " << pos_y << ")" << std::endl;
            mouse_selected_copy_ = map_[pos_y][pos_x];
            mouse_selected_ = &mouse_selected_copy_;

            mouse_selected_origin_ = &map_[pos_y][pos_x];
            mouse_selected_origin_position_ = mouse_selected_origin_->GetPosition();

            map_[pos_y][pos_x].SetEmpty();
        }
    }
}

void Board::MoveSelectedPiece() {
    if (mouse_selected_ != nullptr) {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window_);
        mouse_selected_->SetPosition(mouse_pos.x - 32, mouse_pos.y - 32);
    }
}

void Board::SwapSelectedTile() {
    std::cout << "SwapPositions" << std::endl;

    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window_);

    int pos_x = mouse_pos.x / 64;
    int pos_y = mouse_pos.y / 64;

    if (pos_x < 0 || pos_y < 0 ||
        pos_x > 9 || pos_y > 9) {
        if (mouse_selected_ != nullptr &&
            mouse_selected_origin_ != nullptr) {
            ResetSelectedTile();
        }
    } else {
        if (mouse_selected_ != nullptr &&
            mouse_selected_origin_ != nullptr) {
            if (mouse_selected_->GetType() == Type::EMPTY) {
                ResetSelectedTile();
            } else {
                // int orig_x = mouse_selected_origin_->GetPosX();
                // int orig_y = mouse_selected_origin_->GetPosY();

                // map_[orig_y / 64][orig_x / 64] = map_[pos_y][pos_x];
                // map_[orig_y / 64][orig_x / 64].SetPosition(orig_x, orig_y);

                // mouse_selected_->SetPosition(mouse_pos.x - (mouse_pos.x % 64),
                //                                mouse_pos.y - (mouse_pos.y % 64));
                // map_[pos_y][pos_x] = *mouse_selected_;
                // mouse_selected_ = nullptr;
                // mouse_selected_origin_ = nullptr;
                CompareTiles();
            }
        } else {
            std::cout << "Selection is null" << std::endl;
        }
    }
}

void Board::ResetSelectedTile() {
    std::cout << "ResetSelectedTile()" << std::endl;
    if (mouse_selected_ != nullptr &&
        mouse_selected_origin_ != nullptr) {
        int orig_x = mouse_selected_origin_->GetPosX();
        int orig_y = mouse_selected_origin_->GetPosY();

        mouse_selected_->SetPosition(orig_x, orig_y);
        map_[orig_y / 64][orig_x / 64] = *mouse_selected_;

        mouse_selected_ = nullptr;
        mouse_selected_origin_ = nullptr;
    } else {
        std::cout << "Invalid ResetSelectedTile(), origin and selected are null"
                  << std::endl;
    }
}

void Board::ReplaceSelectedTile() {
    if (mouse_selected_ != nullptr &&
        mouse_selected_origin_ != nullptr) {

        sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window_);
        int orig_x = mouse_selected_origin_->GetPosX();
        int orig_y = mouse_selected_origin_->GetPosY();


        mouse_selected_->SetPosition(mouse_pos.x - (mouse_pos.x % 64),
                                       mouse_pos.y - (mouse_pos.y % 64));
        map_[mouse_pos.y / 64][mouse_pos.x / 64] = *mouse_selected_;
        map_[orig_y / 64][orig_x / 64] = Tile();

        mouse_selected_ = nullptr;
        mouse_selected_origin_ = nullptr;
    } else {
        std::cout << "Invalid ResetSelectedTile(), origin and selected are null"
                  << std::endl;
    }
}

void Board::KillSelectedTile() {
    if (mouse_selected_ != nullptr &&
        mouse_selected_origin_ != nullptr) {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window_);
        int orig_x = mouse_selected_origin_->GetPosX();
        int orig_y = mouse_selected_origin_->GetPosY();

        map_[orig_y / 64][orig_x / 64] = Tile();

        mouse_selected_ = nullptr;
        mouse_selected_origin_ = nullptr;
    }
}

void Board::KillAndResetTile() {
    if (mouse_selected_ != nullptr &&
        mouse_selected_origin_ != nullptr) {

        sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window_);
        int orig_x = mouse_selected_origin_->GetPosX();
        int orig_y = mouse_selected_origin_->GetPosY();

        map_[mouse_pos.y / 64][mouse_pos.x / 64] = Tile();
        map_[orig_y / 64][orig_x / 64] = Tile();

        mouse_selected_ = nullptr;
        mouse_selected_origin_ = nullptr;
    }
}

void Board::CompareTiles() {
    if (mouse_selected_ != nullptr &&
        mouse_selected_origin_ != nullptr) {

        Tile attacker = *mouse_selected_;
        Tile defender = GetTileAtMouse();

        Type attack_type = attacker.GetType();
        Type defend_type = defender.GetType();

        std::cout << attacker.GetPosition().x << " " << attacker.GetPosition().y << std::endl
                  << defender.GetPosition().x << " " << defender.GetPosition().y << std::endl;

        if (attacker.GetColor() == defender.GetColor()) {
            std::cout << "Cannot swap same color positions" << std::endl;
            ResetSelectedTile();
        } else if(defender.GetPosition() / 64 == mouse_selected_origin_position_ / 64) {
            ResetSelectedTile();
        } else if (defend_type == Type::EMPTY) {
            std::cout << "Moving tile" << std::endl;
            ReplaceSelectedTile();
        } else if (defend_type == Type::IMPASSABLE) {
            std::cout << "Cannot move onto impassable terrain" << std::endl;
            ResetSelectedTile();
        } else if (defend_type == Type::BOMB) {
            if (attack_type == Type::SAPPER) {
                ReplaceSelectedTile();
            } else {
                KillAndResetTile();
            }
        } else if (defend_type == Type::FLAG) {
            ReplaceSelectedTile();
        } else if (defend_type == attack_type) {
            KillAndResetTile();
        } else if (defend_type == Type::MARSHAL) {
            if (attack_type == Type::SPY) {
                ReplaceSelectedTile();
            } else {
                KillSelectedTile();
            }
        } else {
            std::cout << "No special cases" << std::endl;
            if (attack_type < defend_type) {
                std::cout << "Replace" << std::endl;
                ReplaceSelectedTile();
            } else {
                std::cout << "Kill" << std::endl;
                KillSelectedTile();
            }
        }
    }

    std::cout << "End of CompareTile" << std::endl;
}

void Board::Draw() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            window_->draw(map_[i][j].GetSprite());
            if (mouse_selected_ != nullptr) {
                window_->draw(mouse_selected_->GetSprite());
            }
        }
    }
}


void Board::InitializeBlue() {
    map_[0][0].SetTileType(Type::MARSHAL, Color::BLUE);

    map_[0][1].SetTileType(Type::GENERAL, Color::BLUE);

    map_[0][2].SetTileType(Type::COLONEL, Color::BLUE);
    map_[0][3].SetTileType(Type::COLONEL, Color::BLUE);

    map_[0][4].SetTileType(Type::MAJOR, Color::BLUE);
    map_[0][5].SetTileType(Type::MAJOR, Color::BLUE);
    map_[0][6].SetTileType(Type::MAJOR, Color::BLUE);

    map_[0][7].SetTileType(Type::CAPTAIN, Color::BLUE);
    map_[0][8].SetTileType(Type::CAPTAIN, Color::BLUE);
    map_[0][9].SetTileType(Type::CAPTAIN, Color::BLUE);
    map_[1][0].SetTileType(Type::CAPTAIN, Color::BLUE);

    map_[1][1].SetTileType(Type::LIEUTENANT, Color::BLUE);
    map_[1][2].SetTileType(Type::LIEUTENANT, Color::BLUE);
    map_[1][3].SetTileType(Type::LIEUTENANT, Color::BLUE);
    map_[1][4].SetTileType(Type::LIEUTENANT, Color::BLUE);

    map_[1][5].SetTileType(Type::SERGEANT, Color::BLUE);
    map_[1][6].SetTileType(Type::SERGEANT, Color::BLUE);
    map_[1][7].SetTileType(Type::SERGEANT, Color::BLUE);
    map_[1][8].SetTileType(Type::SERGEANT, Color::BLUE);

    map_[1][9].SetTileType(Type::SAPPER, Color::BLUE);
    map_[2][0].SetTileType(Type::SAPPER, Color::BLUE);
    map_[2][1].SetTileType(Type::SAPPER, Color::BLUE);
    map_[2][2].SetTileType(Type::SAPPER, Color::BLUE);
    map_[2][3].SetTileType(Type::SAPPER, Color::BLUE);

    map_[2][4].SetTileType(Type::SCOUT, Color::BLUE);
    map_[2][5].SetTileType(Type::SCOUT, Color::BLUE);
    map_[2][6].SetTileType(Type::SCOUT, Color::BLUE);
    map_[2][7].SetTileType(Type::SCOUT, Color::BLUE);
    map_[2][8].SetTileType(Type::SCOUT, Color::BLUE);
    map_[2][9].SetTileType(Type::SCOUT, Color::BLUE);
    map_[3][0].SetTileType(Type::SCOUT, Color::BLUE);
    map_[3][1].SetTileType(Type::SCOUT, Color::BLUE);

    map_[3][2].SetTileType(Type::SPY, Color::BLUE);

    map_[3][3].SetTileType(Type::BOMB, Color::BLUE);
    map_[3][4].SetTileType(Type::BOMB, Color::BLUE);
    map_[3][5].SetTileType(Type::BOMB, Color::BLUE);
    map_[3][6].SetTileType(Type::BOMB, Color::BLUE);
    map_[3][7].SetTileType(Type::BOMB, Color::BLUE);
    map_[3][8].SetTileType(Type::BOMB, Color::BLUE);

    map_[3][9].SetTileType(Type::FLAG, Color::BLUE);
}

void Board::InitializeRed() {
    map_[9][0].SetTileType(Type::MARSHAL, Color::RED);

    map_[9][1].SetTileType(Type::GENERAL, Color::RED);

    map_[9][2].SetTileType(Type::COLONEL, Color::RED);
    map_[9][3].SetTileType(Type::COLONEL, Color::RED);

    map_[9][4].SetTileType(Type::MAJOR, Color::RED);
    map_[9][5].SetTileType(Type::MAJOR, Color::RED);
    map_[9][6].SetTileType(Type::MAJOR, Color::RED);

    map_[9][7].SetTileType(Type::CAPTAIN, Color::RED);
    map_[9][8].SetTileType(Type::CAPTAIN, Color::RED);
    map_[9][9].SetTileType(Type::CAPTAIN, Color::RED);
    map_[8][0].SetTileType(Type::CAPTAIN, Color::RED);

    map_[8][1].SetTileType(Type::LIEUTENANT, Color::RED);
    map_[8][2].SetTileType(Type::LIEUTENANT, Color::RED);
    map_[8][3].SetTileType(Type::LIEUTENANT, Color::RED);
    map_[8][4].SetTileType(Type::LIEUTENANT, Color::RED);

    map_[8][5].SetTileType(Type::SERGEANT, Color::RED);
    map_[8][6].SetTileType(Type::SERGEANT, Color::RED);
    map_[8][7].SetTileType(Type::SERGEANT, Color::RED);
    map_[8][8].SetTileType(Type::SERGEANT, Color::RED);

    map_[8][9].SetTileType(Type::SAPPER, Color::RED);
    map_[7][0].SetTileType(Type::SAPPER, Color::RED);
    map_[7][1].SetTileType(Type::SAPPER, Color::RED);
    map_[7][2].SetTileType(Type::SAPPER, Color::RED);
    map_[7][3].SetTileType(Type::SAPPER, Color::RED);

    map_[7][4].SetTileType(Type::SCOUT, Color::RED);
    map_[7][5].SetTileType(Type::SCOUT, Color::RED);
    map_[7][6].SetTileType(Type::SCOUT, Color::RED);
    map_[7][7].SetTileType(Type::SCOUT, Color::RED);
    map_[7][8].SetTileType(Type::SCOUT, Color::RED);
    map_[7][9].SetTileType(Type::SCOUT, Color::RED);
    map_[6][0].SetTileType(Type::SCOUT, Color::RED);
    map_[6][1].SetTileType(Type::SCOUT, Color::RED);

    map_[6][2].SetTileType(Type::SPY, Color::RED);

    map_[6][3].SetTileType(Type::BOMB, Color::RED);
    map_[6][4].SetTileType(Type::BOMB, Color::RED);
    map_[6][5].SetTileType(Type::BOMB, Color::RED);
    map_[6][6].SetTileType(Type::BOMB, Color::RED);
    map_[6][7].SetTileType(Type::BOMB, Color::RED);
    map_[6][8].SetTileType(Type::BOMB, Color::RED);

    map_[6][9].SetTileType(Type::FLAG, Color::RED);
}

void Board::InitializeImpassable() {
    map_[4][2].SetImpassable();
    map_[5][2].SetImpassable();
    map_[4][3].SetImpassable();
    map_[5][3].SetImpassable();

    map_[4][6].SetImpassable();
    map_[5][6].SetImpassable();
    map_[4][7].SetImpassable();
    map_[5][7].SetImpassable();

}

