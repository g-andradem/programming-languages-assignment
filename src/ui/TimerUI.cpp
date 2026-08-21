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
    text.setPosition({20.f, 20.f});
}

void TimerUI::update(const GameTime& gameTime)
{
    std::ostringstream oss;

    oss << std::setfill('0')
        << std::setw(2) << gameTime.getMinutes()
        << ":"
        << std::setw(2) << gameTime.getSeconds();

    text.setString(oss.str());
}

void TimerUI::draw(sf::RenderWindow& window)
{
    window.draw(text);
}