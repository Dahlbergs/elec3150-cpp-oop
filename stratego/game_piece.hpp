#include <SFML/Graphics.hpp>

#include <string>

class GamePiece {
public:
    enum Type {
        SPY,
        MARSHALL,
        GENERAL,
        COLONEL,
        MAJOR,
        CAPTAIN,
        LIEUTENANT,
        SERGEANT,
        SAPPER,
        SCOUT,
        BOMB,
        FLAG
    };

    enum Color {
        BLUE,
        RED
    };

    GamePiece(Type type, Color color);

    void CreateSpriteFromFile(std::string path);

    sf::Sprite GetSprite();

    int getPositionX();
    int getPositionY();

    void setPositionX(int x);
    void setPositionY(int y);

private:
    sf::Sprite sprite;
    sf::Texture texture;

    Color color;
    Type piece_type;

    int pos_x;
    int pos_y;
};
