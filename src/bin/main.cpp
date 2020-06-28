#include <intent_recognizer/RecognizerFactory.hpp>

#include <iostream>
#include <string>

int main()
{
    // TODO: parse input
    const std::string testSentence = "What is the weather like today?";

    auto r = RecognizerFactory::createBasic();
    std::cout << "Intent: " << r->getIntent(testSentence);

    return 0;
}