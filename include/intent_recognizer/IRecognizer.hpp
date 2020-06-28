#pragma once

#include <ostream>
#include <string>

enum class Intent;

class IRecognizer {
public:
    virtual const Intent getIntent(const std::string& sentence) const = 0;
};

enum class Intent {
    GET_WEATHER = 1,
    GET_WEATHER_CITY = 2,
    CHECK_CALENDAR = 3,
    GET_FACT = 4,
};

inline std::ostream& operator<<(std::ostream& s, const Intent& i) {
    switch (i) {
        case Intent::GET_WEATHER:
            return s << "Get Weather";
        case Intent::GET_WEATHER_CITY:
            return s << "Get Weather City";
        case Intent::CHECK_CALENDAR:
            return s << "Check Calendar";
        case Intent::GET_FACT:
            return s << "Get Fact";
    }
}
