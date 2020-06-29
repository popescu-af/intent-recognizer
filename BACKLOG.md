# Backlog

## Use configs for both recognizers
This will remove hardcoded stuff and the need to recompile when

- a regex is changed (basic)
- the bag of words is changed

## Improve advanced recognizer build system

- define cmake custom target for training and obtaining the model
- define config for both training and production lib. This will ensure both components use the
same bag of words.

## Other improvements

- quality of the advanced recognizer model, which is over fit to a really small set of words
- tests for the advanced model
- performance tests
- CI scripts, Jenkinsfile or similar
- Dockerfile
- CPack for packing the app
