cmake_minimum_required(VERSION 3.10)

project(intent_recognizer)

add_library(${PROJECT_NAME} STATIC
    recognizer/basic/BasicRecognizer.cpp
    recognizer/RecognizerFactory.cpp
)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

file(DOWNLOAD "https://raw.githubusercontent.com/catchorg/Catch2/master/single_include/catch2/catch.hpp" ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)

add_executable(${PROJECT_NAME}_test test/main.cpp)

target_include_directories(${PROJECT_NAME}_test SYSTEM
PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})
