#include "DerivedClass.h"

int SecondOperation( DerivedClass * const me, int variableOne)
{
    return me->super.FirstVariable + me->FirstVariable + variableOne;
}
