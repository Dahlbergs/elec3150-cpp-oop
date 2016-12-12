#include "game.hpp"

#include <iostream>

Game::Game()
    : window_(sf::VideoMode(1000, 640), "Stratego Clone"),
      board_(640, 640, &window_) {

}

void Game::Run() {

    while (window_.isOpen()) {
        ProcessEvents();
        Render();
    }
}

void Game::ProcessEvents() {
    sf::Event event;

    while (window_.pollEvent(event)) {
        switch(event.type) {
        case sf::Event::Closed:
            window_.close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left) {
                board_.SelectPieceAtPosition();
            }
            break;
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left) {
                board_.CheckValidMovement();
            }

            break;
        case sf::Event::MouseMoved:
            board_.MoveSelectedPiece();
            break;
        }
    }
}

void Game::Update() {

}

void Game::Render() {
    window_.clear(sf::Color(0x90, 0x95, 0xA1));
    window_.draw(board_.GetSprite());
    board_.Draw();
    window_.display();
}

