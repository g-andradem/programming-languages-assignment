#include <SFML/Graphics.hpp>

class Wall
    {
    public:
        Wall(const sf::Texture& texture);

        void setPosition(float x, float y);
        void setOrigin(sf::Vector2f origin);
        void setScale(float width, float height);
        void setRotation(float angle);
        sf::FloatRect getLocalBounds();

        void draw(sf::RenderWindow& window);

    private:
        sf::Sprite sprite;
};