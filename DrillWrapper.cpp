#include "DrillWrapper.h"

DrillWrapper::DrillWrapper(Drill* d) : pointerToDrill(d) {}

DrillWrapper::~DrillWrapper()
{
    delete pointerToDrill;
}

