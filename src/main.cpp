#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Meu primeiro programa SFML"
    );

    sf::RectangleShape player({50.f, 50.f});
    player.setFillColor(sf::Color::Green);
    player.setPosition({375.f, 275.f});

    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        float speed = 1.f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            player.move({-speed, 0.f});

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            player.move({speed, 0.f});

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            player.move({0.f, -speed});

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            player.move({0.f, speed});

        window.clear();

        window.draw(player);

        window.display();
    }

    return 0;
}