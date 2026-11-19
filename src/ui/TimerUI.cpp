#include "TimerUI.hpp"
#include <iomanip>
#include <sstream>
#include <iostream>

// Construtor do UI Temporizador
TimerUI::TimerUI(): 
    text(font)
{
    if (!font.openFromFile("assets/fonts/ROGENZ(DEMO).ttf")) {
        std::cerr << "Erro ao carregar fonte do Timer UI\n";
    }

    text.setCharacterSize(80);
    text.setFillColor(sf::Color::White);
    text.setPosition({
        0.7 * 40.f, 
        0.4 * 40.f
    });
}

// Update UI Temporizador
void TimerUI::update(const Time& Time)
{
    std::ostringstream oss;

    oss << std::setfill('0')
        << std::setw(2) << Time.getMinutes()
        << ":"
        << std::setw(2) << Time.getSeconds();

    text.setString(oss.str());
}

// Desenhar UI Temporizador
void TimerUI::draw(sf::RenderWindow& window)
{
    window.draw(text);
}