#include <SFML/Graphics.hpp>

#include "Tile.hpp"
#include "Wall.hpp"
#include "Object.hpp"
//#include "../student/Student.hpp"

class Map
{
    public:
        Map();

        void draw(sf::RenderWindow& window);

    private:
        std::vector<std::vector<int>> map;

        sf::Texture piso;
        sf::Texture professor;
        sf::Texture wall_vertical;
        sf::Texture wall_edge;
        sf::Texture door;

        // Students
        sf::Texture student_1;
        sf::Texture student_2;
        sf::Texture student_3;
        sf::Texture student_4;
        sf::Texture student_5;

        // Hud
        sf::Texture hud_edge;;
        sf::Texture hud_horizontal;

        std::vector<std::vector<Tile>> tiles;
        std::vector<Wall> walls;
        std::vector<Object> objects;

        // Tirar estudante daqui depois
        //std::vector<Student> students;
};