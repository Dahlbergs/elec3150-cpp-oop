#include "texture_manager.hpp"

TextureManager::TextureManager()
    : textures_(26, sf::Texture()) {

    /* Empty or impassible slot texture */
    texture_paths_.push_back("assets/empty.png");

    /* Game piece textures */
    texture_paths_.push_back("assets/one_blue.png");
    texture_paths_.push_back("assets/two_blue.png");
    texture_paths_.push_back("assets/three_blue.png");
    texture_paths_.push_back("assets/four_blue.png");
    texture_paths_.push_back("assets/five_blue.png");
    texture_paths_.push_back("assets/six_blue.png");
    texture_paths_.push_back("assets/seven_blue.png");
    texture_paths_.push_back("assets/eight_blue.png");
    texture_paths_.push_back("assets/nine_blue.png");
    texture_paths_.push_back("assets/spy_blue.png");
    texture_paths_.push_back("assets/bomb_blue.png");
    texture_paths_.push_back("assets/flag_blue.png");
    texture_paths_.push_back("assets/one_red.png");
    texture_paths_.push_back("assets/two_red.png");
    texture_paths_.push_back("assets/three_red.png");
    texture_paths_.push_back("assets/four_red.png");
    texture_paths_.push_back("assets/five_red.png");
    texture_paths_.push_back("assets/six_red.png");
    texture_paths_.push_back("assets/seven_red.png");
    texture_paths_.push_back("assets/eight_red.png");
    texture_paths_.push_back("assets/nine_red.png");
    texture_paths_.push_back("assets/spy_red.png");
    texture_paths_.push_back("assets/bomb_red.png");
    texture_paths_.push_back("assets/flag_red.png");

    /* Button textures */
    texture_paths_.push_back("assets/done_placing.png");

    LoadTextures();
}

void TextureManager::LoadTextures() {
    for (int i = 0; i < texture_paths_.size(); i++) {
        if (!textures_[i].loadFromFile(texture_paths_[i])) {
            std::cout << "Could not load texture for: "
                      << texture_paths_[i] << std::endl;
        }
    }
}

sf::Texture& TextureManager::GetTexture(Type type, Color color) {
    int index = 1;

    if (color == Color::RED) {
        index += 12;
    }

    switch (type) {
    case Type::MARSHAL:
        break;
    case Type::GENERAL:
        index += 1;
        break;
    case Type::COLONEL:
        index += 2;
        break;
    case Type::MAJOR:
        index += 3;
        break;
    case Type::CAPTAIN:
        index += 4;
        break;
    case Type::LIEUTENANT:
        index += 5;
        break;
    case Type::SERGEANT:
        index += 6;
        break;
    case Type::SAPPER:
        index += 7;
        break;
    case Type::SCOUT:
        index += 8;
        break;
    case Type::SPY:
        index += 9;
        break;
    case Type::BOMB:
        index += 10;
        break;
    case Type::FLAG:
        index += 11;
        break;
    }

    return textures_[index];
}

sf::Texture& TextureManager::GetButtonTexture(Button button) {
    int index = 25;

    switch (button) {
    case Button::NONE:
        index = 0;
        break;
    case Button::DONE_PLACING:
        break;
    default:
        index = 0;
    }

    return textures_[index];
}

sf::Texture& TextureManager::GetEmptyTexture() {
    return textures_[0];
}

sf::Texture& TextureManager::GetImpassableTexture() {
    return textures_[0];
}

sf::Texture& TextureManager::GetMapTexture() {
    return textures_[26];
}
