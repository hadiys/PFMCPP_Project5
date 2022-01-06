#include "PencilCase.h"

struct PencilCaseWrapper
{
    PencilCase* pointerToPC = nullptr;
    PencilCaseWrapper(PencilCase* pc);
    ~PencilCaseWrapper();
};
