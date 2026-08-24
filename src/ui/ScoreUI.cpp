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

void ScoreUI::update(const Score& Score)
{
    std::ostringstream oss;

    oss << std::setfill('0')
        << std::setw(2) << Score.getPoints();

    text.setString(oss.str());
}

void ScoreUI::draw(sf::RenderWindow& window)
{
    window.draw(text);
}