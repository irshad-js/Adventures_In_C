#ifndef SUBJECT_H
#define SUBJECT_H

#define MAX_OBSERVERS 25

typedef struct SubjectData SubjectData;

struct SubjectData
{
    int ValueOfInterest_1;
    int ValueOfInterest_2;
    int ValueOfInterest_3;
    int ValueOfInterest_4;
};

typedef struct SubjectClass SubjectClass;

struct SubjectClass
{
    SubjectData SampleData;
	
    int ObserverCount;

    void (*ObserverNotificationHandle[MAX_OBSERVERS]) (void);

    /* Private Functions structure like so 

    int (*isFull)(Queue* const me);

    int (*isEmpty)(Queue* const me);

    int (*getSize)(Queue* const me);

    void (*insert)(Queue* const me, int k);

    int (*remove)(Queue* const me);
    
    */

};

void SubjectClass_Initialization(SubjectClass * const me);
void SubjectClass_AddObserver(SubjectClass * const me, void (*ObserverNotificationFunction)(void));
void SubjectClass_RemoveObserver(SubjectClass * const me, void (*ObserverNotificationFunction)(void));
void SubjectClass_NotifyObservers(SubjectClass * const me);

extern SubjectClass * DataProducer;

#endif
