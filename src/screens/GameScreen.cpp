#include "GameScreen.hpp"
#include <iostream>

#include "core/Time.hpp"
#include "core/Score.hpp"
#include "ui/TimerUI.hpp"
#include "ui/ScoreUI.hpp"
#include "ui/HeartUI.hpp"

#include "player/Player.hpp"
#include "teacher/Teacher.hpp"
#include "world/Map.hpp"

GameScreen::GameScreen(): 

{
    // Mapa
    Map map;

    // Teacher
    Teacher teacher;
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

    // Heart
    HeartUI heartUI;

    // Time
    Time time;
    TimerUI timerUI;

    // Score
    Score score;
    ScoreUI scoreUI;

    // Player
    Player player(score);
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
GameAction GameScreen::handleEvent(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {

        if (keyPressed->scancode == sf::Keyboard::Scan::W) {

            selectedButton--;

            if (selectedButton < 0)
                selectedButton = 2;

            updateSelection();
        }

        else if (keyPressed->scancode == sf::Keyboard::Scan::S) {

            selectedButton++;

            if (selectedButton > 2)
                selectedButton = 0;

            updateSelection();
        }

        else if (keyPressed->scancode == sf::Keyboard::Scancode::Enter) {

            if (selectedButton == 0)
                return MenuAction::Play;

            if (selectedButton == 1)
                return MenuAction::Score;

            if (selectedButton == 2)
                return MenuAction::Exit;
        }
    }

    return MenuAction::None;
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

void MainMenu::updateSelection()
{
    playButton.setCharacterSize(52);
    scoreButton.setCharacterSize(52);
    exitButton.setCharacterSize(52);

    if (selectedButton == 0)
        playButton.setCharacterSize(70);
    else if (selectedButton == 1)
        scoreButton.setCharacterSize(70);
    else if (selectedButton == 2)
        exitButton.setCharacterSize(70);

    centerText(playButton, 416.f);
    centerText(scoreButton, 416.f);
    centerText(exitButton, 416.f);
}

void MainMenu::centerText(sf::Text& text, float x)
{
    auto bounds = text.getLocalBounds();

    text.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
    });

    text.setPosition({
        x,
        text.getPosition().y
    });
}

int MainMenu::getSelectedButton() const
{
    return selectedButton;
}