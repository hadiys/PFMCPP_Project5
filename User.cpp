#include <iostream>
#include <string>
#include "Elevator.h"

Elevator::User::User() : weight(100.0), destinationFloor(0), currentFloor(0)
{
    std::cout << "****** User Created ******" << std::endl;
}

Elevator::User::~User()
{
    std::cout << "****** User Destroyed ******" << std::endl;
}

void Elevator::User::printPassengerWeight()
{
    std::cout << "This passenger weighs: " << this->weight << "kg" << std::endl;
}

void Elevator::User::callElevator()
{
    if(!isInsideElevator)
        std::cout << "Calling elevator..." << std::endl;
    else
        std::cout << "Wait till you exit the elevator" << std::endl;
}

void Elevator::User::enterElevator()
{
    if(!isInsideElevator)
    {
        isInsideElevator = true;
        std::cout << "You have entered the elevator, now go to a floor" << std::endl;
    }
    else
    {
        std::cout << "You are already inside the elevator" << std::endl;
    }
}

void Elevator::User::setDestination(int newDestinationFloor)
{
    destinationFloor = newDestinationFloor;
    std::cout << "Destination floor " << destinationFloor << std::endl;
}

void Elevator::User::exitElevator()
{
    std::cout << "Exiting... ";

    if(isInsideElevator)
    {
        isInsideElevator = false;
        std::cout << "You have exited the elevator" << std::endl;
    }    
    else
    {
        std::cout << "You are not in an elevator yet!" << std::endl;
    }
}

void Elevator::User::takeStairsInstead(int newDestinationFloor)
{
    destinationFloor = newDestinationFloor;

    while(destinationFloor != currentFloor)
        (destinationFloor > currentFloor) ? ++currentFloor : --currentFloor; 

    std::cout << "You have taken the stairs to floor " << currentFloor << std::endl;
}
