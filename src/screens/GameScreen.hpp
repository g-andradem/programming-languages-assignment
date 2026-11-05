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

    public:
        GameScreen();

        int handleEvent(const sf::Event& event);
        void update(float deltaTime);
        void draw(sf::RenderWindow& window);
};