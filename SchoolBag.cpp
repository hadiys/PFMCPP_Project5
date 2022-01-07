#pragma once
#include <iostream>
#include <string>
#include "SchoolBag.h"

SchoolBag::SchoolBag()
{
    std::cout << "****** SchoolBag Created ******" << std::endl;
}

SchoolBag::~SchoolBag()
{
    unpackPencilCase();
    std::cout << "****** SchoolBag Destroyed ******" << std::endl;
}

void SchoolBag::checkForPencilCase()
{
    (this->schoolPencilCase.inSchoolBag) ? std::cout << "Pencilcase is in schoolbag" << std::endl : std::cout << "Pencilcase is not in schoolbag" << std::endl;
}

void SchoolBag::packPencilCase()
{
    if(!schoolPencilCase.inSchoolBag && !schoolPencilCase.isOpen)
    {
        schoolPencilCase.inSchoolBag = true;
        std::cout << "Packing the pencilcase... Good to go!" << std::endl;
    }
    else if(schoolPencilCase.inSchoolBag)
    {
        std::cout << "Pencilcase already packed" << std::endl;
    }
    else
    {
        schoolPencilCase.removeItems(schoolPencilCase.maxItemsToHold);
        std::cout << "** You forgot to close your pencilcase!! **" << std::endl;
    }
}

void SchoolBag::unpackPencilCase()
{
    if(!schoolPencilCase.inSchoolBag)
    {
        std::cout << "Pencilcase already unpacked or not in schoolbag" << std::endl;
    }
    else
    { 
        schoolPencilCase.inSchoolBag = false;
        std::cout << "Unpacked the pencilcase" << std::endl;
    }
}
