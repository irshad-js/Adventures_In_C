#include "subject.h"
#include <stddef.h>
#include "Observer.h"
#include <stdio.h>

void ObserverClass_Initialization(ObserverClass * const me, SubjectClass * const Baseclass, void(*NotificationFunction)(void)){

    me->super = Baseclass;

    me->ObserverClass_UpdateFunction = NotificationFunction;

}

void ObserverClass_RegisterToBeNotified(ObserverClass * const me){

    SubjectClass_AddObserver(me->super,me->ObserverClass_UpdateFunction);

}


void ObserverClass_UnRegisterToBeNotified(ObserverClass * const me){

    SubjectClass_RemoveObserver(me->super,me->ObserverClass_UpdateFunction);
    
}

#undef Test_Print

void ObserverClass_UpdateFunction_First(void){

#ifdef Test_Print
    printf("\n\nNotification received in 1st Object,\n\nInterested variable - Element 1 of data is %d\n\n",Consumer_1->super->SampleData.ValueOfInterest_1);
#endif

}

void ObserverClass_UpdateFunction_Second(void){

#ifdef Test_Print
    printf("\n\nNotification received in 2nd Object,\n\nInterested variable - Element 2 of data is %d\n\n",Consumer_2->super->SampleData.ValueOfInterest_2);
#endif

}

void ObserverClass_UpdateFunction_Third(void){

#ifdef Test_Print
    printf("\n\nNotification received in 3rd Object,\n\nInterested variable - Element 3 of data is %d\n\n",Consumer_3->super->SampleData.ValueOfInterest_3);
#endif

}

void ObserverClass_UpdateFunction_Fourth(void){

#ifdef Test_Print
    printf("\n\nNotification received in 4th Object,\n\nInterested variable - Element 4 of data is %d\n\n",Consumer_4->super->SampleData.ValueOfInterest_4);
#endif

}