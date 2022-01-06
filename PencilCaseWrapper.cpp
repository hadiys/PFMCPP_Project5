#include "PencilCaseWrapper.h"

PencilCaseWrapper::PencilCaseWrapper(PencilCase* pc) : pointerToPC(pc) {}

PencilCaseWrapper::~PencilCaseWrapper()
{
    delete pointerToPC;
}

