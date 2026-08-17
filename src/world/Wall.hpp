#include <SFML/Graphics.hpp>

class Wall
    {
    public:
        Wall(const sf::Texture& texture);

        void setPosition(float x, float y);

        void draw(sf::RenderWindow& window);

    private:
        sf::Sprite sprite;
};