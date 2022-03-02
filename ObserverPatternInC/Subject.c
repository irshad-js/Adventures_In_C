
#include "Subject.h"
#include <stddef.h>

void SubjectClass_Initialization(SubjectClass * const me){

    me->SampleData.ValueOfInterest_1 =0;

    me->SampleData.ValueOfInterest_2 =0;

    me->SampleData.ValueOfInterest_3 =0;

    me->SampleData.ValueOfInterest_4 =0;

    me->ObserverCount =0;

    for(int temp_variable=0;temp_variable<MAX_OBSERVERS;++temp_variable){

        me->ObserverNotificationHandle[temp_variable] = NULL;

    }

}

void SubjectClass_AddObserver(SubjectClass * const me, void (*ObserverNotificationFunction)(void)){

    if(ObserverNotificationFunction != NULL){

        me->ObserverNotificationHandle[me->ObserverCount] = ObserverNotificationFunction;

        me->ObserverCount += 1;

    }
}

void SubjectClass_RemoveObserver(SubjectClass * const me, void (*ObserverNotificationFunction)(void)){

    if(ObserverNotificationFunction != NULL){

        for( int temp_variable =0; temp_variable<(me->ObserverCount);++temp_variable){

            if(me->ObserverNotificationHandle[temp_variable] == ObserverNotificationFunction){

                me->ObserverCount -= 1;

                me->ObserverNotificationHandle[temp_variable] = me->ObserverNotificationHandle[me->ObserverCount];  // Changes the place of the last function pointer so that the array position is not wasted

            }
        }
     
    }
}

void SubjectClass_NotifyObservers(SubjectClass * const me){

    for( int temp_variable =0; temp_variable<(me->ObserverCount);++temp_variable){

            me->ObserverNotificationHandle[temp_variable]();

    }

}
