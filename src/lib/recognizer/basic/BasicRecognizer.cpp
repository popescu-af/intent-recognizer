#include "BasicRecognizer.hpp"

BasicRecognizer::BasicRecognizer()
    : m_intentMap{
        // TODO: these should be configurable
          {std::regex(R"(What('s| is) the weather like( today| tomorrow| in (two|three) days)?\?)"), Intent::GET_WEATHER},
          {std::regex(R"(What('s| is) the weather like in (Paris|New York|Berlin)( today| tomorrow| in (two|three) days)?\?)"), Intent::GET_WEATHER_CITY},
          {std::regex(R"((What('s| is) my schedule|Am I free)( at .*)?( today| tomorrow| in (two|three) days)?\?)"), Intent::CHECK_CALENDAR},
          {std::regex(R"(.*interesting fact.*)"), Intent::GET_FACT},
          {std::regex(R"(.*)"), Intent::UNKNOWN},
      }
{
}

const Intent BasicRecognizer::getIntent(const std::string &sentence) const
{
    const auto foundIt = std::find_if(m_intentMap.cbegin(), m_intentMap.cend(), [&sentence](const auto &entry) -> bool { return std::regex_match(sentence, entry.first); });

    // Double-check, although given the hard-coded regexes, at least the last one will always match.
    if (foundIt != m_intentMap.cend())
    {
        return foundIt->second;
    }
    return Intent::UNKNOWN;
}
