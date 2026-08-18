#include <iostream>
#include "Map.hpp"

Map::Map(){

    map = {
        {4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 3},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 3},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 3},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 3},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 3},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4},
    };

    if(!carteira.loadFromFile("assets/textures/characters/sprite_pessoa.png")){
        std::cerr << "Erro ao carregar sprite_pessoa.png\n";
    }
    if(!piso.loadFromFile("assets/textures/tiles/sprite_chao.png")){
        std::cerr << "Erro ao carregar sprite_piso.png\n";
    }
    if(!professor.loadFromFile("assets/textures/characters/sprite_professora.png")){
        std::cerr << "Erro ao carregar sprite_professor.png\n";
    }
    if(!wall_vertical.loadFromFile("assets/textures/walls/sprite_wall_vertical.png")){
        std::cerr << "Erro ao carregar sprite_wall_vertical.png\n";
    }
    if(!wall_edge.loadFromFile("assets/textures/walls/sprite_wall_edge.png")){
        std::cerr << "Erro ao carregar sprite_wall_edge.png\n";
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
            
            object.setOrigin(object.getLocalBounds().size / 2.f);

            object.setScale(3.f, 3.f);

            object.setPosition(
                x * 64.f + 32.f,
                y * 64.f + 32.f
            );
            objects.push_back(object);
            }

            if(map[y][x] == 1){
                Object object(professor);
            
            object.setOrigin(object.getLocalBounds().size / 2.f);

            object.setScale(4.f, 4.f);

            object.setPosition(
                x * 64.f + 32.f,
                y * 64.f + 32.f
            );
            objects.push_back(object);
            }
        }
    }

    // Wall
    for (int y = 0; y < map.size(); y++){
        for (int x = 0; x < map[y].size(); x++){
            if(map[y][x] == 3){
                Wall wall(wall_vertical);
                wall.setOrigin(wall.getLocalBounds().size / 2.f);
                wall.setScale(2.f, 2.f);

                if (x == 0) {
                    wall.setRotation(0.f);
                }
                else if (y == 0) {
                    wall.setRotation(90.f);
                }
                else if (x == map[y].size() - 1) {
                    wall.setRotation(180.f);
                }
                else if (y == map.size() - 1) {
                    wall.setRotation(270.f);
                }

                wall.setPosition(
                    x * 64.f + 32.f,
                    y * 64.f + 32.f
                );
                walls.push_back(wall);
            }
        }

        for (int x = 0; x < map[y].size(); x++){
            if(map[y][x] == 4){
                Wall wall(wall_edge);
                wall.setOrigin(wall.getLocalBounds().size / 2.f);
                wall.setScale(2.f, 2.f);

                if (x == 0 && y == 0) {
                    wall.setRotation(0.f);
                }
                else if (x == map[y].size() - 1 && y == 0) {
                    wall.setRotation(90.f);
                }
                else if (x == map[y].size() - 1 && y == map.size() - 1) {
                    wall.setRotation(180.f);
                }
                else if (x == 0 && y == map.size() - 1) {
                    wall.setRotation(270.f);
                }

                wall.setPosition(
                    x * 64.f + 32.f,
                    y * 64.f + 32.f
                );
                walls.push_back(wall);
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