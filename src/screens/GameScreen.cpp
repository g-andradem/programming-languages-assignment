#include "GameScreen.hpp"
#include <iostream>

GameScreen::GameScreen(): 
    player(score)
{
    // Mapa
    //Map map;

    // Teacher
    //Teacher teacher;

    // Heart
    //HeartUI heartUI;

    // Time
    //Time time;
    //TimerUI timerUI;    

    
    // ver dps
    teacher.setAnimation(TeacherAnimation::Front);
    teacher.setOrigin(
        teacher.getLocalBounds().size / 2.f
    );
    teacher.setScale(4.f, 4.f);
    teacher.setPosition(
        10 * 64.f + 32.f,
        3 * 64.f + 32.f // ALTURA
    );

    

    // Score
    //Score score;
    //ScoreUI scoreUI;

    // Player
    //Player player(score);
    player.setOrigin(
        player.getLocalBounds().size / 2.f
    );
    player.setPosition(
        6 * 64.f + 32.f,
        8 * 64.f + 32.f // ALTURA
    );
}

// Seleciona Opcao no Menu
// VER DEPOIS
int GameScreen::handleEvent(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
            printf("pressionado");
            return 1;
        }
    }

    return 0;
}

void GameScreen::update(float deltaTime)
{
    // Atualiza o jogo
    player.update(deltaTime);
    teacher.update(deltaTime);
    time.update(deltaTime);
    timerUI.update(time);
    scoreUI.update(score);
    //heartUI.update(score);
}

void GameScreen::draw(sf::RenderWindow& window)
{
    // Desenha o jogo
    map.draw(window);
    teacher.draw(window);
    player.draw(window);
    timerUI.draw(window);
    scoreUI.draw(window);
    heartUI.draw(window);   
}