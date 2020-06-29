import numpy as np
import pandas as pd
import re

from tensorflow.keras.layers import Input, Dense
from tensorflow.keras.models import Model


# bag of words used as features
bag = {
    "weather": 0,
    "in": 1,
    "schedule": 2,
    "appointment": 3,
    "free": 4,
    "fact": 5,
}


def build_feature_vector(sentence):
    # remove punctuation and split sentence into words
    sentence = re.sub(r'[^\w\s]', '', sentence)
    words = sentence.split(" ")

    # count words in bag
    feature_vector = [0] * len(bag)

    for w in words:
        if w in bag:
            feature_vector[bag[w]] += 1

    return feature_vector


def build_features():
    # prepare features
    df = pd.read_csv("sentences.csv")

    features = []
    labels = []
    combined = []

    for (_, sentence, intent) in df.itertuples():
        f = build_feature_vector(sentence)
        features.append(f)

        l = [int(i==intent) for i in range(4)]
        labels.append(l)

        c = f.copy()
        c += l
        combined.append(c)

    column_names = list(bag.keys())
    column_names += ["get_weather", "get_weather_city", "check_calendar", "get_fact"]

    df = pd.DataFrame(data=combined, columns=column_names)
    df.to_csv("features.csv", index=None)

    return features, labels


features, labels = build_features()

# define NN
inputs = Input(shape=(len(features[0]),))
x = Dense(50, activation='relu')(inputs)
predictions = Dense(4, activation='softmax')(x)

# fit
model = Model(inputs=inputs, outputs=predictions)
model.compile(loss='categorical_crossentropy', optimizer='nadam')
model.fit(features, labels, epochs=2500)

# Example:
# model.fit(
#     np.asarray([[1, 2, 3, 4], [2, 3, 4, 5]]),
#     np.asarray([[1, 0, 0], [0, 0, 1]]), epochs=10)

# save model
model.save('keras_model.h5', include_optimizer=False)
