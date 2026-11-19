#include "GameScreen.hpp"
#include <iostream>

// Construtor da Tela de Jogo
GameScreen::GameScreen(): 
    player(score),
    font(),
    warningText(font)
{
    teacher.setAnimation(TeacherAnimation::Front);
    teacher.setOrigin(
        teacher.getLocalBounds().size / 2.f
    );
    teacher.setScale(4.f, 4.f);
    teacher.setPosition(
        10 * 64.f + 32.f,
        3 * 64.f + 32.f
    );

    player.setOrigin(
        player.getLocalBounds().size / 2.f
    );
    player.setPosition(
        6 * 64.f + 32.f,
        8 * 64.f + 32.f
    );

    if (!font.openFromFile("assets/fonts/ROGENZ(DEMO).ttf")) {
        std::cerr << "Erro ao carregar fonte!\n";
    }

    warningText.setString("Vire para frente");
    warningText.setCharacterSize(50);
    warningText.setFillColor(sf::Color::Red);
    warningText.setPosition({250.f, 250.f});
}

// Eventos da Tela do Jogo
void GameScreen::handleEvent(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
            setAction(GameAction::Pause);
        }
    }
}

// Verificar Dano ao Jogador
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

// Update da Tela de Jogo
void GameScreen::update(float deltaTime)
{
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

// Desenhar a Tela do Jogo
void GameScreen::draw(sf::RenderWindow& window)
{
    map.draw(window);
    teacher.draw(window);
    player.draw(window);
    timerUI.draw(window);
    scoreUI.draw(window);
    heartUI.draw(window);
    
    if (player.getIsStunned()) 
        window.draw(warningText);
}

// Setter da Ação da Tela de Jogo
void GameScreen::setAction(GameAction action)
{
    currentAction = action;
}

// Getter da Ação da Tela de Jogo
GameAction GameScreen::getAction()
{
    GameAction action = currentAction;

    currentAction = GameAction::None;

    return action;
}

// Getter da Pontuação Atual do Jogo
int GameScreen::getScore()
{
    return score.getPoints();
}

// Reset das Variaveis do Jogo
void GameScreen::reset()
{
    player.reset();
    teacher.reset();
    time.reset();
    score.reset();
    damageApplied = false;
    currentAction = GameAction::None;
    teacher.setAnimation(TeacherAnimation::Front);
    heartUI.setLives(player.getHealth());
    scoreUI.update(score);
    timerUI.update(time);
}