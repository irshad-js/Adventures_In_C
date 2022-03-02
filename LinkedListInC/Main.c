#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct LinkedListNode LinkedListNode_t;

struct LinkedListNode{

    int ValueInNode;

    struct LinkedListNode * NextInList;
    
};

static LinkedListNode_t* CreateNewNode(int value){

    LinkedListNode_t * NewNode = (LinkedListNode_t*) malloc(sizeof(LinkedListNode_t));

    if(NewNode == NULL) return NULL;

    NewNode->ValueInNode = value;

    NewNode->NextInList = NULL;

    return NewNode;

}

static LinkedListNode_t * InsertNodeAtHead(LinkedListNode_t *ListHead,LinkedListNode_t *NodeToInsert){

    NodeToInsert ->NextInList = ListHead;

    return NodeToInsert;

}

static LinkedListNode_t * FindNode (LinkedListNode_t* ListHead, int ValueToSearch){

    LinkedListNode_t * TemporaryPointer = ListHead;

    while(TemporaryPointer != NULL){

        if(TemporaryPointer->ValueInNode == ValueToSearch) return TemporaryPointer;

        TemporaryPointer = TemporaryPointer->NextInList; 
    }

    return NULL;

}

static void InsertNodeInCustomPosition(LinkedListNode_t * NodeNeighbour, LinkedListNode_t * NodeToBePlaced){

    NodeToBePlaced->NextInList = NodeNeighbour->NextInList;

    NodeNeighbour->NextInList = NodeToBePlaced;

}

int main(){

    #define NodesToBeCreated 25

    LinkedListNode_t * ListHead = NULL;
    
    LinkedListNode_t * TemporaryPointer ;

    for(int IterationVariable=0;IterationVariable<NodesToBeCreated;++IterationVariable){

        TemporaryPointer = CreateNewNode(IterationVariable);

        ListHead = InsertNodeAtHead(ListHead,TemporaryPointer);

    }

    TemporaryPointer = FindNode(ListHead,5);

    InsertNodeInCustomPosition(TemporaryPointer, CreateNewNode(99));

    return 0;
}
