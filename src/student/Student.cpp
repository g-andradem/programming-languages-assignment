#include "Student.hpp"

// Construtor dos Estudantes
Student::Student(const sf::Texture& texture):
    sprite(texture)
{}

// Setter da Escala
void Student::setScale(float width, float height)
{
    sprite.setScale({width, height});
}

// Setter da Origem
void Student::setOrigin(sf::Vector2f origin)
{
    sprite.setOrigin(origin);
}

// Setter da Posição
void Student::setPosition(float x, float y)
{
    sprite.setPosition({x, y});
}

// Desenhar Estudantes
void Student::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

// Getter do Limites Locais
sf::FloatRect Student::getLocalBounds()
{
    return sprite.getLocalBounds();
}