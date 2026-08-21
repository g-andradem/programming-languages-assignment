#include <SFML/Graphics.hpp>
#include "player/Player.hpp"
#include "world/Map.hpp"
#include "teacher/Teacher.hpp"
#include "core/GameTime.hpp"
#include "ui/TimerUI.hpp"

#include <iostream>

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
    player.setPosition(400.f, 400.f);

    sf::Clock clock;

    // Mapa
    Map map;

    // Teacher
    Teacher teacher;
    teacher.setAnimation(TeacherAnimation::Front);
    teacher.setOrigin(
        teacher.getLocalBounds().size / 2.f
    );
    teacher.setScale(4.f, 4.f);
    teacher.setPosition(
        10 * 64.f + 32.f,
        3 * 64.f + 32.f // ALTURA
    );

    // Time
    GameTime gameTime;
    TimerUI timerUI;

    // Looping Main
    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            }

            if (event->is<sf::Event::KeyPressed>())
            {
                const auto& keyEvent = event->getIf<sf::Event::KeyPressed>();

                if (keyEvent->code == sf::Keyboard::Key::Num1)
                {
                    teacher.setAnimation(TeacherAnimation::Front);
                }
                else if (keyEvent->code == sf::Keyboard::Key::Num2)
                {
                    teacher.setAnimation(TeacherAnimation::Diagonal);
                }
                else if (keyEvent->code == sf::Keyboard::Key::Num3)
                {
                    teacher.setAnimation(TeacherAnimation::Side);
                }
            }

            if (event->is<sf::Event::KeyPressed>())
            {
                const auto& keyEvent = event->getIf<sf::Event::KeyPressed>();

                if (keyEvent->code == sf::Keyboard::Key::Num4)
                {
                    player.setAnimation(PlayerAnimation::Front);
                }
                else if (keyEvent->code == sf::Keyboard::Key::Num5)
                {
                    player.setAnimation(PlayerAnimation::Side);
                }
            }
        }


        sf::View view(sf::FloatRect(
            {0.f, 0.f},
            {static_cast<float>(GAME_WIDTH), static_cast<float>(GAME_HEIGHT)}
        ));

        window.setView(view);

        float deltaTime = clock.restart().asSeconds();
        
        // Update
        player.update(deltaTime);
        teacher.update(deltaTime);
        gameTime.update(deltaTime);

        timerUI.update(gameTime);

        window.clear();

        // Draw
        map.draw(window);
        teacher.draw(window);
        player.draw(window);
        timerUI.draw(window);

        window.display();
    }

    return 0;
}