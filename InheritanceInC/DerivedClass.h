#ifndef DERIVEDCLASS_H
#define DERIVEDCLASS_H

#include "BaseClass.h"

typedef struct
{
    Base super;
    int FirstVariable;
    int SecondVariable;
} DerivedClass;

int SecondOperation( DerivedClass * const me, int variableOne);

#endif