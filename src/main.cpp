#include <iostream>
#include <vector>
#include "core/Question.h"
#include "core/Quiz.h"

int main() {
    std::vector<Question> questions{
        Question(
            "Какой контейнер хранит элементы последовательно?", // text
            "vector", // answer
            "containers", // topic
            QuestionType::multiple_choice, // type
            {"map", "vector", "set", "unordered_map"} // options
        )
    };

    Quiz quiz(questions);
    const Question& current = quiz.getCurrentQuestion();

    std::cout << current.getText() << '\n';

    for (const std::string& option : current.getOptions()) {
        std::cout << option << '\n';
    }
}