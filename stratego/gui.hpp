#pragma once

#include "system.hpp"

#include <SFML/Graphics.hpp>

class GUI : public System {
public:
    GUI(sf::RenderWindow *window);

    void HandleEvent(sf::Event event);

private:
    sf::RenderWindow *window_;
};
