#include "AdvancedRecognizer.hpp"

#include <sstream>
#include <map>
#include <vector>

AdvancedRecognizer::AdvancedRecognizer(const std::string &pathToModel)
    : m_model(fdeep::load_model(pathToModel))
{
}

const Intent AdvancedRecognizer::getIntent(const std::string &sentence) const
{
    std::map<std::string, int> bag = {
        {"weather", 0},
        {"in", 1},
        {"schedule", 2},
        {"appointment", 3},
        {"free", 4},
        {"fact", 5},
    };

    // compute feature vector
    std::vector<float> featureVector(6, 0);

    auto copy = sentence;
    std::transform(copy.begin(), copy.end(), copy.begin(), [](unsigned char c){ return std::tolower(c); });
    copy.erase(std::remove_if(copy.begin(), copy.end(), [](unsigned char x){return std::ispunct(x);}), copy.end());

    std::istringstream ss(copy);
    while (ss)
    {
        std::string word;
        ss >> word;

        if (bag.find(word) != bag.cend())
        {
            featureVector[bag[word]] += 1;
        }
    }

    // predict
    const auto result = m_model.predict({fdeep::tensor(fdeep::tensor_shape(static_cast<std::size_t>(6)), featureVector)});
    const auto resultAsVector = result[0].as_vector();

    const auto maxIt = std::max_element(resultAsVector->cbegin(), resultAsVector->cend());
    int index = std::distance(resultAsVector->cbegin(), maxIt);

    // Labels are from 0 to 3, the enum is from 0 to 4, with 0 meaning UNKNOWN.
    return static_cast<Intent>(index + 1);
}
