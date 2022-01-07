#pragma once
#include "LeakedObjectDetector.h"

struct Elevator
{
    int highestFloor = 50;
    int lowestFloor = -2;
    double totalWeightCarried = 0.0;
    bool elevatorArrived = false;
    double maxWeight;
    int currentFloor;
    double lastUserWeight = 0;
    std::string name;

    Elevator(std::string name);
    ~Elevator();

    void goToFloor(int designatedFloor);
    void onboardPassenger(double userWeight);
    void offboardPassenger();
    bool canTakePassengerWeight(double userWeight);
    void updateWeightCarried(double userWeight, bool userExit);
    bool arrived();
    void printTotalWeightCarried();
	
    struct User
    {
        double weight;
        int destinationFloor;
        int currentFloor;
        bool isInsideElevator = false;
        bool canExit = true;

        User();
        ~User();

        void callElevator();
        void enterElevator();
        void setDestination(int newDestinationFloor);
        void exitElevator();
        void takeStairsInstead(int newDestinationFloor);
        void printPassengerWeight();

        JUCE_LEAK_DETECTOR(User)
    };

    JUCE_LEAK_DETECTOR(Elevator)
};
