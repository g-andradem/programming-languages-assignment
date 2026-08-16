#include <SFML/Graphics.hpp>
#include "player/Player.hpp"
#include "world/Map.hpp"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Meu primeiro programa SFML"
    );

    // Player
    Player player;

    sf::Clock clock;

    // Camera
    sf::View camera(
        sf::FloatRect({0.f, 0.f}, {800.f, 600.f})
    );

    // Pegar Posicao do Jogador
    sf::Vector2f playerPosition = player.getPosition();

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

        camera.setCenter(player.getPosition());

        window.setView(camera);
        
        window.clear();

        map.draw(window);

        player.draw(window);

        window.display();
    }

    return 0;
}