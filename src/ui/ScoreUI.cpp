#include "ScoreUI.hpp"
#include <iomanip>
#include <sstream>
#include <iostream>

ScoreUI::ScoreUI()
    : text(font)
{
    if (!font.openFromFile("assets/fonts/JetBrainsMono-Regular.ttf")) {
        std::cerr << "Erro ao carregar fonte do Timer UI\n";
    }

    text.setCharacterSize(32);
    text.setFillColor(sf::Color::White);
    text.setPosition({20.f, 20.f});
}

void ScoreUI::update(const Score& score)
{
    std::ostringstream oss;

    oss << std::setfill('0')
        << std::setw(5) 
        << score.getPoints();

    text.setString(oss.str());
}

void ScoreUI::draw(sf::RenderWindow& window)
{
    window.draw(text);
}

void ScoreUI::setPosition(float x, float y)
{
    text.setPosition({x, y});
}