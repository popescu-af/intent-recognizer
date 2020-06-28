#pragma once

#include <intent_recognizer/IRecognizer.hpp>

#include <memory>

typedef std::unique_ptr<IRecognizer> RecognizerPtr;

class RecognizerFactory {
public:
    // createBasic creates a basic recognizer.
    static RecognizerPtr createBasic();
};
