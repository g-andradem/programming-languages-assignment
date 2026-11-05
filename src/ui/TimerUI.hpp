#pragma once

#include <SFML/Graphics.hpp>
#include "../core/Time.hpp"

class Timer;

class TimerUI
{
    private:
        sf::Font font;
        sf::Text text;
    public:
        TimerUI();

        void update(const Time& Time);
        void draw(sf::RenderWindow& window);
};