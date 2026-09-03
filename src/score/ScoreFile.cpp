#include "ScoreFile.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

void ScoreFile::save(const std::vector<ScoreEntry>& scores)
{
    std::ofstream file("data/scores.txt");

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para salvar os placares!\n";
        return;
    }

    for (const ScoreEntry& score : scores) {
        file << score.playerName << ";" << score.score << "\n";
    }

    file.close();
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

            int score = std::stoi(scoreString);

            scores.push_back({
                playerName,
                score
            });
        }
    }

    file.close();

    return scores;
}