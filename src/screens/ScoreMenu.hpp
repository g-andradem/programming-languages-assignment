#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

typedef struct tScoreEntry
{
    std::string playerName;
    int score;
}ScoreEntry;

class ScoreMenu
{
private:
    sf::Font font;
    std::vector<ScoreEntry> scores;

public:
    ScoreMenu();

    void addScore(const std::string& playerName, int score);
    void draw(sf::RenderWindow& window);

private:
    void sortScores();
};