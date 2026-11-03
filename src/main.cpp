#include <SFML/Graphics.hpp>

#include "screens/MainMenu.hpp"
#include "screens/ScoreMenu.hpp"
#include "screens/GameScreen.hpp"
#include "screens/PauseScreen.hpp"

#include <iostream>

const unsigned int GAME_WIDTH = 832;
const unsigned int GAME_HEIGHT = 832;

// Nao possui Paused e GameOver, ou talvez possua
enum class GameState {
    MainMenu,
    Playing,
    Score,
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

    // Game Screen
    GameScreen gameScreen;

    // Score Menu
    ScoreMenu scoreMenu;
    
    // Pause Screen
    PauseScreen pauseScreen;

    // Estado do Jogo
    GameState state = GameState::MainMenu;

    // Estado do Jogo Anterior
    GameState previousState = GameState::MainMenu;

    // Looping Main
    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    if (state != GameState::MainMenu)
                    {
                        GameState temp = state;
                        state = previousState;
                        previousState = temp;
                    }
                }
            }

            // menu recebe eventos
            if (state == GameState::MainMenu) {
                MenuAction action = mainMenu.handleEvent(*event);

                if (action == MenuAction::Play) {
                    // trocar o previous State depois
                    previousState = GameState::Paused;
                    state = GameState::Playing;
                }

                else if (action == MenuAction::Score) {
                    previousState = state;
                    state = GameState::Score;
                }

                else if (action == MenuAction::Exit) {
                    window.close();
                }
            }
            else if (state == GameState::Score) {
                scoreMenu.handleEvent(*event);
            }

            // VER DEPOIS
            else if (state == GameState::Playing) {
                gameScreen.handleEvent(*event);
                //MenuAction action = mainMenu.handleEvent(*event);

                // previousState = 
            }
        }

        sf::View view(sf::FloatRect(
            {0.f, 0.f},
            {static_cast<float>(GAME_WIDTH), static_cast<float>(GAME_HEIGHT)}
        ));

        window.setView(view);

        // Define o deltaTime
        float deltaTime = clock.restart().asSeconds();

        if (state == GameState::MainMenu)
        {
            // Atualiza o Menu
            mainMenu.update(deltaTime);
        }
        else if (state == GameState::Playing)
        {
            // Atualiza o Jogo
            gameScreen.update(deltaTime);
        }
        else if (state == GameState::Score)
        {
            // Atualiza a Pontuação
            // scoreMenu.update(deltaTime);
        }

        // Limpa a Tela
        window.clear();

        if (state == GameState::MainMenu)
        {
            // Desenha o menu
            mainMenu.draw(window);
        }
        else if (state == GameState::Playing)
        {
            // Desenha o Jogo
            gameScreen.draw(window);
        }
        else if (state == GameState::Score)
        {
            // Desenha a Pontuação
            scoreMenu.draw(window);   
        }

        window.display();
    }
    return 0;
}