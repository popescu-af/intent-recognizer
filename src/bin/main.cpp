#include <intent_recognizer/RecognizerFactory.hpp>

#include <iostream>
#include <string>

int main() {

    const std::string testSentence = "What is the weather like today?";

    auto r = RecognizerFactory::createBasic();

    std::cout << "Recognized: " << r->getIntent(testSentence);

    return 0;
}