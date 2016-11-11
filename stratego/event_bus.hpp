#include <SFML/Graphics.hpp>

#include "input.hpp"
#include "gui.hpp"

class EventBus {
public:
    EventBus(sf::RenderWindow *window);
    ~EventBus();

    void HandleEvent(sf::Event event);

private:
    Input *input_;
    GUI *gui_;
};
