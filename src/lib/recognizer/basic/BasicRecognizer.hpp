#pragma once

#include <intent_recognizer/IRecognizer.hpp>

#include <map>

class BasicRecognizer : public IRecognizer {
public:
    BasicRecognizer();

    const Intent getIntent(const std::string& sentence) const override;

private:
    std::map<std::string, Intent> m_intentMap;
};
