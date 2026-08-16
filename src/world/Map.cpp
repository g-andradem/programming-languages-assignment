#include <iostream>
#include "Map.hpp"

Map::Map(){
    map = {
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    if(!grama.loadFromFile("assets/textures/tiles/sprite_chao_grama.png")){
        std::cerr << "Erro ao carregar sprite_grama.png\n";
    }
    if(!wallTexture.loadFromFile("assets/textures/tiles/sprite_parede.png")){
        std::cerr << "Erro ao carregar sprite_parede.png\n";
    }
    if(!carteira.loadFromFile("assets/textures/tiles/sprite_carteira.png")){
        std::cerr << "Erro ao carregar sprite_carteira.png\n";
    }
    if(!preto.loadFromFile("assets/textures/tiles/sprite_chao_pedra.png")){
        std::cerr << "Erro ao carregar sprite_canto_parede.png\n";
    }

    for (int y = 0; y < map.size(); y++)
    {
        std::vector<Tile> row;
        for (int x = 0; x < map[y].size(); x++){
            if (map[y][x] == 0){
                row.emplace_back(grama, true);
            }
            else if(map[y][x] == 2){
                row.emplace_back(carteira, true);
            }
            else if(map[y][x] == 3){
                row.emplace_back(preto, true);
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