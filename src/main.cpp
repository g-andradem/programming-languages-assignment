#include <SFML/Graphics.hpp>
#include "player/Player.hpp"
#include "world/Map.hpp"
#include "teacher/Teacher.hpp"
#include "core/Time.hpp"
#include "ui/TimerUI.hpp"
#include "ui/ScoreUI.hpp"
#include "core/Score.hpp"
#include "screens/MainMenu.hpp"

#include <iostream>

const unsigned int GAME_WIDTH = 832;
const unsigned int GAME_HEIGHT = 832;

enum class GameState {
    MainMenu,
    Playing,
    Settings,
    Paused,
    GameOver
};

int main()
{
    sf::RenderWindow window(
        //sf::VideoMode({1024, 768}), y < 12 x < 16
        // sf::VideoMode({960, 704}), y < 11 x < 15
        sf::VideoMode({GAME_WIDTH, GAME_HEIGHT}),
        "Meu primeiro programa SFML"
    );

    sf::Clock clock;

    // Menu
    MainMenu mainMenu;

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
    Time time;
    TimerUI timerUI;

    // Score
    Score score;
    ScoreUI scoreUI;
    scoreUI.setPosition(
        2 * 40.f, 
        2 * 40.f
    );

    // Player
    Player player(score);
    player.setOrigin(
        player.getLocalBounds().size / 2.f
    );
    player.setPosition(
        6 * 64.f + 32.f,
        8 * 64.f + 32.f // ALTURA
    );

    // Estado do Jogo
    GameState state = GameState::MainMenu;

    // Looping Main
    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            }

            // menu recebe eventos
            if (state == GameState::MainMenu) {
                MenuAction action = mainMenu.handleEvent(*event);

                if (action == MenuAction::Play) {
                    state = GameState::Playing;
                }

                else if (action == MenuAction::Settings) {
                    state = GameState::Settings;
                }

                else if (action == MenuAction::Exit) {
                    window.close();
                }
            }
        }

        sf::View view(sf::FloatRect(
            {0.f, 0.f},
            {static_cast<float>(GAME_WIDTH), static_cast<float>(GAME_HEIGHT)}
        ));

        window.setView(view);

        float deltaTime = clock.restart().asSeconds();

        if (state == GameState::MainMenu) {
            // menu
            mainMenu.update(deltaTime);
        }
        else if (state == GameState::Playing) {

            // Atualiza o jogo
            player.update(deltaTime);
            teacher.update(deltaTime);
            time.update(deltaTime);
            timerUI.update(time);
            scoreUI.update(score);

        }
        /*else if (state == GameState::Settings) {
            // configurações
        }*/

        window.clear();

        if (state == GameState::MainMenu) {
            // Desenha o menu
            mainMenu.draw(window);

        }
        else if (state == GameState::Playing) {
            // Desenha o jogo
            map.draw(window);
            teacher.draw(window);
            player.draw(window);
            timerUI.draw(window);
            scoreUI.draw(window);

        }

        window.display();
    }
    return 0;
}