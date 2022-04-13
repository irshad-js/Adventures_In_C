#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*

Factory desgin pattern is a creational design pattern

Objects are created within the Factory class by the choice of different available objects sent to it at runtime

*/


void DoSomethingObject1(void);

typedef struct Factory Factory;
typedef struct DynamicObject DynamicObject;

struct DynamicObject{
    
    void (*DoSomething)(void);

};

struct Factory{

    DynamicObject * (*FactoryHandler)(char* Choice);

};

DynamicObject * FactoryHandler(char* Choice);

void DoSomethingObject1(void){

    printf("\n\n Object 1 is created and called dynamically \n\n");

}

void DoSomethingObject2(void){

    printf("\n\n Object 2 is created and called dynamically \n\n");

}

void DoSomethingObject3(void){

    printf("\n\n Object 3 is created and called dynamically \n\n");

}

void DoSomethingObject4(void){

    printf("\n\n Object 4 is created and called dynamically \n\n");

}

DynamicObject * FactoryHandler(char* Choice){

    if(Choice == "Object1"){
        DynamicObject * Object1 = (DynamicObject*) malloc(sizeof(DynamicObject));
        Object1->DoSomething = DoSomethingObject1;
        return Object1;
    }

    if(Choice == "Object2"){
        DynamicObject * Object2 = (DynamicObject*) malloc(sizeof(DynamicObject));
        Object2->DoSomething = DoSomethingObject2;
        return Object2;
    }

    if(Choice == "Object3"){
        DynamicObject * Object3 = (DynamicObject*) malloc(sizeof(DynamicObject));
        Object3->DoSomething = DoSomethingObject3;
        return Object3;
    }

    if(Choice == "Object4"){
        DynamicObject * Object4 = (DynamicObject*) malloc(sizeof(DynamicObject));
        Object4->DoSomething = DoSomethingObject4;
        return Object4;
    }

}


int main(){

    Factory * NewFactoryObject = (Factory*)malloc(sizeof(Factory));
    NewFactoryObject->FactoryHandler = FactoryHandler;

    DynamicObject * NewDynamicObject = NewFactoryObject->FactoryHandler("Object1");
    NewDynamicObject->DoSomething();

    free(NewDynamicObject);

    NewDynamicObject = NewFactoryObject->FactoryHandler("Object2");
    NewDynamicObject->DoSomething();

    free(NewDynamicObject);
    
    NewDynamicObject = NewFactoryObject->FactoryHandler("Object3");
    NewDynamicObject->DoSomething();

    free(NewDynamicObject);
    
    NewDynamicObject = NewFactoryObject->FactoryHandler("Object4");
    NewDynamicObject->DoSomething();

    free(NewDynamicObject);
    
    return 0;

}