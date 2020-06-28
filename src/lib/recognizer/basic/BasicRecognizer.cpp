#include "BasicRecognizer.hpp"

BasicRecognizer::BasicRecognizer()
    : m_intentMap{
        // insert patterns here
        {"weather", Intent::GET_WEATHER},
        {"Paris", Intent::GET_WEATHER_CITY},
        {"Berlin", Intent::GET_WEATHER_CITY},
        {"Amsterdam", Intent::GET_WEATHER_CITY},
        {"today", Intent::CHECK_CALENDAR},
        {"tomorrow", Intent::CHECK_CALENDAR},
        {"fact", Intent::GET_FACT},
    }
{
}


const Intent BasicRecognizer::getIntent(const std::string& sentence) const
{
    // TODO: pattern match the sentence.
    return Intent::GET_WEATHER;
}
