#pragma once

#include <SFML/Graphics.hpp>

#include "../core/Time.hpp"
#include "../core/Score.hpp"
#include "../ui/TimerUI.hpp"
#include "../ui/ScoreUI.hpp"
#include "../ui/HeartUI.hpp"

#include "../player/Player.hpp"
#include "../teacher/Teacher.hpp"
#include "../world/Map.hpp"

enum class GameAction
{
    None,
    Pause,
    GameOver,
    Exit
};

class GameScreen
{
    private:
        Map map;
        Teacher teacher;
        HeartUI heartUI;
        Time time;
        TimerUI timerUI;
        Score score;
        ScoreUI scoreUI;
        Player player;

        bool damageApplied = false;
        void checkPlayerDamage();

        sf::Font font;
        sf::Text warningText;
        bool showWarning = false;

        GameAction currentAction = GameAction::None;
    public:
        GameScreen();

        void handleEvent(const sf::Event& event);
        void update(float deltaTime);
        void draw(sf::RenderWindow& window);

        void setAction(GameAction action);
        GameAction getAction() const;
};