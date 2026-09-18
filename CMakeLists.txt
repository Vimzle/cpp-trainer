cmake_minimum_required(VERSION 3.20)

project(cpp-trainer CXX)

find_package(TgBot CONFIG REQUIRED)

add_executable(cpp-trainer src/main.cpp)

target_link_libraries(cpp-trainer PRIVATE tgbot::tgbot)