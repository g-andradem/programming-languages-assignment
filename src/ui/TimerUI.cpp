#include "TimerUI.hpp"
#include <iomanip>
#include <sstream>
#include <iostream>

TimerUI::TimerUI()
    : text(font)
{
    if (!font.openFromFile("assets/fonts/JetBrainsMono-Regular.ttf")) {
        std::cerr << "Erro ao carregar fonte do Timer UI\n";
    }

    text.setCharacterSize(32);
    text.setFillColor(sf::Color::White);
    text.setPosition(
        {8 * 40.f, 
        1.5 * 40.f}
    );
}

void TimerUI::update(const Time& Time)
{
    std::ostringstream oss;

    oss << std::setfill('0')
        << std::setw(2) << Time.getMinutes()
        << ":"
        << std::setw(2) << Time.getSeconds();

    text.setString(oss.str());
}

void TimerUI::draw(sf::RenderWindow& window)
{
    window.draw(text);
}