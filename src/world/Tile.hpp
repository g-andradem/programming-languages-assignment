#include <SFML/Graphics.hpp>

class Tile
{
    private:
        sf::Sprite sprite;
        bool walkable;
    public:
        Tile(const sf::Texture& texture, bool walkable);

        void setPosition(float x, float y);

        void draw(sf::RenderWindow& window);

        bool isWalkable() const;
};