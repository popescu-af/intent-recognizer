#pragma once

#include <intent_recognizer/IRecognizer.hpp>

#include <memory>

// RecognizerPtr is the type for polymorphic pointers to recognizers.
typedef std::unique_ptr<IRecognizer> RecognizerPtr;

// RecognizerFactory creates instances of the existing recognizer classes.
class RecognizerFactory {
public:
    // createBasic creates a basic recognizer.
    static RecognizerPtr createBasic();
};
