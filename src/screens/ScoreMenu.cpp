#include "ScoreMenu.hpp"
#include <algorithm>

ScoreMenu::ScoreMenu()
{
    if (!font.openFromFile("assets/fonts/JetBrainsMono-Regular.ttf")) {
        // Tratar erro caso a fonte não seja encontrada
    }
}

void ScoreMenu::addScore(const std::string& playerName, int score)
{
    scores.push_back({playerName, score});
    sortScores();
}

void ScoreMenu::sortScores()
{
    std::sort(scores.begin(), scores.end(),
        [](const ScoreEntry& a, const ScoreEntry& b)
        {
            return a.score > b.score;
        });
}

void ScoreMenu::draw(sf::RenderWindow& window)
{
    sf::Text title(font, "PLACARES", 50);
    title.setPosition({500.f, 80.f});

    window.draw(title);

    float y = 180.f;

    for (std::size_t i = 0; i < scores.size(); ++i)
    {
        std::string text =
            std::to_string(i + 1) + ". " +
            scores[i].playerName + " - " +
            std::to_string(scores[i].score);

        sf::Text scoreText(font, text, 30);
        scoreText.setPosition({450.f, y});

        window.draw(scoreText);

        y += 50.f;
    }
}