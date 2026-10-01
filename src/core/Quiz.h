#pragma once
#include <vector>

#include "Question.h"

class Quiz{
    std::vector<Question> questions;  
    int currentQuestionIndex;
    int score;

public:
    Quiz(const std::vector<Question>& questions);
    const Question& getCurrentQuestion() const;
    bool checkAnswer(const std::string& answer);
    void nextQuestion();
    int getScore() const;
    bool isFinished() const;
};