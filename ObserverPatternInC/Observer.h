#ifndef OBSERVER_H
#define OBSERVER_H

#include "Subject.h"

typedef struct ObserverClass ObserverClass;

void ObserverClass_UpdateFunction_First(void);
void ObserverClass_UpdateFunction_Second(void);
void ObserverClass_UpdateFunction_Third(void);
void ObserverClass_UpdateFunction_Fourth(void);

struct ObserverClass
{
    SubjectClass *super;
    void (*ObserverClass_UpdateFunction) (void);
};

void ObserverClass_Initialization(ObserverClass * const me, SubjectClass * const Baseclass, void(*NotificationFunction)(void));
void ObserverClass_RegisterToBeNotified(ObserverClass * const me);
void ObserverClass_UnRegisterToBeNotified(ObserverClass * const me);

extern ObserverClass * Consumer_1 ;
extern ObserverClass * Consumer_2 ;
extern ObserverClass * Consumer_3 ;
extern ObserverClass * Consumer_4 ;

#endif
