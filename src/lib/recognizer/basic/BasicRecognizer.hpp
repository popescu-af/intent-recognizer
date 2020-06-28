#pragma once

#include <intent_recognizer/IRecognizer.hpp>

#include <regex>
#include <vector>

class BasicRecognizer : public IRecognizer {
public:
    BasicRecognizer();

    const Intent getIntent(const std::string& sentence) const override;

private:
    std::vector<std::pair<std::regex, Intent>> m_intentMap;
};
