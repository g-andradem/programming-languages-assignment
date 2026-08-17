#include <SFML/Graphics.hpp>

#include "Tile.hpp"
#include "Wall.hpp"
#include "Object.hpp"

class Map
{
    public:
        Map();

        void draw(sf::RenderWindow& window);

    private:
        std::vector<std::vector<int>> map;

        sf::Texture carteira;
        sf::Texture piso;

        std::vector<std::vector<Tile>> tiles;
        std::vector<Wall> walls;
        std::vector<Object> objects;
};