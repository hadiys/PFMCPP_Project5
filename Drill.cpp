#pragma once
#include <iostream>
#include <string>
#include "Drill.h"

Drill::Drill() : isPlugged(true), drillbitAttached(false), powerInWatts(3600) 
{
    std::cout << "****** Drill Created ******" << std::endl;
}

Drill::~Drill()
{
    std::cout << "****** Drill Destroyed ******" << std::endl;
}

void Drill::printDrillStatus()
{
    (this->isPlugged && this->drillbitAttached) ? std::cout << "The drill is ready to work" << std::endl : std::cout << "The drill is not ready to work" << std::endl;
}

void Drill::drillHole(int holes)
{
    if(isPlugged && drillbitAttached && holes > 0)
    {
        std::cout << "Drilling holes..." << std::endl;
        std::cout << "Drilling done!!" << std::endl;
    }
    else if(holes < 1)
    {
        std::cout << "You can't drill " << holes << " holes..." << std::endl;
    }
    else
    { 
        std::cout << "Whoops! Check if your drill is ready" << std::endl;
    }
}

void Drill::unplug()
{
    isPlugged = false;
    std::cout << "Unplugged drill" << std::endl;
}

void Drill::attachDrillbit(float drillbitWidth)
{
    rotationsToSecureBit = 0.8f * drillbitWidth;

    std::cout << "Securing drill bit... " << std::endl;

    for(int i = 0; i < int(rotationsToSecureBit); ++i)
        chuckTightness += rotationsToSecureBit;

    drillbitAttached = true;	

    std::cout << "Drillbit secured" << std::endl;
}
