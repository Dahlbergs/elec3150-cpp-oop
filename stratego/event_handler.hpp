#pragma once

#include <SFML/Graphics.hpp>

#include "board.hpp"

class EventHandler {
public:
    EventHandler();
    ~EventHandler();

    void HandleEvent(sf::Event event);
};
