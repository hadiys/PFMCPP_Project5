#include <iostream>
#include <string>
#include "Building.h"

Building::Building()
{
    std::cout << "****** Building Created ******" << std::endl;
}

Building::~Building()
{
    closeBuilding();
    std::cout << "****** Building Destroyed ******" << std::endl;
}

void Building::displayFloorOptions()
{
    std::cout << "Highest floor: " << this->elevatorA.highestFloor << "   Lowest floor: " << this->elevatorA.lowestFloor << std::endl;
}

void Building::closeBuilding()
{
    if(buildingEmpty() && isOpen)
    {
        isOpen = false;
        std::cout << "Closing building. Elevators clear..." << std::endl;
    }
    else if(!isOpen)
    {
        std::cout << "Building already closed" << std::endl;
    }
    else
    {
        std::cout << "Cannot close building now.. There are still users in the elevator" << std::endl;
    }
}

void Building::openBuilding()
{
    if(!isOpen)
    {
        isOpen = true;
        std::cout << "Building is now open" << std::endl;
    }
    else
    {
        std::cout << "Building is already open" << std::endl;
    }
}

bool Building::buildingEmpty()
{
    if(elevatorA.totalWeightCarried == 0.0 && elevatorB.totalWeightCarried == 0.0)
        return true;

    return false;
}

void Building::clearBuilding()
{	
    if(elevatorA.totalWeightCarried > 0.0)
        elevatorA.updateWeightCarried(elevatorA.lastUserWeight, false);
    else if(elevatorB.totalWeightCarried > 0.0)
        elevatorB.updateWeightCarried(elevatorB.lastUserWeight, false);
    else
        std::cout << "No one in the building...";

    std::cout << "Building cleared." << std::endl;
}

void Building::callElevatorAAndTakePassenger(int designatedFloor, double userWeight)
{
    if(isOpen)
    {
        std::cout << "Calling elevator " << elevatorA.name << std::endl;
        elevatorA.goToFloor(designatedFloor);
        elevatorA.onboardPassenger(userWeight);
    }
    else
    {	
        std::cout << "Cannot call elevator, building not open yet" << elevatorA.name << std::endl;
    }
}
