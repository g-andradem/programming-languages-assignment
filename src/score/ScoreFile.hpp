#pragma once

#include <vector>
#include <string>

struct ScoreEntry
{
    std::string playerName;
    int score;
};

class ScoreFile
{
public:
    static void save(const std::vector<ScoreEntry>& scores);
    static std::vector<ScoreEntry> load();
};