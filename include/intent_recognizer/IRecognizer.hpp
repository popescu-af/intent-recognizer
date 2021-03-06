#pragma once

#include <ostream>
#include <string>

enum class Intent;

// IRecognizer is the interface for intent recognizer implementations.
class IRecognizer {
public:
    virtual const Intent getIntent(const std::string& sentence) const = 0;

    virtual ~IRecognizer() {};
};

// Intent is the enum for supported intents.
enum class Intent {
    UNKNOWN = 0,
    GET_WEATHER = 1,
    GET_WEATHER_CITY = 2,
    CHECK_CALENDAR = 3,
    GET_FACT = 4,
};

// Operator overload for feeding an Intent value to a stream.
inline std::ostream& operator<<(std::ostream& s, const Intent& i) {
    switch (i) {
        case Intent::UNKNOWN:
            return s << "Unknown";
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
