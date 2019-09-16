/*
*/

#include "readerState.h"

ReaderState::ReaderState(int nbCardReader)
{
    countCardReader = nbCardReader;
    readerState = (RfidData *)calloc(countCardReader, sizeof(RfidData));
    // Initialisation du tableau
    for(uint16_t i = 0; i < countCardReader; i++)
    {
        readerState[i] = RfidData();
    }
}

ReaderState::~ReaderState()
{
    free(readerState);
}

uint16_t ReaderState::count()
{
    return countCardReader;
}

boolean ReaderState::setState(uint16_t reader, RfidData *data)
{
#ifdef DEBUG
    Serial.println("ReaderState::setState:");
#endif
    boolean result = true;
    if (data->error().length() > 0)
    {
        // do not change state if an error occurs
        result = false;
    }
    else
    {
        if (readerState[reader].equals(data))
        {
            // do not change state if data is the same
            result = false;
        }
        else
        {
            // update state if data is different
            readerState[reader].set(data);
        }
    }
#ifdef DEBUG
    Serial.print("ReaderState::setState:return ");
    Serial.println(result);
#endif
    return result;
}

RfidData ReaderState::getState(uint16_t reader)
{
    return readerState[reader];
}

String ReaderState::toJsonString(boolean colorSelector, boolean formatSelector)
{
    StaticJsonDocument<1024> jsonArray;

    for (int reader = 0; reader < countCardReader; reader++)
    {
        StaticJsonDocument<256> jsonObject;
        jsonObject["reader"] = reader;
        if (colorSelector)
        {
            jsonObject["color"] = readerState[reader].color();
        }
        if (formatSelector)
        {
            jsonObject["format"] = readerState[reader].format();
        }
#ifdef DEBUG
        Serial.print("toJsonString::jsonObject -> ");
        serializeJson(jsonObject, Serial);
        Serial.println();
#endif
        jsonArray.add(jsonObject);
    }
    uint16_t arraySize = jsonArray.memoryUsage();
#ifdef DEBUG
    Serial.print("toJsonString::arraySize -> ");
    Serial.println(arraySize);
#endif
    char results[arraySize];
    serializeJson(jsonArray, results, arraySize);
#ifdef DEBUG
    Serial.print("toJsonString::result -> ");
    Serial.println(results);
#endif
    return String(results);
}
