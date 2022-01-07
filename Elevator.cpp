#include <iostream>
#include <string>
#include "Elevator.h"

Elevator::Elevator(std::string elevatorName) : maxWeight(800.0), currentFloor(0), name(elevatorName)
{
    std::cout << "****** Elevator Created & Ready for Service ******" << std::endl;
}

Elevator::~Elevator()
{
    std::cout << "****** Elevator " << name << " Destroyed & Out of Service ******" << std::endl;
}

void Elevator::printTotalWeightCarried()
{
    std::cout << "Passengers in this elevator weigh " << this->totalWeightCarried << "kg in total" << std::endl;
}

void Elevator::goToFloor(int designatedFloor)
{   
    if(designatedFloor <= highestFloor && designatedFloor >= lowestFloor)
    {
        std::cout << "On the way to floor " << designatedFloor << std::endl;	

        while(designatedFloor != currentFloor)
            (designatedFloor > currentFloor) ? ++currentFloor : --currentFloor; 	

        elevatorArrived = true;

        std::cout << "Elevator " << name << " arrived to floor " << currentFloor << std::endl;
    }
    else
    {
        elevatorArrived = false;
        std::cout << "Floor " << designatedFloor << " does not exist!" << std::endl;
    }
}

void Elevator::onboardPassenger(double userWeight)
{
    if(arrived() && canTakePassengerWeight(userWeight))
        updateWeightCarried(userWeight, true);
    else
        std::cout << "This passenger cannot board the elevator" << std::endl;
}

void Elevator::offboardPassenger()
{
    if(arrived() && lastUserWeight > 0)
        updateWeightCarried(lastUserWeight, false);
    else
        std::cout << "The elevator has not arrived to a floor yet or no passengers inside" << std::endl;
}

void Elevator::updateWeightCarried(double userWeight, bool goingInside)
{
    if(goingInside)
    {
        lastUserWeight = userWeight;
        totalWeightCarried += lastUserWeight;
        std::cout << "Passenger onboarded" << std::endl;
    }
    else
    {
        totalWeightCarried -= lastUserWeight;
        std::cout << "Passenger offboarded" << std::endl;
    }
}

bool Elevator::canTakePassengerWeight(double userWeight)
{
    if((userWeight + totalWeightCarried) > maxWeight)
        return false;
        
    return true;
}

bool Elevator::arrived()
{
    return elevatorArrived;
}
