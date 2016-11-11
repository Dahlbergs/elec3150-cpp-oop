#pragma once

#include <SFML/Graphics.hpp>

class System {
public:
    virtual void HandleEvent(sf::Event event) = 0;
};
