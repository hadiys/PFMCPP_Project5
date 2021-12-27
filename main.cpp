/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() 
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

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
    };
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
    };
};

struct SchoolBag
{
    PencilCase schoolPencilCase;

    SchoolBag();
    ~SchoolBag();

    void packPencilCase();
    void unpackPencilCase();
    void checkForPencilCase();
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
    PencilCase pencilCase1;
    pencilCase1.open();
    pencilCase1.close();
    pencilCase1.open();
    pencilCase1.addItems(12);
    pencilCase1.removeItems(8);
    std::cout << "Items in the pencilcase: " << pencilCase1.numItemsAdded << std::endl;
    pencilCase1.printNumContainedItems();

    std::cout << std::endl;

    PencilCase pencilCase2;
    pencilCase2.addItems(25);
    pencilCase2.open();
    pencilCase2.addItems(25);
    pencilCase2.removeItems(1);
    std::cout << "Items in the pencilcase: " << pencilCase2.numItemsAdded << std::endl;
    pencilCase2.printNumContainedItems();

    std::cout << std::endl;
    // ============== SchoolBag ==========================
    SchoolBag schoolbag1;
    schoolbag1.schoolPencilCase.open();
    schoolbag1.schoolPencilCase.addItems(15);
    schoolbag1.packPencilCase();
    schoolbag1.schoolPencilCase.addItems(15);
    schoolbag1.packPencilCase();
    (schoolbag1.schoolPencilCase.inSchoolBag) ? std::cout << "Pencilcase is in schoolbag" << std::endl : std::cout << "Pencilcase is not in schoolbag" << std::endl;
    schoolbag1.checkForPencilCase();

    std::cout << std::endl;

    SchoolBag schoolbag2;
    schoolbag2.schoolPencilCase.open();
    schoolbag2.schoolPencilCase.addItems(15);
    schoolbag2.schoolPencilCase.close();
    (schoolbag2.schoolPencilCase.inSchoolBag) ? std::cout << "Pencilcase is in schoolbag" << std::endl : std::cout << "Pencilcase is not in schoolbag" << std::endl;
    schoolbag2.checkForPencilCase();

    std::cout << std::endl;
    // ============== Drill =======================
    Drill drill1;
    drill1.unplug();
    drill1.attachDrillbit(3.f);
    drill1.drillHole(5);
    (drill1.isPlugged && drill1.drillbitAttached) ? std::cout << "The drill is ready to work" << std::endl : std::cout << "The drill is not ready to work" << std::endl;
    drill1.printDrillStatus();

    std::cout << std::endl;

    Drill drill2;
    drill2.drillHole(20);
    drill2.attachDrillbit(5.8f);
    drill2.drillHole(20);
    (drill2.isPlugged && drill2.drillbitAttached) ? std::cout << "The drill is ready to work" << std::endl : std::cout << "The drill is not ready to work" << std::endl;
    drill2.printDrillStatus();
    drill2.unplug();

    std::cout << std::endl;

    // ============== Elevator & ElevatorUser ============
    Elevator ev1("A1");
    Elevator::ElevatorUser evu1;
    evu1.callElevator();
    ev1.goToFloor(evu1.currentFloor);
    ev1.onboardPassenger(evu1.weight);
    evu1.enterElevator();
    evu1.setDestination(13);
    ev1.goToFloor(evu1.destinationFloor);
    evu1.exitElevator();
    ev1.offboardPassenger();
    std::cout << "This passenger weighs: " << evu1.weight << "kg" << std::endl;
    evu1.printPassengerWeight();
    std::cout << "Passengers in this elevator weigh " << ev1.totalWeightCarried << "kg in total" << std::endl;
    ev1.printTotalWeightCarried();

    std::cout << std::endl;

    Elevator ev2("A2");
    Elevator::ElevatorUser evu2;
    evu2.takeStairsInstead(44);
    evu2.callElevator();
    ev2.goToFloor(evu2.currentFloor);
    evu2.takeStairsInstead(31);
    evu2.exitElevator();
    evu2.callElevator();
    evu2.weight = 901.55;
    ev2.onboardPassenger(evu2.weight);
    std::cout << "Passengers in this elevator weigh " << ev2.totalWeightCarried << "kg in total" << std::endl;
    ev2.printTotalWeightCarried();
    ev2.offboardPassenger();
    std::cout << "This passenger weighs: " << evu2.weight << "kg" << std::endl;
    evu2.printPassengerWeight();
    
    std::cout << std::endl;
    
    // ============== Building ==================
    Building b1;
    b1.openBuilding();
    b1.callElevatorAAndTakePassenger(14, 901.0);
    b1.callElevatorAAndTakePassenger(3, 55);
    b1.clearBuilding();
    std::cout << "Highest floor: " << b1.elevatorA.highestFloor << "   Lowest floor: " << b1.elevatorA.lowestFloor << std::endl;
    b1.displayFloorOptions();
    
    std::cout << std::endl;

    Building b2;
    b2.openBuilding();
    b2.callElevatorAAndTakePassenger(51, 100);
    b2.clearBuilding();
    b2.callElevatorAAndTakePassenger(44, 120);
    b2.openBuilding();
    b2.clearBuilding();
    std::cout << "good to go!" << std::endl;

    std::cout << std::endl;
}
