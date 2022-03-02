#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct QueueNode QueueNode;

typedef struct QueueImplementation QueueImplementation;

struct QueueNode{

    int ValueInNode;

    struct QueueNode * NextInQueue;
    
};

struct QueueImplementation{

    QueueNode * QueueHead;

    QueueNode * QueueTail;

};

static void InitializeQueue ( QueueImplementation * Queue){

    Queue->QueueHead = NULL;

    Queue->QueueTail = NULL;

}

/*

                         --------|--------|--------|--------|--------|---------
Elements come out      <-        |        |        |        |        |HEAD,TAIL      <- Elements Go In
                         --------|--------|--------|--------|--------|---------

*/

char Enqueue(QueueImplementation * Queue, int ValueToStore){

    QueueNode * NewQueueNode = (QueueNode*)malloc(sizeof(QueueNode));

    if(NewQueueNode == NULL) return 0;

    NewQueueNode->ValueInNode = ValueToStore;

    NewQueueNode->NextInQueue = NULL;

    if(Queue->QueueTail != NULL){

        Queue->QueueTail->NextInQueue = NewQueueNode;

    }

    Queue->QueueTail = NewQueueNode;

    if(Queue->QueueHead == NULL) Queue->QueueHead = NewQueueNode;


}

int Dequeue (QueueImplementation * Queue){

    if(Queue->QueueHead == NULL) return 0xDEADBEEF;

    QueueNode * TemporaryNode = (QueueNode*)malloc(sizeof(QueueNode));
    
    TemporaryNode = Queue->QueueHead;

    int StoreValue ;
    
    StoreValue = TemporaryNode->ValueInNode;

    Queue->QueueHead = Queue->QueueHead->NextInQueue;

    if(Queue->QueueHead == NULL) Queue->QueueTail = NULL;

    free(TemporaryNode);

    return StoreValue;

}

int main(){

    QueueImplementation * FirstQueue = (QueueImplementation*)malloc(sizeof(QueueImplementation));

    InitializeQueue(FirstQueue);

    Enqueue(FirstQueue,55);

    Enqueue(FirstQueue,25);

    Enqueue(FirstQueue,45);

    Enqueue(FirstQueue,15);

    int StoredQueueValue =0;

    while( (StoredQueueValue = Dequeue(FirstQueue)) != 0xDEADBEEF){

        printf("\n\n Items in Queue - %d \n",StoredQueueValue);

    }
    
    return 0;
}
