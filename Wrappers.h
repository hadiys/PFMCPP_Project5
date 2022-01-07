struct Building;
struct Drill;
struct Elevator;
struct PencilCase;
struct SchoolBag;

struct BuildingWrapper
{
    Building* pointerToBuilding = nullptr;
    BuildingWrapper(Building* b);
    ~BuildingWrapper();
};

struct DrillWrapper
{
    Drill* pointerToDrill = nullptr;
    DrillWrapper(Drill* d);
    ~DrillWrapper();
};

struct ElevatorWrapper
{
    Elevator* pointerToEV = nullptr;
    ElevatorWrapper(Elevator* ev);
    ~ElevatorWrapper();
};

struct PencilCaseWrapper
{
    PencilCase* pointerToPC = nullptr;
    PencilCaseWrapper(PencilCase* pc);
    ~PencilCaseWrapper();
};

struct SchoolBagWrapper
{
    SchoolBag* pointerToSB = nullptr;
    SchoolBagWrapper(SchoolBag* sb);
    ~SchoolBagWrapper();
};
