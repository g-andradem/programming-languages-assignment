#include <SFML/Graphics.hpp>
#include "player/Player.hpp"
#include "world/Map.hpp"

const unsigned int GAME_WIDTH = 832;
const unsigned int GAME_HEIGHT = 832;

int main()
{
    sf::RenderWindow window(
        //sf::VideoMode({1024, 768}), y < 12 x < 16
        // sf::VideoMode({960, 704}), y < 11 x < 15
        sf::VideoMode({GAME_WIDTH, GAME_HEIGHT}),
        "Meu primeiro programa SFML"
    );

    // Player
    Player player;

    sf::Clock clock;

    // Mapa
    Map map;

    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
        }


        sf::View view(sf::FloatRect(
            {0.f, 0.f},
            {static_cast<float>(GAME_WIDTH), static_cast<float>(GAME_HEIGHT)}
        ));
        //sf::View view(sf::FloatRect({0.f, 0.f}, {1088.f, 832.f}));
        window.setView(view);

        float deltaTime = clock.restart().asSeconds();

        player.update(deltaTime);

        //camera.setCenter(player.getPosition());

        //window.setView(camera);
        
        window.clear();

        map.draw(window);

        player.draw(window);

        window.display();
    }

    return 0;
}