#pragma once
#include "LeakedObjectDetector.h"

struct PencilCase
{
    char openMechanism = 'Z';
    int maxItemsToHold;
    bool isOpen;
    int numItemsAdded = 0;
    bool inSchoolBag = false;

    PencilCase();
    ~PencilCase();

    void open(); 
    void close();	
    void addItems(int itemsToAdd = 1);
    void removeItems(int itemsToRemove);
    void printNumContainedItems();
	
    struct Pencil
    {
        float sharpness = 1.5f;
        bool sharpEnough = false;
        std::string color = "Brown";
        bool canColor;
        std::string shade;
        
        Pencil();
        ~Pencil();
        
        void sharpen(int rotations);
        void writeSomething(std::string writing);
        bool isSharp();
        void printSharpness();

        JUCE_LEAK_DETECTOR(Pencil)
    };

    JUCE_LEAK_DETECTOR(PencilCase)
};
