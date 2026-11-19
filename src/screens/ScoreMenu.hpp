#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "../score/ScoreEntry.hpp"
#include "../score/ScoreFile.hpp"

class ScoreMenu
{
    private:
        sf::Font font;
        std::vector<ScoreEntry> scores;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
        std::size_t selectedIndex = 0;
        int selectedButton = 0;
        bool editing = false;
        std::string editingName;
        std::size_t editingIndex = 0;
        void sortScores();

    public:
        ScoreMenu();

        void addScore(const std::string& playerName, int score);
        void draw(sf::RenderWindow& window);
        int handleEvent(const sf::Event& event);
        void editScore(std::size_t index);
        void deleteScore(std::size_t index); 
        void update();
};