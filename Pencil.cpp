#include <iostream>
#include <string>
#include "PencilCase.h"

PencilCase::Pencil::Pencil() : canColor(false), shade("2HB")
{	
    std::cout << "****** Pencil Created ******" << std::endl;
}

PencilCase::Pencil::~Pencil()
{
    std::cout << "****** Pencil Destroyed ******" << std::endl;
}

void PencilCase::Pencil::printSharpness()
{
    std::cout << "The sharpness of this pencil: " << this->sharpness << std::endl;
}

void PencilCase::Pencil::sharpen(int rotations)
{
    if(!isSharp())
    {
        std::cout << "Sharpening..." << std::endl;
        for(int i = 0; i < rotations; ++i)
            sharpness += 0.067f;

        if(sharpness > 1.5f && sharpness < 2.5f)
        {
            sharpEnough = true;
            std::cout << "Pencil sharpened" << std::endl;
        }	
        else if(sharpness >= 2.5f)
        {
            sharpEnough = true;
            std::cout << "Super sharp!" << std::endl;
        }
        else
        {
            sharpEnough = false;
            std::cout << "Needs more sharpening" << std::endl;
        }	
    }
    else
    {
        std::cout << "Pencil sharp enough" << std::endl;
    }
}

void PencilCase::Pencil::writeSomething(std::string writing)
{
    std::cout << writing << std::endl;
    std::cout << "Finished writing" << std::endl;
    sharpness -= 0.089f;
}

bool PencilCase::Pencil::isSharp()
{
    return sharpEnough;
}
