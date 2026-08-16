#include <iostream>
#include "Map.hpp"

Map::Map(){
    for (int y = 0; y < 15; y++)
    {
        std::vector<int> row;
        for (int x = 0; x < 15; x++)
        {
            if (x == 0 || x == 14 || y == 0 || y == 14)
                row.push_back(1);
            else
                row.push_back(0);
        }
        map.push_back(row);
    }

    if(!carteira.loadFromFile("assets/textures/tiles/sprite_carteira.png")){
        std::cerr << "Erro ao carregar sprite_carteira.png\n";
    }
    if(!wallTexture.loadFromFile("assets/textures/tiles/sprite_parede.png")){
        std::cerr << "Erro ao carregar sprite_parede.png\n";
    }

    for (int y = 0; y < map.size(); y++)
    {
        std::vector<Tile> row;
        for (int x = 0; x < map[y].size(); x++){
            if (map[y][x] == 0){
                row.emplace_back(carteira, true);
            }
            else{
                row.emplace_back(wallTexture, false);
            }

            row.back().setPosition(
                x * 64.f,
                y * 64.f
            );
        }
        tiles.push_back(row);
    }
}

void Map::draw(sf::RenderWindow& window)
{
    for (auto& row : tiles)
    {
        for (auto& tile : row)
        {
            tile.draw(window);
        }
    }
}