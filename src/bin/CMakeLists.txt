cmake_minimum_required(VERSION 3.10)

project(app)

add_executable(${PROJECT_NAME} main.cpp)

file(DOWNLOAD "https://raw.githubusercontent.com/badaix/popl/v1.2.0/include/popl.hpp" ${CMAKE_CURRENT_BINARY_DIR}/popl.hpp)

target_include_directories(${PROJECT_NAME} SYSTEM
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME} intent_recognizer)
