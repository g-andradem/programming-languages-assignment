#include <iostream>
#include "Map.hpp"

Map::Map(){

    map = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    if(!carteira.loadFromFile("assets/textures/characters/sprite_pessoa.png")){
        std::cerr << "Erro ao carregar sprite_pessoa.png\n";
    }
    if(!piso.loadFromFile("assets/textures/tiles/sprite_chao.png")){
        std::cerr << "Erro ao carregar sprite_piso.png\n";
    }

    for (int y = 0; y < map.size(); y++)
    {
        std::vector<Tile> row;
        for (int x = 0; x < map[y].size(); x++){
            row.emplace_back(piso, true);

            row.back().setPosition(
                x * 64.f,
                y * 64.f
            );
        }
        tiles.push_back(row);
    }

    for (int y = 0; y < map.size(); y++)
    {
        for (int x = 0; x < map[y].size(); x++){
            if(map[y][x] == 2){
                Object object(carteira);
            
            object.setOrigin(
                object.getLocalBounds().size / 2.f
            );

            object.setPosition(
                x * 64.f + 32.f,
                y * 64.f + 32.f
            );
            objects.push_back(object);
            }
        }
    }
}

void Map::draw(sf::RenderWindow& window)
{
    // Chao
    for (auto& row : tiles){
        for (auto& tile : row){
            tile.draw(window);
        }
    }

    // Paredes
    for (auto& wall : walls){
        wall.draw(window);
    }

    // Objetos
    for (auto& object : objects){
        object.draw(window);
    }
}