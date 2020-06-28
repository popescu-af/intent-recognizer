#include "BasicRecognizer.hpp"

#include <regex>

BasicRecognizer::BasicRecognizer()
    : m_intentMap{
          {R"(What is the weather like( today| tomorrow| in (two|three) days)?\?)", Intent::GET_WEATHER},
          {R"(What is the weather like in (Paris|New York|Berlin) ( today| tomorrow| in (two|three) days)?\?)", Intent::GET_WEATHER_CITY},
          {R"((What('s| is) my schedule|Am I free)( at .*)?( today| tomorrow| in (two|three) days)?\?)", Intent::CHECK_CALENDAR},
          {R"(.*interesting fact.*)", Intent::GET_FACT},
          {R"(.*)", Intent::UNKNOWN},
      }
{
}

const Intent BasicRecognizer::getIntent(const std::string &sentence) const
{
    const auto foundIt = std::find_if(m_intentMap.cbegin(), m_intentMap.cend(), [&sentence](const auto &entry) { return std::regex_match(sentence, entry.first) });

    // Double-check, although given the hard-coded regexes, at least the last one will always match.
    if (foundIt != m_intentMap.cend())
    {
        return foundIt->second;
    }
    return Intent::UNKNOWN;
}
