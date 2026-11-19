#include <iostream>
#include "Map.hpp"

#include <random>

// Construtor do Mapa
Map::Map(){

    map = {
        {6, 7, 7, 6, 6, 7, 7, 7, 6, 6, 7, 7, 6},
        {6, 7, 7, 6, 6, 7, 7, 7, 6, 6, 7, 7, 6},
        {4, 3, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 3},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 3},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 0, 2, 0, 2, 0, 0, 0, 2, 0, 2, 0, 3},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {3, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 3},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4},
    };

    if(!hud_horizontal.loadFromFile("assets/textures/hud/horizontal_superior.png")){
        std::cerr << "Erro ao carregar Hud horizontal_superior\n";
    }
    if(!hud_edge.loadFromFile("assets/textures/hud/esquerdo_superior.png")){
        std::cerr << "Erro ao carregar Hud esquerdo_superior\n";
    }

    if(!student_1.loadFromFile("assets/textures/characters/sprite_student_1.png")){
        std::cerr << "Erro ao carregar student_1\n";
    }
    if(!student_2.loadFromFile("assets/textures/characters/sprite_student_2.png")){
        std::cerr << "Erro ao carregar student_2\n";
    }
    if(!student_3.loadFromFile("assets/textures/characters/sprite_student_3.png")){
        std::cerr << "Erro ao carregar student_3\n";
    }
    if(!student_4.loadFromFile("assets/textures/characters/sprite_student_4.png")){
        std::cerr << "Erro ao carregar student_4\n";
    }
    if(!student_5.loadFromFile("assets/textures/characters/sprite_student_5.png")){
        std::cerr << "Erro ao carregar student_5\n";
    }

    if(!piso.loadFromFile("assets/textures/tiles/sprite_chao.png")){
        std::cerr << "Erro ao carregar piso\n";
    }

    if(!professor.loadFromFile("assets/textures/characters/sprite_professora.png")){
        std::cerr << "Erro ao carregar professor\n";
    }

    if(!wall_vertical.loadFromFile("assets/textures/walls/sprite_wall_vertical.png")){
        std::cerr << "Erro ao carregar parede_vertical\n";
    }
    if(!wall_edge.loadFromFile("assets/textures/walls/sprite_wall_edge.png")){
        std::cerr << "Erro ao carregar parede_canto\n";
    }
    if(!door.loadFromFile("assets/textures/walls/sprite_door.png")){
        std::cerr << "Erro ao carregar porta\n";
    }

    for (int y = 2; y < map.size(); y++)
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

    for (int y = 0; y < map.size(); y++){
        for (int x = 0; x < map[y].size(); x++){
            if(map[y][x] == 7){
                Wall hud(hud_horizontal);
                hud.setOrigin(hud.getLocalBounds().size / 2.f);
                hud.setScale(2.f, 2.f);

                if (x == 0) {
                    hud.setRotation(0.f);
                }
                else if (y == 1) {
                    hud.setRotation(180.f);
                }

                hud.setPosition(
                    x * 64.f + 32.f,
                    y * 64.f + 32.f
                );
                walls.push_back(hud);
            }
        }

        for (int x = 0; x < map[y].size(); x++){
            if(map[y][x] == 6){
                Wall hud(hud_edge);
                hud.setOrigin(hud.getLocalBounds().size / 2.f);
                hud.setScale(2.f, 2.f);

                if ((x == 0 || x == 4 || x == 9) && y == 0) {
                    hud.setRotation(0.f);
                }
                else if ((x == map[y].size() - 1 || x == 3 || x == 8) && y == 0) {
                    hud.setRotation(90.f);
                }
                else if ((x == map[y].size() - 1 || x == 3 || x == 8) && y == 1) {
                    hud.setRotation(180.f);
                }
                else if ((x == 0 || x == 4 || x == 9) && y == 1) {
                    hud.setRotation(270.f);
                }

                hud.setPosition(
                    x * 64.f + 32.f,
                    y * 64.f + 32.f
                );
                walls.push_back(hud);
            }
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<sf::Texture*> textures = {
        &student_1,
        &student_2,
        &student_3,
        &student_4,
        &student_5
    };
    std::uniform_int_distribution<int> dist(0, 4);

    for (int y = 0; y < map.size(); y++)
    {
        for (int x = 0; x < map[y].size(); x++){
            if(map[y][x] == 2){
                sf::Texture* randomTexture = textures[dist(gen)];

                Object object(*randomTexture);
            
                object.setOrigin(object.getLocalBounds().size / 2.f);

                object.setScale(3.f, 3.f);

                object.setPosition(
                    x * 64.f + 32.f,
                    y * 64.f + 32.f
                );
                objects.push_back(object);
            }
        }
    }

    for (int y = 0; y < map.size(); y++){
        for (int x = 0; x < map[y].size(); x++){
            if(map[y][x] == 3){
                Wall wall(wall_vertical);
                wall.setOrigin(wall.getLocalBounds().size / 2.f);
                wall.setScale(2.f, 2.f);

                if (x == 0) {
                    wall.setRotation(0.f);
                }
                else if (y == 2) {
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
                else if (x == map[y].size() - 1 && y == 2) {
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

        for (int x = 0; x < map[y].size(); x++){
            if(map[y][x] == 5){
                Wall wall(door);
                wall.setOrigin(wall.getLocalBounds().size / 2.f);
                wall.setScale(2.f, 2.f);
                wall.setPosition(
                    x * 64.f + 32.f,
                    y * 64.f + 32.f
                );
                walls.push_back(wall);
            }
        }
    }
}

// Desenhar Mapa
void Map::draw(sf::RenderWindow& window)
{
    for (auto& row : tiles){
        for (auto& tile : row){
            tile.draw(window);
        }
    }

    for (auto& wall : walls){
        wall.draw(window);
    }

    for (auto& object : objects){
        object.draw(window);
    }
}