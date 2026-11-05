#include <SFML/Graphics.hpp>

class Object
{
    private:
        sf::Sprite sprite;
    public:
        Object(const sf::Texture& texture);

        void setPosition(sf::Vector2f position);
        void setOrigin(sf::Vector2f origin);
        void setPosition(float x, float y);
        void setScale(float width, float height);

        void draw(sf::RenderWindow& window);

        sf::FloatRect getLocalBounds();
};