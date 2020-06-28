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
