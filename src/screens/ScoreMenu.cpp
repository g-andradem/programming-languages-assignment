#include "ScoreMenu.hpp"
#include <algorithm>
#include <iostream>

// Construtor da Tela de Pontos
ScoreMenu::ScoreMenu():
    backgroundSprite(backgroundTexture)
{
    if (!backgroundTexture.loadFromFile("assets/textures/background.jpg")) {
        std::cerr << "Erro ao carregar imagem de fundo!\n";
    }
    
    backgroundSprite.setTextureRect(
        sf::IntRect({0, 0}, {832, 832})
    );

    if (!font.openFromFile("assets/fonts/ROGENZ(DEMO).ttf")) {
        std::cerr << "Erro ao carregar fonte!\n";
    }
    scores = ScoreFile::load();

    sortScores();
}

// Adicionar Pontuação
void ScoreMenu::addScore(const std::string& playerName, int score)
{
    scores.push_back({playerName, score});
    sortScores();
}

// Ordenar Pontuações
void ScoreMenu::sortScores()
{
    std::sort(scores.begin(), scores.end(),
        [](const ScoreEntry& a, const ScoreEntry& b)
        {
            return a.score > b.score;
        });
}

// Desenhar a Tela de Pontuações
void ScoreMenu::draw(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);
    
    if (editing)
    {
        sf::Text title(font, "EDITAR NOME", 50);

        title.setOrigin(title.getLocalBounds().getCenter());
        title.setPosition({416.f, 250.f});

        window.draw(title);

        sf::Text nameText(font, editingName + "_", 35);

        nameText.setOrigin(
            nameText.getLocalBounds().getCenter()
        );

        nameText.setPosition({416.f, 416.f});

        window.draw(nameText);

        sf::Text instruction(font, "ENTER = salvar    ESC = cancelar", 20);

        instruction.setOrigin(
            instruction.getLocalBounds().getCenter()
        );

        instruction.setPosition({416.f, 500.f});

        window.draw(instruction);

        return;
    }

    sf::Text title(font, "PLACARES", 50);

    title.setOrigin(title.getLocalBounds().getCenter());
    title.setPosition({416.f, 200.f});

    window.draw(title);

    float y = 416.f;

    for (std::size_t i = 0; i < scores.size(); ++i)
    {
        std::string text =
            std::to_string(i + 1) + " " +
            scores[i].playerName + " " +
            std::to_string(scores[i].score);

        sf::Text scoreText(font, text, 30);

        scoreText.setOrigin(
            scoreText.getLocalBounds().getCenter()
        );

        scoreText.setPosition({330.f, y});
        window.draw(scoreText);


        sf::RectangleShape editButton({80.f, 40.f});

        editButton.setPosition({
            520.f,
            y - 25.f
        });

        if (i == selectedIndex && selectedButton == 0)
        {
            editButton.setFillColor(sf::Color::Yellow);
        }
        else
        {
            editButton.setFillColor(sf::Color::White);
        }

        window.draw(editButton);


        sf::Text editText(font, "Editar", 20);

        editText.setFillColor(sf::Color::Black);

        editText.setPosition({
            535.f,
            y - 15.f
        });

        window.draw(editText);


        sf::RectangleShape deleteButton({80.f, 40.f});

        deleteButton.setPosition({
            610.f,
            y - 25.f
        });

        if (i == selectedIndex && selectedButton == 1)
        {
            deleteButton.setFillColor(sf::Color::Red);
        }
        else
        {
            deleteButton.setFillColor(sf::Color::White);
        }

        window.draw(deleteButton);


        sf::Text deleteText(font, "Deletar", 20);

        deleteText.setFillColor(sf::Color::Black);

        deleteText.setPosition({
            620.f,
            y - 15.f
        });

        window.draw(deleteText);

        y += 50.f;
    }
}

// Deletar Pontuação
void ScoreMenu::deleteScore(std::size_t index)
{
    if (index >= scores.size())
        return;

    scores.erase(scores.begin() + index);
    ScoreFile::save(scores);
    sortScores();


    if (scores.empty())
    {
        selectedIndex = 0;
    }
    else if (selectedIndex >= scores.size())
    {
        selectedIndex = scores.size() - 1;
    }
}

// Editar Pontuação
void ScoreMenu::editScore(std::size_t index)
{
    if (index >= scores.size())
        return;

    editing = true;
    editingIndex = index;

    editingName = scores[index].playerName;
}

// Eventos da Tela de Pontuações
int ScoreMenu::handleEvent(const sf::Event& event)
{
    if (editing)
    {
        if (const auto* textEntered = event.getIf<sf::Event::TextEntered>())
        {
            if (textEntered->unicode == 8)
            {
                if (!editingName.empty())
                {
                    editingName.pop_back();
                }
            }

            else if (textEntered->unicode >= 32 && textEntered->unicode < 127)
            {
                if (editingName.size() < 20)
                {
                    editingName += static_cast<char>(textEntered->unicode);
                }
            }
        }


        if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Enter)
            {
                if (!editingName.empty())
                {
                    scores[editingIndex].playerName = editingName;

                    ScoreFile::save(scores);

                    editing = false;

                    sortScores();

                    if (editingIndex >= scores.size())
                    {
                        selectedIndex = scores.size() - 1;
                    }
                    else
                    {
                        selectedIndex = editingIndex;
                    }
                }
            }

            else if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
            {
                editing = false;
            }
        }

        return 0;
    }


    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scancode::W)
        {
            if (selectedIndex > 0)
            {
                selectedIndex--;
            }
        }

        else if (keyPressed->scancode == sf::Keyboard::Scancode::S)
        {
            if (!scores.empty() && selectedIndex < scores.size() - 1)
            {
                selectedIndex++;
            }
        }

        else if (keyPressed->scancode == sf::Keyboard::Scancode::A)
        {
            selectedButton = 0;
        }

        else if (keyPressed->scancode == sf::Keyboard::Scancode::D)
        {
            selectedButton = 1;
        }

        else if (keyPressed->scancode == sf::Keyboard::Scancode::Enter)
        {
            if (scores.empty())
                return 0;

            if (selectedButton == 0)
            {
                editScore(selectedIndex);
            }
            else if (selectedButton == 1)
            {
                deleteScore(selectedIndex);
            }
        }

        else if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
        {
            return 1;
        }

    }
    return 0;
}

// Update Tela de Pontuações
void ScoreMenu::update()
{
    scores = ScoreFile::load();

    sortScores();

    if (scores.empty())
    {
        selectedIndex = 0;
    }
    else if (selectedIndex >= scores.size())
    {
        selectedIndex = scores.size() - 1;
    }
}