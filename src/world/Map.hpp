#include <SFML/Graphics.hpp>

#include "Tile.hpp"

class Map
{
    public:
        Map();

        void draw(sf::RenderWindow& window);

    private:
        std::vector<std::vector<int>> map;

        sf::Texture carteira;
        sf::Texture wallTexture;

        std::vector<std::vector<Tile>> tiles;
};