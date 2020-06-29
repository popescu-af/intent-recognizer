#include <intent_recognizer/RecognizerFactory.hpp>

#include "advanced/AdvancedRecognizer.hpp"
#include "basic/BasicRecognizer.hpp"

RecognizerPtr RecognizerFactory::createBasic()
{
    return std::make_unique<BasicRecognizer>();
}

RecognizerPtr RecognizerFactory::createAdvanced(const std::string& pathToModel)
{
    return std::make_unique<AdvancedRecognizer>(pathToModel);
}
