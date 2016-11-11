#include "game.hpp"

#include <iostream>

Game::Game()
    : window_(sf::VideoMode(1000, 640), "Stratego Clone"),
      event_bus_(&window_) {


}

void Game::Run() {
    while (window_.isOpen()) {
        // Update();
        ProcessEvents();
        // Render();
    }
}

void Game::ProcessEvents() {
   sf::Event event;

    while (window_.pollEvent(event)) {
        event_bus_.HandleEvent(event);
    }
}

void Game::Render() {

}

void Game::Update() {

}
