#include "Building.h"

struct BuildingWrapper
{
    Building* pointerToBuilding = nullptr;
    BuildingWrapper(Building* b);
    ~BuildingWrapper();
};
