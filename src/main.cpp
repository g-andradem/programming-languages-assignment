#include <SFML/Graphics.hpp>
#include "player/Player.hpp"
#include "world/Map.hpp"

int main()
{
    sf::RenderWindow window(
        //sf::VideoMode({1024, 768}), y < 12 x < 16
        // sf::VideoMode({960, 704}), y < 11 x < 15
        sf::VideoMode({1088, 832}),
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