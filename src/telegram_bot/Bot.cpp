#include <tgbot/tgbot.h>

#include "Bot.h"

Bot::Bot(const std::string& token, const std::vector<Question>& questions) : token(token), quiz(questions){}

void Bot::run(){
    TgBot::Bot bot(token);

    auto keyboard = std::make_shared<TgBot::InlineKeyboardMarkup>();
    const Question& question = quiz.getCurrentQuestion();

    for(const std::string& option : question.getOptions()){
        auto button = std::make_shared<TgBot::InlineKeyboardButton>();
        button->text = option;
        button->callbackData = option;
        keyboard->inlineKeyboard.push_back({button});
    }
    // https://github.com/reo7sp/tgbot-cpp/blob/master/include/tgbot/ApiMethods.inc.h
    bot.getEvents().onCommand("start", [&bot,&keyboard,&question](std::shared_ptr<TgBot::Message> message) {
        bot.getApi().sendMessage(message->chat->id, question.getText(), nullptr, nullptr, keyboard);
    });

    // https://github.com/reo7sp/tgbot-cpp/blob/master/include/tgbot/Types.h
    bot.getEvents().onCallbackQuery([&bot,this,&keyboard](std::shared_ptr<TgBot::CallbackQuery> query) {
        std::string answer = query->data.value_or("");
        if (!query->message) return;
        const Question& question = quiz.getCurrentQuestion();
        if(answer == "show_answer"){
            std::string text = question.getText() + "\n\n";
            for (const std::string& option : question.getOptions()) {
                text += "• " + option + "\n";
            }
            text += "\nПравильный ответ: " + question.getAnswer();
            std::visit([&bot,&text](const auto& message) {
                bot.getApi().editMessageText(
                    text,
                    message->chat->id,
                    message->messageId,
                    "",
                    "",
                    nullptr,
                    nullptr);
                }, query->message->value
            );
            return;
        }
        bool is_correct = quiz.checkAnswer(answer);
        std::string text = question.getText() + "\n\n";
        for (const std::string& option : question.getOptions()) {
            if(option == answer){
                text += "✓ " + option + "\n";
            }else{
                text += "• " + option + "\n";
            }
        }
        std::shared_ptr<TgBot::InlineKeyboardMarkup> keyboard = nullptr;
        if (is_correct) {
            text += "\n✅ Верно!\n";
        } else {
            text += "\n❌ Неверно!";

            keyboard = std::make_shared<TgBot::InlineKeyboardMarkup>();
            auto button = std::make_shared<TgBot::InlineKeyboardButton>();
            button->text = "Показать правильный ответ";
            button->callbackData = "show_answer";
            keyboard->inlineKeyboard.push_back({button});
        }
        std::visit(
            [&bot, &text, &keyboard](const auto& message) {
                bot.getApi().editMessageText(
                    text,
                    message->chat->id,
                    message->messageId,
                    "",
                    "",
                    nullptr,
                    keyboard // std::shared_ptr<InlineKeyboardMarkup> replyMarkup = nullptr
                );
            },
            query->message->value
        );
    });

    TgBot::TgLongPoll longPoll(bot);   
    while (true) {
        longPoll.start();
    }
}
