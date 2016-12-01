#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "tile_enums.hpp"

class TextureManager {
public:
    TextureManager();

    void LoadTextures();

    sf::Texture& GetTexture(Type type, Color color);
    sf::Texture& GetEmptyTexture();
    sf::Texture& GetImpassableTexture();
    sf::Texture& GetMapTexture();

private:
    std::vector<sf::Texture> textures_;
    std::vector<std::string> texture_paths_;

};
