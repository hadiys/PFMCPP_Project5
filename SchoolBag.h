#pragma once
#include "LeakedObjectDetector.h"
#include "PencilCase.h"

struct SchoolBag
{
    PencilCase schoolPencilCase;

    SchoolBag();
    ~SchoolBag();

    void packPencilCase();
    void unpackPencilCase();
    void checkForPencilCase();

    JUCE_LEAK_DETECTOR(SchoolBag)
};
