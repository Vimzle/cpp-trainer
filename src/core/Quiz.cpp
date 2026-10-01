#include "Quiz.h"

Quiz::Quiz(const std::vector<Question>& questions)
    : questions(questions),
      currentQuestionIndex(0),
      score(0){}

const Question& Quiz::getCurrentQuestion() const{
    return questions[currentQuestionIndex];
}

bool Quiz::checkAnswer(const std::string& answer){
    if(answer == questions[currentQuestionIndex].getAnswer()){
        ++score;
        return true;
    }
    return false;
}

void Quiz::nextQuestion(){
    ++currentQuestionIndex;
}

int Quiz::getScore() const{
    return score;
}

bool Quiz::isFinished() const{
    return currentQuestionIndex >= questions.size();
}