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
#include <iostream>
#include <string>
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

struct Drill
{
    bool isPlugged;
    bool drillbitAttached;
    int powerInWatts;
    char drillType = 'H';
    float rotationsToSecureBit = 0;
    float chuckTightness = 0.f;

    Drill();
    ~Drill();

    void drillHole(int holes);
    void unplug();
    void attachDrillbit(float drillbitWidth);
    void printDrillStatus();

    JUCE_LEAK_DETECTOR(Drill)
};

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
	
    struct ElevatorUser
    {
        double weight;
        int destinationFloor;
        int currentFloor;
        bool isInsideElevator = false;
        bool canExit = true;

        ElevatorUser();
        ~ElevatorUser();

        void callElevator();
        void enterElevator();
        void setDestination(int newDestinationFloor);
        void exitElevator();
        void takeStairsInstead(int newDestinationFloor);
        void printPassengerWeight();

        JUCE_LEAK_DETECTOR(ElevatorUser)
    };

    JUCE_LEAK_DETECTOR(Elevator)
};

struct SchoolBag
{
    PencilCase schoolPencilCase;

    SchoolBag();
    ~SchoolBag();

    void packPencilCase();
    void unpackPencilCase();
    void checkForPencilCase();

    JUCE_LEAK_DETECTOR(SchoolBag)
};

struct Building
{
    Elevator elevatorA{"A1"};
    Elevator elevatorB{"B1"};
    bool isOpen;

    Building();
    ~Building();

    void closeBuilding();
    void openBuilding();
    bool buildingEmpty();
    void clearBuilding();
    void callElevatorAAndTakePassenger(int designatedFloor, double passengerWeight);
    void displayFloorOptions();

    JUCE_LEAK_DETECTOR(Building)
};

struct PencilCaseWrapper
{
    PencilCaseWrapper(PencilCase* pc) : pointerToPC(pc) {}
    PencilCase* pointerToPC = nullptr;

    ~PencilCaseWrapper()
    {
        delete pointerToPC;
    }
};

struct DrillWrapper
{
    DrillWrapper(Drill* d) : pointerToDrill(d) {}
    Drill* pointerToDrill = nullptr;

    ~DrillWrapper()
    {
        delete pointerToDrill;
    }

};

struct ElevatorWrapper
{
    ElevatorWrapper(Elevator* ev) : pointerToEV(ev) {}
    Elevator* pointerToEV = nullptr;

    ~ElevatorWrapper()
    {
        delete pointerToEV;
    }
};

struct SchoolBagWrapper
{
    SchoolBagWrapper(SchoolBag* sb) : pointerToSB(sb) {}
    SchoolBag* pointerToSB = nullptr;

    ~SchoolBagWrapper()
    {
        delete pointerToSB;
    }
};

struct BuildingWrapper
{
    BuildingWrapper(Building* b) : pointerToBuilding(b) {}
    Building* pointerToBuilding = nullptr;

    ~BuildingWrapper()
    {
        delete pointerToBuilding;
    }
};

// ============Pencil Functions ================

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

// ===============PencilCase Functions=================

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

// ============= Drill Functions =================

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

// =========== ElevatorUser Functions ===========

Elevator::ElevatorUser::ElevatorUser() : weight(100.0), destinationFloor(0), currentFloor(0)
{
    std::cout << "****** ElevatorUser Created ******" << std::endl;
}

Elevator::ElevatorUser::~ElevatorUser()
{
    std::cout << "****** ElevatorUser Destroyed ******" << std::endl;
}

void Elevator::ElevatorUser::printPassengerWeight()
{
    std::cout << "This passenger weighs: " << this->weight << "kg" << std::endl;
}

void Elevator::ElevatorUser::callElevator()
{
    if(!isInsideElevator)
        std::cout << "Calling elevator..." << std::endl;
    else
        std::cout << "Wait till you exit the elevator" << std::endl;
}

void Elevator::ElevatorUser::enterElevator()
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

void Elevator::ElevatorUser::setDestination(int newDestinationFloor)
{
    destinationFloor = newDestinationFloor;
    std::cout << "Destination floor " << destinationFloor << std::endl;
}

void Elevator::ElevatorUser::exitElevator()
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

void Elevator::ElevatorUser::takeStairsInstead(int newDestinationFloor)
{
    destinationFloor = newDestinationFloor;

    while(destinationFloor != currentFloor)
        (destinationFloor > currentFloor) ? ++currentFloor : --currentFloor; 

    std::cout << "You have taken the stairs to floor " << currentFloor << std::endl;
}

// ================ Elevator Functions ===================

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

// ============= SchoolBag Functions ===============

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

// ============= Building Functions ==============

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

// ============= Main ==================
 

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

    // ============== Elevator & ElevatorUser ============
    ElevatorWrapper ev1(new Elevator("A1"));
    Elevator::ElevatorUser evu1;
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
    Elevator::ElevatorUser evu2;
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
