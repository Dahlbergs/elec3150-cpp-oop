#include <SFML/Graphics.hpp>

#include <iostream>

#include "game.hpp"

int main() {
    Game game;
    game.Run();
}

/* sf::RenderWindow window(sf::VideoMode(1000, 640), "Stratego Clone");

sf::Texture t_map;
if (!t_map.loadFromFile("assets/map.png")) {
    std::cout << "Unable to load map image" << std::endl;
 }

sf::Sprite s_map;
s_map.setTexture(t_map);

GamePiece marshall(GamePiece::MARSHALL, GamePiece::BLUE);

sf::RectangleShape toolbar(sf::Vector2f(480, 640));
toolbar.setFillColor(sf::Color(100, 100, 100));
toolbar.setPosition(640, 0);

while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

    window.clear();
    window.draw(s_map);
    window.draw(marshall.GetSprite());
    window.draw(toolbar);
    window.display();
 }

 return 0;
*/
