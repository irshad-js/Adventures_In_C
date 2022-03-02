#include <stdio.h>
#include "BaseClass.h"
#include "DerivedClass.h"

Base FirstClass;

DerivedClass SecondClass;

int main(){

    FirstClass.FirstVariable = 10;
    
    FirstClass.SecondVariable = 12;

    SecondClass.super.FirstVariable = 8;

    SecondClass.super.SecondVariable = 2;

    SecondClass.FirstVariable = 6;

    SecondClass.SecondVariable = 8;

    printf("\n\nFirst Operation result %d\n\n",(FirstOperation(&FirstClass,5)));

    printf("\n\nSecond Operation result %d\n\n",(SecondOperation(&SecondClass,5)));

    return 0;
}
