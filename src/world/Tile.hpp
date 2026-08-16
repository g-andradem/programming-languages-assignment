#include <SFML/Graphics.hpp>

class Tile
    {
    public:
        Tile(const sf::Texture& texture, bool walkable);

        void setPosition(float x, float y);

        void draw(sf::RenderWindow& window);

        bool isWalkable() const;

    private:
        sf::Sprite sprite;
        bool walkable;
};