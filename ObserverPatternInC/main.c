#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "subject.h"
#include "Observer.h"

/*

Observer design pattern implementation in C

Publishers are also called Subjects

Subscribers are also called Observers

ChangeProducerData method already changes the base class attribute's value. 

The value change is notified to user/application only by SubjectClass_NotifyObservers

*/


/* Start Unit testing experimenations */

#include "unity.h"
#include "unity_fixture.h"


SubjectClass * DataProducer;

ObserverClass * Consumer_1 ;

ObserverClass * Consumer_2 ;

ObserverClass * Consumer_3 ;

ObserverClass * Consumer_4 ;



static void ChangeProducerData(SubjectClass * const me, int Var1, int Var2, int Var3, int Var4){

    me->SampleData.ValueOfInterest_1 = Var1;

    me->SampleData.ValueOfInterest_2 = Var2;
    
    me->SampleData.ValueOfInterest_3 = Var3;

    me->SampleData.ValueOfInterest_4 = Var4;

}

void TestFirstRegisteredObserver_common(void){

    ObserverClass_RegisterToBeNotified(Consumer_1);

    ChangeProducerData(DataProducer,2,5,7,9);

    SubjectClass_NotifyObservers(DataProducer);

    TEST_ASSERT_EQUAL_INT8_MESSAGE(2,Consumer_1->super->SampleData.ValueOfInterest_1,"Test-1 OK PASS");

}

void TestRegisteredObserver_FirstSecond_common(void){

    ObserverClass_RegisterToBeNotified(Consumer_2);

    ChangeProducerData(DataProducer,3,1,4,2);

    SubjectClass_NotifyObservers(DataProducer);

    TEST_ASSERT_EQUAL_INT8(3,Consumer_1->super->SampleData.ValueOfInterest_1);

    TEST_ASSERT_EQUAL_INT8_MESSAGE(1,Consumer_2->super->SampleData.ValueOfInterest_2,"Test-2 OK PASS");

}

void TestRegisteredObserver_FirstSecondThird_common(void){

    ObserverClass_RegisterToBeNotified(Consumer_3);

    ChangeProducerData(DataProducer,9,2,8,6);

    SubjectClass_NotifyObservers(DataProducer);
        
    TEST_ASSERT_EQUAL_INT8(9,Consumer_1->super->SampleData.ValueOfInterest_1);

    TEST_ASSERT_EQUAL_INT8(2,Consumer_2->super->SampleData.ValueOfInterest_2);

    TEST_ASSERT_EQUAL_INT8_MESSAGE(8,Consumer_3->super->SampleData.ValueOfInterest_3,"Test-3 OK PASS");

}

void TestRegisteredObserver_FirstSecondThirdFourth_common(void){

    ObserverClass_RegisterToBeNotified(Consumer_4);

    ChangeProducerData(DataProducer,1,4,5,2);

    SubjectClass_NotifyObservers(DataProducer);   

    TEST_ASSERT_EQUAL_INT8(1,Consumer_1->super->SampleData.ValueOfInterest_1);

    TEST_ASSERT_EQUAL_INT8(4,Consumer_2->super->SampleData.ValueOfInterest_2);

    TEST_ASSERT_EQUAL_INT8(5,Consumer_3->super->SampleData.ValueOfInterest_3);

    TEST_ASSERT_EQUAL_INT8(2,Consumer_4->super->SampleData.ValueOfInterest_4);

}

void TestObserverDeregistration_Third_common(void){

    ObserverClass_UnRegisterToBeNotified(Consumer_3);

    ChangeProducerData(DataProducer,3,1,4,2);

    SubjectClass_NotifyObservers(DataProducer);

    TEST_ASSERT_EQUAL_INT8(3,Consumer_1->super->SampleData.ValueOfInterest_1);

    TEST_ASSERT_EQUAL_INT8(1,Consumer_2->super->SampleData.ValueOfInterest_2);

    TEST_ASSERT_EQUAL_INT8(4-1,DataProducer->ObserverCount);

    TEST_ASSERT_EQUAL_INT8(2,Consumer_4->super->SampleData.ValueOfInterest_4);
    
}

void TestObserverDeregistration_ThirdFirst_common(void){

    ObserverClass_UnRegisterToBeNotified(Consumer_1);

    ChangeProducerData(DataProducer,2,4,9,8);

    SubjectClass_NotifyObservers(DataProducer);

    TEST_ASSERT_EQUAL_INT8(4,Consumer_2->super->SampleData.ValueOfInterest_2);

    TEST_ASSERT_EQUAL_INT8(3-1,DataProducer->ObserverCount);

    TEST_ASSERT_EQUAL_INT8(8,Consumer_4->super->SampleData.ValueOfInterest_4);
    
}

void TestObserverDeregistration_ThirdFirstSecond_common(void){

    ObserverClass_UnRegisterToBeNotified(Consumer_2);

    ChangeProducerData(DataProducer,1,4,6,5);

    SubjectClass_NotifyObservers(DataProducer);

    TEST_ASSERT_EQUAL_INT8(2-1,DataProducer->ObserverCount);

    TEST_ASSERT_EQUAL_INT8(5,Consumer_4->super->SampleData.ValueOfInterest_4);
    
}

#undef Test_print

TEST_GROUP(ObserverPatternTesting);

TEST_SETUP(ObserverPatternTesting){

#ifdef Test_print
    printf("\nTest setup is Initialized - From Test runner\n");
#endif

}

TEST_TEAR_DOWN(ObserverPatternTesting){

#ifdef Test_print
    printf("\nTest setup is De-Initialized - From Test runner\n");
#endif

}

TEST(ObserverPatternTesting,TestFirstRegisteredObserver){

    TestFirstRegisteredObserver_common();

}

TEST(ObserverPatternTesting,TestRegisteredObserver_FirstSecond){

    TestRegisteredObserver_FirstSecond_common();

}

TEST(ObserverPatternTesting,TestRegisteredObserver_FirstSecondThird){

    TestRegisteredObserver_FirstSecondThird_common();

}

TEST(ObserverPatternTesting,TestRegisteredObserver_FirstSecondThirdFourth){

    TestRegisteredObserver_FirstSecondThirdFourth_common();

}

TEST(ObserverPatternTesting,TestObserverDeregistration_Third){

    TestObserverDeregistration_Third_common();

}

TEST(ObserverPatternTesting,TestObserverDeregistration_ThirdFirst){

    TestObserverDeregistration_ThirdFirst_common();

}

TEST(ObserverPatternTesting,TestObserverDeregistration_ThirdFirstSecond){

    TestObserverDeregistration_ThirdFirstSecond_common();

}

TEST_GROUP_RUNNER(ObserverPatternTesting){

    RUN_TEST_CASE(ObserverPatternTesting,TestFirstRegisteredObserver);

    RUN_TEST_CASE(ObserverPatternTesting,TestRegisteredObserver_FirstSecond);

    RUN_TEST_CASE(ObserverPatternTesting,TestRegisteredObserver_FirstSecondThird);

    RUN_TEST_CASE(ObserverPatternTesting,TestRegisteredObserver_FirstSecondThirdFourth);

    RUN_TEST_CASE(ObserverPatternTesting,TestObserverDeregistration_Third);

    RUN_TEST_CASE(ObserverPatternTesting,TestObserverDeregistration_ThirdFirst);

    RUN_TEST_CASE(ObserverPatternTesting,TestObserverDeregistration_ThirdFirstSecond); 

}

int main(void){
 
    printf("\nObserver Pattern Implemenation in C\n\n");

    printf("\nTest setup is Initialized - From main\n\n");

    /* Test initialization */

    DataProducer = malloc(sizeof(SubjectClass));

    Consumer_1 = malloc(sizeof(ObserverClass));

    Consumer_2 = malloc(sizeof(ObserverClass));

    Consumer_3 = malloc(sizeof(ObserverClass));

    Consumer_4 = malloc(sizeof(ObserverClass));

    SubjectClass_Initialization(DataProducer);

    ObserverClass_Initialization(Consumer_1,DataProducer,ObserverClass_UpdateFunction_First);

    ObserverClass_Initialization(Consumer_2,DataProducer,ObserverClass_UpdateFunction_Second);

    ObserverClass_Initialization(Consumer_3,DataProducer,ObserverClass_UpdateFunction_Third);

    ObserverClass_Initialization(Consumer_4,DataProducer,ObserverClass_UpdateFunction_Fourth);

    UNITY_BEGIN();
    
    RUN_TEST_GROUP(ObserverPatternTesting);

    return UNITY_END();

}


//void setUp (void) {/* Is run before every test, put unit init calls here. */

 //   printf("\nTest setup is Initialized\n");

    /* printf("\nObserver Pattern Implemenation in C");

    printf("\nTest setup is Initialized");

    DataProducer = malloc(sizeof(SubjectClass));

    Consumer_1 = malloc(sizeof(ObserverClass));

    Consumer_2 = malloc(sizeof(ObserverClass));

    Consumer_3 = malloc(sizeof(ObserverClass));

    Consumer_4 = malloc(sizeof(ObserverClass));

    SubjectClass_Initialization(DataProducer);

    ObserverClass_Initialization(Consumer_1,DataProducer,ObserverClass_UpdateFunction_First);

    ObserverClass_Initialization(Consumer_2,DataProducer,ObserverClass_UpdateFunction_Second);

    ObserverClass_Initialization(Consumer_3,DataProducer,ObserverClass_UpdateFunction_Third);

    ObserverClass_Initialization(Consumer_4,DataProducer,ObserverClass_UpdateFunction_Fourth); */

//}

//void tearDown (void) { /* Is run after every test, put unit clean-up calls here. */

/*     free(DataProducer);

    free(Consumer_1);

    free(Consumer_2);

    free(Consumer_3);        

    free(Consumer_4); */

//    printf("\nTest setup is De-Initialized\n");

//}

 
/*    
    // Original implementation before unit testing

    SubjectClass * DataProducer = malloc(sizeof(SubjectClass));

    ObserverClass * Consumer_1 = malloc(sizeof(ObserverClass));

    ObserverClass * Consumer_2 = malloc(sizeof(ObserverClass));

    ObserverClass * Consumer_3 = malloc(sizeof(ObserverClass));

    ObserverClass * Consumer_4 = malloc(sizeof(ObserverClass));

    SubjectClass_Initialization(DataProducer);

    ObserverClass_Initialization(Consumer_1,DataProducer,ObserverClass_UpdateFunction_First);

    ObserverClass_Initialization(Consumer_2,DataProducer,ObserverClass_UpdateFunction_Second);

    ObserverClass_Initialization(Consumer_3,DataProducer,ObserverClass_UpdateFunction_Third);

    ObserverClass_Initialization(Consumer_4,DataProducer,ObserverClass_UpdateFunction_Fourth);

    ObserverClass_RegisterToBeNotified(Consumer_1);

    SubjectClass_NotifyObservers(DataProducer);

    ChangeProducerData(DataProducer,2,5,7,9);

    ObserverClass_RegisterToBeNotified(Consumer_2);

    SubjectClass_NotifyObservers(DataProducer);
    
    ChangeProducerData(DataProducer,3,1,4,2);

    ObserverClass_RegisterToBeNotified(Consumer_3);

    SubjectClass_NotifyObservers(DataProducer);

    ChangeProducerData(DataProducer,4,1,5,6);

    ObserverClass_RegisterToBeNotified(Consumer_4);

    SubjectClass_NotifyObservers(DataProducer);

    ChangeProducerData(DataProducer,3,7,6,8);

    ObserverClass_UnRegisterToBeNotified(Consumer_2);

    SubjectClass_NotifyObservers(DataProducer);

    ChangeProducerData(DataProducer,2,5,7,6);

    ObserverClass_UnRegisterToBeNotified(Consumer_1);

    SubjectClass_NotifyObservers(DataProducer);

    ChangeProducerData(DataProducer,1,9,8,7);

    ObserverClass_UnRegisterToBeNotified(Consumer_4);

    SubjectClass_NotifyObservers(DataProducer);

    // Original implementation ends

 */