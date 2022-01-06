#include "Drill.h"

struct DrillWrapper
{
    Drill* pointerToDrill = nullptr;
    DrillWrapper(Drill* d);
    ~DrillWrapper();
};
