#pragma once

#include "event_bus.hpp"

#include <SFML/Graphics.hpp>

class Game {
public:
    Game();

    void Run();

private:
    void Update();
    void ProcessEvents();
    void Render();

    sf::RenderWindow window_;
    EventBus event_bus_;
};
