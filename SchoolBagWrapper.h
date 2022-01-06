#include "SchoolBag.h"

struct SchoolBagWrapper
{
    SchoolBag* pointerToSB = nullptr;
    SchoolBagWrapper(SchoolBag* sb);
    ~SchoolBagWrapper();
};
