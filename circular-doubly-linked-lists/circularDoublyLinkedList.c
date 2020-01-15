#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "circularDoublyLinkedList.h"


//////////////////////////////////////////
// 
// Aim:		create new list
// Input:	pointer to the node structure
// Output:	TRUE if succeeded
//////////////////////////////////////////
BOOL* L_init(List* pList)
{

	if (pList == NULL)
		return False;
	pList->head = (Node*)malloc(sizeof(Node));
	if (!pList->head)
		return False;

	pList->head->right = pList->head;
	pList->head->left = pList->head;

}


/////////////////////////////////////////////////////////////////
// 
// Aim:		add new node
// Input:	pointer to the node BEFORE the place for the new one
//			a value to be stored in the new node
// Output:	pointer to the new node
/////////////////////////////////////////////////////////////////
Node* L_insert_After(Node* pNode, DATA Value)
{
	Node* insert;
	if (!pNode)
		return NULL;


	insert = (Node*)malloc(sizeof(Node));	// new node
	if (!insert)
		return NULL;
	insert->info = Value;

	Node* tmp = pNode->right;
	tmp->left = insert;
	insert->right = tmp;


	pNode->right = insert;
	insert->left = pNode;

	return insert;

}


/////////////////////////////////////////////////////////////////
// 
// Aim:		add new node
// Input:	pointer to the node Before the place for the new one
//			a value to be stored in the new node
// Output:	pointer to the new node
/////////////////////////////////////////////////////////////////
Node* L_insert_Before(Node* pNode, DATA Value)
{
	Node* insert;
	if (!pNode)
		return NULL;


	insert = (Node*)malloc(sizeof(Node));	// new node
	if (!insert)
		return NULL;
	insert->info = Value;

	Node* tmp = pNode->left;
	tmp->right = insert;
	insert->left = tmp;

	pNode->left = insert;
	insert->right = pNode;

	return insert;

}
/////////////////////////////////////////////////////////////////
// Insert
// Aim:		delete a node
// Input:	pointer to be deleted
// Output:	
/////////////////////////////////////////////////////////////////
void L_delete(Node* ptr)
{

	Node* tmpLeft = ptr->left;
	Node* tmpRight = ptr->right;
	tmpLeft->right = tmpRight;
	tmpRight->left = tmpLeft;
	free(ptr);
}

/////////////////////////////////////////////////////////////////
// Aim:		get the node in postion i, the head node is in postion 0
// Input:	List
// Output:	the node in the postion
/////////////////////////////////////////////////////////////////
Node* NodeInPositionI(List pL, int i)
{
	int count = 0;
	Node* ptr = pL.head;
	do
	{
		if (count == i)
			return ptr;
		ptr = ptr->right;
		count++;
	} while (ptr != pL.head); // if it matches we did more than one loop
	return NULL; // didnt find
}
/////////////////////////////////////////////////////////////////
// Aim:		print the list, include the head
// Input:	List
// Output:	
/////////////////////////////////////////////////////////////////
void printList(List pl)
{
	Node* ptr = pl.head;
	if (!ptr)
		return;

	do
	{
		printf(" %d ", ptr->info);
		ptr = ptr->right;

	} while (ptr != pl.head);
	printf("\n");
}