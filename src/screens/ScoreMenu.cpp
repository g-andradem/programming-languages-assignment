#include "ScoreMenu.hpp"
#include <algorithm>

ScoreMenu::ScoreMenu()
{
    if (!font.openFromFile("assets/fonts/JetBrainsMono-Regular.ttf")) {
        // Tratar erro caso a fonte não seja encontrada
    }
    if (scores.empty()) {
        scores = ScoreFile::load();

        ScoreFile::save(scores);
    }

    sortScores();

    // std::vector<ScoreEntry> scores = ScoreFile::load();
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
    title.setOrigin(title.getLocalBounds().getCenter());
    title.setPosition({416.f, 200.f});

    window.draw(title);

    float y = 416.f;

    for (std::size_t i = 0; i < scores.size(); ++i)
    {
        std::string text =
            std::to_string(i + 1) + ". " +
            scores[i].playerName + " - " +
            std::to_string(scores[i].score);

        sf::Text scoreText(font, text, 30);
        scoreText.setOrigin(title.getLocalBounds().getCenter());
        scoreText.setPosition({380.f, y});

        window.draw(scoreText);

        y += 50.f;
    }
}