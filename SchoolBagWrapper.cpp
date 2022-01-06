#include "SchoolBagWrapper.h"

SchoolBagWrapper::SchoolBagWrapper(SchoolBag* sb) : pointerToSB(sb) {}

SchoolBagWrapper::~SchoolBagWrapper()
{
    delete pointerToSB;
}
