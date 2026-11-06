#include <SFML/Graphics.hpp>

#include "screens/MainMenu.hpp"
#include "screens/ScoreMenu.hpp"
#include "screens/GameScreen.hpp"
#include "screens/PauseScreen.hpp"
#include "screens/GameOverScreen.hpp"
#include "screens/NameInputScreen.hpp"
#include "screens/ResultsScreen.hpp"

const unsigned int GAME_WIDTH = 832;
const unsigned int GAME_HEIGHT = 832;

enum class GameState {
    MainMenu,
    NameInput,
    Playing,
    Score,
    Paused,
    Finish,
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

    // NameInput Screen
    NameInputScreen nameInputScreen;

    // Score Menu
    ScoreMenu scoreMenu;
    
    // Pause Screen
    PauseScreen pauseScreen;

    // GameOver Screen
    GameOverScreen gameOverScreen;

    // Estado do Jogo
    GameState state = GameState::MainMenu;

    // Estado do Jogo Anterior
    GameState previousState = GameState::MainMenu;

    // Looping Main
    while (window.isOpen()){
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (state == GameState::MainMenu)
            {
                MenuAction action = mainMenu.handleEvent(*event);

                if (action == MenuAction::Play)
                {
                    previousState = GameState::MainMenu;
                    nameInputScreen.reset();
                    state = GameState::NameInput;
                }
                else if (action == MenuAction::Score)
                {
                    previousState = state;
                    state = GameState::Score;
                }
                else if (action == MenuAction::Exit)
                {
                    window.close();
                }
            }
            else if (state == GameState::NameInput)
            {
                NameInputAction action = nameInputScreen.handleEvent(*event);

                if (action == NameInputAction::Play)
                {
                    state = GameState::Playing;
                }
            }
            else if (state == GameState::Playing)
            {
                gameScreen.handleEvent(*event);
            }
            else if (state == GameState::Paused)
            {
                PauseAction action = pauseScreen.handleEvent(*event);

                if (action == PauseAction::Play)
                {
                    state = GameState::Playing;
                }
                else if (action == PauseAction::Menu)
                {
                    gameScreen.reset();
                    state = GameState::MainMenu;
                }
                else if (action == PauseAction::Exit)
                {
                    window.close();
                }
            }
            else if (state == GameState::GameOver)
            {
                GameOverAction action = gameOverScreen.handleEvent(*event);

                if (action == GameOverAction::Menu)
                {
                    gameScreen.reset();
                    state = GameState::MainMenu;
                }
                else if (action == GameOverAction::PlayAgain)
                {
                    gameScreen.reset();
                    state = GameState::Playing;
                }
            }
            else if (state == GameState::Score)
            {
                if(scoreMenu.handleEvent(*event) == 1)
                {
                    state = previousState;
                }
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

            GameAction action = gameScreen.getAction();

            if (action == GameAction::GameOver)
            {
                state = GameState::GameOver;
            }
            else if (action == GameAction::Pause)
            {
                previousState = GameState::Playing;
                state = GameState::Paused;
            }
            else if (action == GameAction::Finish)
            {
                state = GameState::Finish;
            }
        }
        else if (state == GameState::Score)
        {
            // Atualiza a Pontuação
            // scoreMenu.update(deltaTime);
        }
        else if (state == GameState::Finish)
        {
            // Atualiza o Resultado
            // scoreMenu.update(deltaTime);
        }

        // Limpa a Tela
        window.clear();

        if (state == GameState::MainMenu)
        {
            // Desenha o menu
            mainMenu.draw(window);
        }
        else if (state == GameState::NameInput)
        {
            // Desenha o Name Input
            nameInputScreen.draw(window);
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
        else if (state == GameState::Paused)
        {
            // Desenha o Pause
            gameScreen.draw(window);
            pauseScreen.draw(window);
        }
        else if (state == GameState::GameOver)
        {
            // Desenha o Game Over
            gameOverScreen.draw(window);
        }
        else if (state == GameState::Finish)
        {
            // Desenha o Resultado da Partida
            ResultsScreen resultsScreen(
                nameInputScreen.getPlayerName(), 
                gameScreen.getScore()
            );
            resultsScreen.draw(window);
        }

        window.display();
    }
    return 0;
}