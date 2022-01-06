#include "ElevatorWrapper.h"

ElevatorWrapper::ElevatorWrapper(Elevator* ev) : pointerToEV(ev) {}

ElevatorWrapper::~ElevatorWrapper()
{
    delete pointerToEV;
}

