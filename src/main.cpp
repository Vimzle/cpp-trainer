#include <vector>

#include "core/Question.h"
#include "telegram_bot/Bot.h"
#include "dotenv.h"

int main() {
    dotenv::env.load_dotenv();
    const auto token = std::string(std::getenv("BOT_TOKEN"));

    std::vector<Question> questions{
        Question(
            "Какой контейнер хранит элементы последовательно?", // text
            "vector", // answer
            "containers", // topic
            QuestionType::multiple_choice, // type
            {"map", "vector", "set", "unordered_map"} // options
        )
    };

    Bot bot(token, questions);
    bot.run();
    return 0;
}