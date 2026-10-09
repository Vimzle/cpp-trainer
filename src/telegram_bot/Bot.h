#pragma once

#include <string>
#include <vector>

#include "../core/Quiz.h"

class Bot{
public:
    Bot(const std::string& token, const std::vector<Question>& questions);
    void run();
private:
    std::string token;
    Quiz quiz;
};
