#include "gui.hpp"

#include <iostream>

GUI::GUI(sf::RenderWindow *window)
    : window_(window) {

}

void GUI::HandleEvent(sf::Event event) {
    switch(event.type) {
    case sf::Event::Closed:
        window_->close();
        break;
    default:
        break;
    }
}
