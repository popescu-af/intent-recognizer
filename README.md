# intent-recognizer

Intent recognizer is a project aimed at deriving intent from natural language. It is especially useful in human machine interaction,
where the human operating the machine can choose the next action the machine should perform based on natural language commands.
It can be used inside the car - for navigation, entertainment or obtaining information from the internet, for smart home appliances and so on.

## Development View

To build the app, please run
```bash
mkdir build && cd build
cmake ..
make

# to run the tests
./src/lib/intent_recognizer_test

# to run the app
./src/bin/app -h
# Allowed options:
#   -h, --help               show help message
#   -s, --sentence arg       user sentence to guess intent for
#   -t, --type arg (=basic)  type of recognizer to use, can be 'basic'

# example calls
./src/bin/app -s "What is the weather like today?"
Intent: Get Weather

./src/bin/app -s "What is the weather like in Paris today?"
Intent: Get Weather City

./src/bin/app -s "What's my schedule at 16:00 PM tomorrow?"
Intent: Check Calendar

./src/bin/app -s "Please elaborate an interesting fact."
Intent: Get Fact
```

## Logical View

The intent recognizer is built around a static library with the same name.

For the purpose of actually using the product, this repository includes a proof of concept CLI app.

![High-level view](doc/images/high-level.png)

### The `intent-recognizer` lib

Many things can be considered when writing a library that deals with noisy or rather uncertain input.
Among others, we could name a few

* multiple languages
* the spelling, which can be wrong

For the moment it supports English language only and no spelling fixing. 
Also for the sake of simplicity, all versions of the library will support a limited set of intents, e.g.

* Get Weather
* Get Weather City
* Check Calendar
* Get Fact

The architecture of the intent-recognizer lib is as follows

![Library architecture](doc/images/lib.png)

As you can see in the picture above, the user of the library can instantiate different types of recognizers, without being coupled to those respective implementations, by means of a common interface.



#### The `basic` version

The basic version of the intent recognizer is a very simple one. The "guessing" of intent is based
on simple regular expressions fit for the four recognizable intents.
This version is assuming the input is strictly matching the expected patterns (which are case insensitive), so it doesn't allow for much flexibility.

#### The `advanced` version

TODO
