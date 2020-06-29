cmake_minimum_required(VERSION 3.10)

project(intent_recognizer)

include(ExternalProject)

ExternalProject_Add(frugally_deep
    GIT_REPOSITORY "https://github.com/Dobiasd/frugally-deep.git"
    SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/frugally_deep
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    # GIT_TAG
)

ExternalProject_Add(functional_plus
    GIT_REPOSITORY "https://github.com/Dobiasd/FunctionalPlus.git"
    SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/functional_plus
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    # GIT_TAG
)

ExternalProject_Add(eigen
    GIT_REPOSITORY "https://gitlab.com/libeigen/eigen.git"
    SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/eigen
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    # GIT_TAG
)

file(DOWNLOAD "https://raw.githubusercontent.com/nlohmann/json/v3.8.0/single_include/nlohmann/json.hpp" ${CMAKE_CURRENT_BINARY_DIR}/nlohmann/json.hpp)

add_library(${PROJECT_NAME} STATIC
    recognizer/advanced/AdvancedRecognizer.cpp
    recognizer/basic/BasicRecognizer.cpp
    recognizer/RecognizerFactory.cpp
)

add_dependencies(${PROJECT_NAME} frugally_deep functional_plus eigen)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/frugally_deep/include
    ${CMAKE_CURRENT_BINARY_DIR}/functional_plus/include
    ${CMAKE_CURRENT_BINARY_DIR}/eigen
)

file(DOWNLOAD "https://raw.githubusercontent.com/catchorg/Catch2/v2.12.2/single_include/catch2/catch.hpp" ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)

add_executable(${PROJECT_NAME}_test test/main.cpp)

target_include_directories(${PROJECT_NAME}_test SYSTEM
PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})
