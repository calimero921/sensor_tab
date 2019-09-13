#include "readerState.h"

ReaderState::ReaderState(int nbCardReader)
{
    countCardReader = nbCardReader;
    readerState = (RfidData *)calloc(countCardReader, sizeof(RfidData));
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
    //Serial.println("ReaderState::setState:");
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
    //Serial.print("ReaderState::setState:return ");
    //Serial.println(result);
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
        Serial.print("toJsonString::jsonObject -> ");
        serializeJson(jsonObject, Serial);
        Serial.println();
        jsonArray.add(jsonObject);
    }

    uint16_t arraySize = jsonArray.memoryUsage();
    Serial.print("toJsonString::arraySize -> ");
    Serial.println(arraySize);

    char results[arraySize];
    serializeJson(jsonArray, results, arraySize);
    Serial.print("toJsonString::result -> ");
    Serial.println(results);
    return String(results);
}
