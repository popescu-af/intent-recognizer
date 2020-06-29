#pragma once

#include <intent_recognizer/IRecognizer.hpp>

#include <fdeep/fdeep.hpp>

// AdvancedRecognizer is a recognizer which uses a pre-trained, simple neural network
// for guessing the intent in the given sentence.
class AdvancedRecognizer : public IRecognizer {
public:
    AdvancedRecognizer(const std::string& pathToModel);

    const Intent getIntent(const std::string& sentence) const override;

    ~AdvancedRecognizer() override = default;

private:
    fdeep::model m_model;
};
