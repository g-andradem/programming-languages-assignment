#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({1000, 1000}),
        "Meu primeiro programa SFML"
    );

    // Textura do Jogador
    sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("assets/textures/characters/sprite_andre0.png")){
        return 1;
    }
    // Jogador
    sf::Sprite player(playerTexture);
    player.setScale({4.f, 4.f});
    player.setPosition({375.f, 275.f});

    // Camera
    sf::View camera(
        sf::FloatRect({0.f, 0.f}, {800.f, 600.f})
    );

    // Pegar Posicao do Jogador
    sf::Vector2f playerPosition = player.getPosition();

    // Testando Chao
    sf::RectangleShape ground({100.f, 100.f});
    ground.setFillColor(sf::Color::Green);
    ground.setPosition({0.f, 0.f});

    sf::RectangleShape wall({100.f, 100.f});
    wall.setFillColor(sf::Color::Blue);
    wall.setPosition({200.f, 100.f});

    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        float speed = 1.f; // pixels por segundo
        // float deltaTime = clock.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            player.move({-speed, 0.f});

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            player.move({speed, 0.f});

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            player.move({0.f, -speed});

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            player.move({0.f, speed});


        camera.setCenter(player.getPosition());

        window.setView(camera);
        
        window.clear();

        window.draw(ground);
        window.draw(wall);
        window.draw(player);

        window.display();
    }

    return 0;
}