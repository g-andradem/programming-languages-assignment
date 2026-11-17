#include "ScoreFile.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

void ScoreFile::save(const std::vector<ScoreEntry>& scores)
{
    std::ofstream file("data/scores.txt");

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para salvar os placares!\n";
        return;
    }

    for (const ScoreEntry& entry : scores) {
        file << entry.playerName << ";" << entry.score << "\n";
    }
}

std::vector<ScoreEntry> ScoreFile::load()
{
    std::vector<ScoreEntry> scores;

    std::ifstream file("data/scores.txt");

    if (!file.is_open()) {
        std::cerr << "Arquivo de placares nao encontrado.\n";
        return scores;
    }

    std::string line;

    while (std::getline(file, line)) {

        std::stringstream ss(line);

        std::string playerName;
        std::string scoreString;

        if (std::getline(ss, playerName, ';') &&
            std::getline(ss, scoreString)) {

            scores.push_back({
                playerName,
                std::stoi(scoreString)
            });
        }
    }
    return scores;
}

void ScoreFile::add(const std::string& playerName, int score)
{
    std::vector<ScoreEntry> scores = load();

    scores.push_back({playerName,score});

    std::sort(scores.begin(), scores.end(), [](const ScoreEntry& a, const ScoreEntry& b) {
        return a.score > b.score;
    });

    // Mantém somente os 5 melhores
    if (scores.size() > 5) {
        scores.resize(5);
    }

    save(scores);
}