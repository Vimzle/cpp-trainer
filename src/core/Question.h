#pragma once
#include <string>
#include <vector>

enum class QuestionType{
    multiple_choice,
    // code
};

class Question{
    std::string text;
    std::string answer;
    std::string topic;
    QuestionType type;
    std::vector<std::string> options;
public:
    Question(
        std::string text,
        std::string answer,
        std::string topic,
        QuestionType type,
        std::vector<std::string> options
    );
    std::string getText() const;
    std::string getAnswer() const;
    std::string getTopic() const;
    QuestionType getType() const;
    std::vector<std::string> getOptions() const;
};