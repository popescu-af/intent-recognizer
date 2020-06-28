#include <intent_recognizer/RecognizerFactory.hpp>

#include "basic/BasicRecognizer.hpp"

RecognizerPtr RecognizerFactory::createBasic() {
    return std::make_unique<BasicRecognizer>();
}
