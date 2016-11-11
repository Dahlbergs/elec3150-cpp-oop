#include "input.hpp"

#include <iostream>

Input::Input() {

}

void Input::HandleEvent(sf::Event event) {
    switch (event.type) {
    case sf::Event::MouseButtonPressed:
        HandleMouseClick(event);
    }
}

void Input::HandleMouseClick(sf::Event event) {
    if (event.mouseButton.button == sf::Mouse::Right) {
        std::cout << "the right button was pressed" << std::endl;
        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
    }
}
