#include "event_bus.hpp"

EventBus::EventBus(sf::RenderWindow *window) {
    input_ = new Input();
    gui_ = new GUI(window);
}

EventBus::~EventBus() {
    delete input_;
    delete gui_;
}

void EventBus::HandleEvent(sf::Event event) {
    input_->HandleEvent(event);
    gui_->HandleEvent(event);
}
