#include "BuildingWrapper.h"

BuildingWrapper::BuildingWrapper(Building* b) : pointerToBuilding(b) {}

BuildingWrapper::~BuildingWrapper()
{
    delete pointerToBuilding;
}
