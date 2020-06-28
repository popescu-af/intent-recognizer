#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <intent_recognizer/RecognizerFactory.hpp>

TEST_CASE("Basic recognizer works as expected", "[basic_recognizer]")
{
    auto r = RecognizerFactory::createBasic();

    // Examples from the requirement
    REQUIRE(r->getIntent("What is the weather like today?") == Intent::GET_WEATHER);
    REQUIRE(r->getIntent("What is the weather like in Paris today?") == Intent::GET_WEATHER_CITY);
    REQUIRE(r->getIntent("What is the weather like in New York today?") == Intent::GET_WEATHER_CITY);
    REQUIRE(r->getIntent("Am I free at 13:00 PM tomorrow?") == Intent::CHECK_CALENDAR);
    REQUIRE(r->getIntent("Tell me an interesting fact.") == Intent::GET_FACT);

    // Some other variations of input (slightly different).
    REQUIRE(r->getIntent("What's the weather like?") == Intent::GET_WEATHER);
    REQUIRE(r->getIntent("What is the weather like in two days?") == Intent::GET_WEATHER);
    REQUIRE(r->getIntent("What's the weather like in Paris tomorrow?") == Intent::GET_WEATHER_CITY);
    REQUIRE(r->getIntent("What is the weather like in New York?") == Intent::GET_WEATHER_CITY);
    REQUIRE(r->getIntent("Am I free tomorrow?") == Intent::CHECK_CALENDAR);
    REQUIRE(r->getIntent("What's my schedule today?") == Intent::CHECK_CALENDAR);
    REQUIRE(r->getIntent("I'd like to hear an interesting fact.") == Intent::GET_FACT);
}
