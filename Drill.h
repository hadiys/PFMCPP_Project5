#pragma once
#include "LeakedObjectDetector.h"

struct Drill
{
    bool isPlugged;
    bool drillbitAttached;
    int powerInWatts;
    char drillType = 'H';
    float rotationsToSecureBit = 0;
    float chuckTightness = 0.f;

    Drill();
    ~Drill();

    void drillHole(int holes);
    void unplug();
    void attachDrillbit(float drillbitWidth);
    void printDrillStatus();

    JUCE_LEAK_DETECTOR(Drill)
};
