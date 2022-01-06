#include "Elevator.h"

struct ElevatorWrapper
{
    Elevator* pointerToEV = nullptr;
    ElevatorWrapper(Elevator* ev);
    ~ElevatorWrapper();
};
