cmake_minimum_required(VERSION 3.20)

project(cpp-trainer CXX)

find_package(TgBot CONFIG REQUIRED)

add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/third_party/cpp-dotenv
    ${CMAKE_CURRENT_BINARY_DIR}/cpp-dotenv
)

add_executable(cpp-trainer src/main.cpp src/core/Question.cpp src/core/Quiz.cpp)

target_link_libraries(cpp-trainer PRIVATE tgbot::tgbot cpp_dotenv)