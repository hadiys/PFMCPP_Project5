#pragma once
#include "Wrappers.h"
#include "Building.h"
#include "Drill.h"
#include "Elevator.h"
#include "PencilCase.h"
#include "SchoolBag.h"

BuildingWrapper::BuildingWrapper(Building* b) : pointerToBuilding(b) {}

BuildingWrapper::~BuildingWrapper()
{
    delete pointerToBuilding;
}

DrillWrapper::DrillWrapper(Drill* d) : pointerToDrill(d) {}

DrillWrapper::~DrillWrapper()
{
    delete pointerToDrill;
}

ElevatorWrapper::ElevatorWrapper(Elevator* ev) : pointerToEV(ev) {}

ElevatorWrapper::~ElevatorWrapper()
{
    delete pointerToEV;
}

PencilCaseWrapper::PencilCaseWrapper(PencilCase* pc) : pointerToPC(pc) {}

PencilCaseWrapper::~PencilCaseWrapper()
{
    delete pointerToPC;
}

SchoolBagWrapper::SchoolBagWrapper(SchoolBag* sb) : pointerToSB(sb) {}

SchoolBagWrapper::~SchoolBagWrapper()
{
    delete pointerToSB;
}

