#pragma once
#include "def.h"

/*** Definitions ***/

typedef struct
{
    Node* head;
}List;



/*** Function prototypes ***/
BOOL* L_init(List* pList);					// create new list
Node* L_insert_After(Node* pNode, DATA Value);	// add new node after *pNode
Node* L_insert_Before(Node* pNode, DATA Value);	// add new node before *pNode
Node* NodeInPositionI(List pL1, int i);         // get the node in position I
void printList(List pl);
void L_delete(Node* ptr);

