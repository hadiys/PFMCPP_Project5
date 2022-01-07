////
/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */
#pragma once
#include <iostream>
#include <string>
#include "Wrappers.h"
#include "Building.h"
#include "Drill.h"
#include "Elevator.h"
#include "PencilCase.h"
#include "SchoolBag.h"

int main()
{
    // ============== Pencil ================================
    
    std::cout << std::endl;
    
    PencilCase::Pencil pencil1;
    pencil1.sharpen(4);
    pencil1.writeSomething("Writing some text	Writing some text	Writing some text");
    std::cout << "The sharpness of this pencil: " << pencil1.sharpness << std::endl;
    pencil1.printSharpness();

    std::cout << std::endl;

    PencilCase::Pencil pencil2;
    pencil2.writeSomething("Now let's try this other pencil with more writing... Writing some text	Writing some text	Writing some text	Writing some text");
    std::cout << "The sharpness of this pencil: " << pencil2.sharpness << std::endl;
    pencil2.printSharpness();
    pencil2.sharpen(3);

    std::cout << std::endl;
    
    // ============== PencilCase ===========================
   
    PencilCaseWrapper pencilCase1(new PencilCase());
    pencilCase1.pointerToPC->open();
    pencilCase1.pointerToPC->close();
    pencilCase1.pointerToPC->open();
    pencilCase1.pointerToPC->addItems(12);
    pencilCase1.pointerToPC->removeItems(8);
    std::cout << "Items in the pencilcase: " << pencilCase1.pointerToPC->numItemsAdded << std::endl;
    pencilCase1.pointerToPC->printNumContainedItems();

    std::cout << std::endl;

    PencilCaseWrapper pencilCase2(new PencilCase());
    pencilCase2.pointerToPC->addItems(25);
    pencilCase2.pointerToPC->open();
    pencilCase2.pointerToPC->addItems(25);
    pencilCase2.pointerToPC->removeItems(1);
    std::cout << "Items in the pencilcase: " << pencilCase2.pointerToPC->numItemsAdded << std::endl;
    pencilCase2.pointerToPC->printNumContainedItems();

    std::cout << std::endl;
    
    // ============== SchoolBag ==========================
    
    SchoolBagWrapper schoolbag1(new SchoolBag());
    schoolbag1.pointerToSB->schoolPencilCase.open();
    schoolbag1.pointerToSB->schoolPencilCase.addItems(15);
    schoolbag1.pointerToSB->packPencilCase();
    schoolbag1.pointerToSB->schoolPencilCase.addItems(15);
    schoolbag1.pointerToSB->packPencilCase();
    (schoolbag1.pointerToSB->schoolPencilCase.inSchoolBag) ? std::cout << "Pencilcase is in schoolbag" << std::endl : std::cout << "Pencilcase is not in schoolbag" << std::endl;
    schoolbag1.pointerToSB->checkForPencilCase();

    std::cout << std::endl;

    SchoolBagWrapper schoolbag2(new SchoolBag());
    schoolbag2.pointerToSB->schoolPencilCase.open();
    schoolbag2.pointerToSB->schoolPencilCase.addItems(15);
    schoolbag2.pointerToSB->schoolPencilCase.close();
    (schoolbag2.pointerToSB->schoolPencilCase.inSchoolBag) ? std::cout << "Pencilcase is in schoolbag" << std::endl : std::cout << "Pencilcase is not in schoolbag" << std::endl;
    schoolbag2.pointerToSB->checkForPencilCase();

    std::cout << std::endl;

    // ============== Drill =======================
    
    DrillWrapper drill1(new Drill());
    drill1.pointerToDrill->unplug();
    drill1.pointerToDrill->attachDrillbit(3.f);
    drill1.pointerToDrill->drillHole(5);
    (drill1.pointerToDrill->isPlugged && drill1.pointerToDrill->drillbitAttached) ? std::cout << "The drill is ready to work" << std::endl : std::cout << "The drill is not ready to work" << std::endl;
    drill1.pointerToDrill->printDrillStatus();

    std::cout << std::endl;

    DrillWrapper drill2(new Drill());
    drill2.pointerToDrill->drillHole(20);
    drill2.pointerToDrill->attachDrillbit(5.8f);
    drill2.pointerToDrill->drillHole(20);
    (drill2.pointerToDrill->isPlugged && drill2.pointerToDrill->drillbitAttached) ? std::cout << "The drill is ready to work" << std::endl : std::cout << "The drill is not ready to work" << std::endl;
    drill2.pointerToDrill->printDrillStatus();
    drill2.pointerToDrill->unplug();

    std::cout << std::endl;
    
    // ============== Elevator & User ============
    
    ElevatorWrapper ev1(new Elevator("A1"));
    Elevator::User evu1;
    evu1.callElevator();
    ev1.pointerToEV->goToFloor(evu1.currentFloor);
    ev1.pointerToEV->onboardPassenger(evu1.weight);
    evu1.enterElevator();
    evu1.setDestination(13);
    ev1.pointerToEV->goToFloor(evu1.destinationFloor);
    evu1.exitElevator();
    ev1.pointerToEV->offboardPassenger();
    std::cout << "This passenger weighs: " << evu1.weight << "kg" << std::endl;
    evu1.printPassengerWeight();
    std::cout << "Passengers in this elevator weigh " << ev1.pointerToEV->totalWeightCarried << "kg in total" << std::endl;
    ev1.pointerToEV->printTotalWeightCarried();

    std::cout << std::endl;

    ElevatorWrapper ev2(new Elevator("A2"));
    Elevator::User evu2;
    evu2.takeStairsInstead(44);
    evu2.callElevator();
    ev2.pointerToEV->goToFloor(evu2.currentFloor);
    evu2.takeStairsInstead(31);
    evu2.exitElevator();
    evu2.callElevator();
    evu2.weight = 901.55;
    ev2.pointerToEV->onboardPassenger(evu2.weight);
    std::cout << "Passengers in this elevator weigh " << ev2.pointerToEV->totalWeightCarried << "kg in total" << std::endl;
    ev2.pointerToEV->printTotalWeightCarried();
    ev2.pointerToEV->offboardPassenger();
    std::cout << "This passenger weighs: " << evu2.weight << "kg" << std::endl;
    evu2.printPassengerWeight();
    
    std::cout << std::endl;
    
    // ============== Building ==================
    
    BuildingWrapper b1(new Building());
    b1.pointerToBuilding->openBuilding();
    b1.pointerToBuilding->callElevatorAAndTakePassenger(14, 901.0);
    b1.pointerToBuilding->callElevatorAAndTakePassenger(3, 55);
    b1.pointerToBuilding->clearBuilding();
    std::cout << "Highest floor: " << b1.pointerToBuilding->elevatorA.highestFloor << "   Lowest floor: " << b1.pointerToBuilding->elevatorA.lowestFloor << std::endl;
    b1.pointerToBuilding->displayFloorOptions();
    
    std::cout << std::endl;

    BuildingWrapper b2(new Building());
    b2.pointerToBuilding->openBuilding();
    b2.pointerToBuilding->callElevatorAAndTakePassenger(51, 100);
    b2.pointerToBuilding->clearBuilding();
    b2.pointerToBuilding->callElevatorAAndTakePassenger(44, 120);
    b2.pointerToBuilding->openBuilding();
    b2.pointerToBuilding->clearBuilding();
    std::cout << "good to go!" << std::endl;

    std::cout << std::endl;
    
}
