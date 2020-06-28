#include <intent_recognizer/RecognizerFactory.hpp>

#include <popl.hpp>

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    popl::OptionParser op("Allowed options");
    auto help = op.add<popl::Switch>("h", "help", "show help message");
    auto sentence = op.add<popl::Value<std::string>>("s", "sentence", "user sentence to guess intent for");
    auto recognizerType = op.add<popl::Value<std::string>>("t", "type", "type of recognizer to use, can be 'basic'", "basic");
    op.parse(argc, argv);

    // print auto-generated help message
    if (help->is_set())
    {
        std::cout << op << "\n";
        return EXIT_SUCCESS;
    }

    if (!sentence->is_set())
    {
        std::cout << "No sentence provided\n";
        return EINVAL;
    }

    RecognizerPtr r;
    if (recognizerType->value() == "basic")
    {
        r = RecognizerFactory::createBasic();
    }
    else
    {
        std::cout << "Invalid recognizer type\n";
        return EINVAL;
    }

    std::cout << "Intent: " << r->getIntent(sentence->value()) << "\n";
    return EXIT_SUCCESS;
}
