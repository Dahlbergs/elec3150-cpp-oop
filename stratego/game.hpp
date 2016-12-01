#pragma once

#include <SFML/Graphics.hpp>

#include "board.hpp"

class Game {
public:
    Game();

    void Run();

private:
    void Update();
    void ProcessEvents();
    void Render();

    sf::RenderWindow window_;
    Board board_;
};
