#pragma once

#include <intent_recognizer/IRecognizer.hpp>

#include <regex>
#include <vector>

// BasicRecognizer is a recognizer which works by simply matching the
// input sentence to a series of regular expressions. The first one that matches
// is considered a fit and the corresponding intent is returned.
class BasicRecognizer : public IRecognizer {
public:
    BasicRecognizer();

    const Intent getIntent(const std::string& sentence) const override;

    ~BasicRecognizer() override = default;

private:
    std::vector<std::pair<std::regex, Intent>> m_intentMap; // regular expressions to check
};
