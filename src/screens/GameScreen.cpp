#include "GameScreen.hpp"
#include <iostream>

GameScreen::GameScreen(): 
    player(score),
    font(),
    warningText(font)
{    
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

    player.setOrigin(
        player.getLocalBounds().size / 2.f
    );
    player.setPosition(
        6 * 64.f + 32.f,
        8 * 64.f + 32.f // ALTURA
    );

    if (!font.openFromFile("assets/fonts/ROGENZ(DEMO).ttf")) {
        std::cerr << "Erro ao carregar fonte!\n";
    }

    warningText.setString("Vire para frente");
    warningText.setCharacterSize(50);
    warningText.setFillColor(sf::Color::Red);
    warningText.setPosition({250.f, 250.f});
}

void GameScreen::handleEvent(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
            setAction(GameAction::Pause);
        }
    }
}

void GameScreen::checkPlayerDamage()
{
    bool teacherIsFront =
        teacher.getCurrentAnimation() == TeacherAnimation::Front;

    bool playerIsSide =
        player.getCurrentAnimation() == PlayerAnimation::Left ||
        player.getCurrentAnimation() == PlayerAnimation::Right;

    if (teacherIsFront && playerIsSide)
    {
        if (!damageApplied && player.getHealth() > 0)
        {
            player.takeDamage();
            teacher.decreaseAnimationInterval();
            heartUI.setLives(player.getHealth());
            damageApplied = true;
        }
    } else
    {
        damageApplied = false;
    }
}

void GameScreen::update(float deltaTime)
{
    // Atualiza o jogo
    player.update(deltaTime);
    teacher.update(deltaTime);
    time.update(deltaTime);

    if (time.getMinutes() == 0 && time.getSeconds() == 0)
    {
        setAction(GameAction::Finish);
        return;
    }

    timerUI.update(time);
    scoreUI.update(score);
    
    checkPlayerDamage();

    if (player.getHealth() <= 0)
    {
        setAction(GameAction::GameOver);
    }
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
    
    if (player.getIsStunned()) 
        window.draw(warningText);
}

void GameScreen::setAction(GameAction action)
{
    currentAction = action;
}

GameAction GameScreen::getAction()
{
    GameAction action = currentAction;

    currentAction = GameAction::None;

    return action;
}

int GameScreen::getScore()
{
    return score.getPoints();
}

void GameScreen::reset()
{
    // Reseta o estado do jogador
    player.reset();

    // Reseta o professor
    teacher.reset();

    // Reseta o tempo
    time.reset();

    // Reseta a pontuação
    score.reset();

    // Reseta o controle de dano
    damageApplied = false;

    // Reseta a ação atual
    currentAction = GameAction::None;

    // Reseta a animação do professor
    teacher.setAnimation(TeacherAnimation::Front);

    // Atualiza a interface
    heartUI.setLives(player.getHealth());
    scoreUI.update(score);
    timerUI.update(time);
}