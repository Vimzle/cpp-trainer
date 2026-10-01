#include "Question.h"

Question::Question(
    std::string text,
    std::string answer,
    std::string topic,
    QuestionType type,
    std::vector<std::string> options
) : text(text), answer(answer),
    topic(topic), type(type), 
    options(options){}

std::string Question::getText() const{
    return text;
}
std::string Question::getAnswer() const{
    return answer;
}
std::string Question::getTopic() const{
    return topic;
}
QuestionType Question::getType() const{
    return type;
}
std::vector<std::string> Question::getOptions() const{
    return options;
}