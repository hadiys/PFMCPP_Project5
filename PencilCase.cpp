#include <iostream>
#include <string>
#include "PencilCase.h"

PencilCase::PencilCase() : maxItemsToHold(20), isOpen(false)
{
    std::cout << "****** PencilCase Created ******" << std::endl;	
}

PencilCase::~PencilCase()
{
    std::cout << "****** PencilCase Destroyed ******" << std::endl;
}

void PencilCase::printNumContainedItems()
{
    std::cout << "Items in the pencilcase: " << this->numItemsAdded << std::endl;
}

void PencilCase::open()
{
    isOpen = true;
}

void PencilCase::close()
{
    isOpen = false;
}

void PencilCase::addItems(int itemsToAdd)
{
    if(isOpen)
    {
        std::cout << "Adding items to pencilcase..." << std::endl;

        while(numItemsAdded < maxItemsToHold && itemsToAdd > 0)
        {
            ++numItemsAdded;
            --itemsToAdd;
        }
        (numItemsAdded == maxItemsToHold) ?  std::cout << "Pencilcase full!" << std::endl : std::cout << numItemsAdded << " items added..." << std::endl;
    }
    else
    {
        std::cout << "Open the pencilcase first" << std::endl;
    }
}

void PencilCase::removeItems(int itemsToRemove)
{
    if(itemsToRemove > 0)
    {
        if(isOpen && numItemsAdded > 0)
        {
            std::cout << "Items leaving the pencilcase..." << std::endl;

            while(numItemsAdded > 0 && itemsToRemove > 0)
            {
                --numItemsAdded;
                --itemsToRemove;
            }
            std::cout << numItemsAdded << " items remaining" << std::endl;
        }
        else
        {
            std::cout << "Pencilcase is closed or nothing inside" << std::endl;
        }
    }
    else
    {
        std::cout << "Can't remove " << itemsToRemove << " items"  << std::endl;
    }
}
