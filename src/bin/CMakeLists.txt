cmake_minimum_required(VERSION 3.10)

project(app)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME}
INTERFACE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} intent_recognizer)
