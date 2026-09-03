#pragma once

#include <vector>
#include "ScoreEntry.hpp"

class ScoreFile
{
public:
    static void save(const std::vector<ScoreEntry>& scores);
    static std::vector<ScoreEntry> load();
};