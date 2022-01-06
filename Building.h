#pragma once
#include "LeakedObjectDetector.h"
#include "Elevator.h"

struct Building
{
    Elevator elevatorA{"A1"};
    Elevator elevatorB{"B1"};
    bool isOpen;

    Building();
    ~Building();

    void closeBuilding();
    void openBuilding();
    bool buildingEmpty();
    void clearBuilding();
    void callElevatorAAndTakePassenger(int designatedFloor, double passengerWeight);
    void displayFloorOptions();

    JUCE_LEAK_DETECTOR(Building)
};
