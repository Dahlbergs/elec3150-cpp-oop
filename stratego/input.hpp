#pragma once

#include "system.hpp"

#include <SFML/Graphics.hpp>

class Input : public System {
public:
    Input();

    void HandleEvent(sf::Event event);

private:
    void HandleMouseClick(sf::Event event);
};
