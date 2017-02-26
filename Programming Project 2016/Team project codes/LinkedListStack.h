#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode
{
    char* Data;
    struct tagNode* NextNode;
} Node;

typedef struct tagLinkedListStack
{
    Node* List;
    Node* Top;
} LinkedListStack;

void  LLS_CreateStack( LinkedListStack** Stack );
void  LLS_DestroyStack( LinkedListStack* Stack );

Node* LLS_CreateNode( char* Data );
void  LLS_DestroyNode( Node* _Node );
void  LLS_Push( LinkedListStack* Stack, Node* NewNode );
Node* LLS_Pop( LinkedListStack* Stack );

Node* LLS_Top( LinkedListStack* Stack );
int   LLS_GetSize( LinkedListStack* Stack );
int   LLS_IsEmpty( LinkedListStack* Stack );

void  LLS_CreateStack( LinkedListStack** Stack )
{
    (*Stack )       = ( LinkedListStack*)malloc(sizeof( LinkedListStack ) );
    (*Stack )->List = NULL;
    (*Stack )->Top  = NULL;
}

void LLS_DestroyStack( LinkedListStack* Stack )
{
    while ( !LLS_IsEmpty(Stack ) )
    {
        Node* Popped = LLS_Pop( Stack );
        LLS_DestroyNode(Popped);
    }

    free(Stack );
}

Node* LLS_CreateNode( char* NewData )
{
    Node* NewNode = ( Node*)malloc(sizeof( Node ) );
    NewNode->Data = ( char*)malloc(strlen( NewData ) + 1);

    strcpy( NewNode->Data, NewData );

    NewNode->NextNode = NULL;

    return NewNode;
}

void  LLS_DestroyNode( Node* _Node )
{
    free(_Node->Data );
    free(_Node );
}

void LLS_Push( LinkedListStack* Stack, Node* NewNode )
{
    if ( Stack->List == NULL )
    {
        Stack->List = NewNode;
    }
    else
    {
        Node* OldTop = Stack->List;
        while ( OldTop->NextNode != NULL )
        {
            OldTop = OldTop->NextNode;
        }

        OldTop->NextNode = NewNode;
    }

    Stack->Top = NewNode;
}

Node* LLS_Pop( LinkedListStack* Stack )
{
    Node* TopNode = Stack->Top;

    if ( Stack->List == Stack->Top )
    {
        Stack->List = NULL;
        Stack->Top  = NULL;
    }
    else
    {
        Node* CurrentTop = Stack->List;
        while ( CurrentTop != NULL && CurrentTop->NextNode != Stack->Top )
        {
            CurrentTop = CurrentTop->NextNode;
        }

        Stack->Top = CurrentTop;
        CurrentTop->NextNode = NULL;
    }

    return TopNode;
}

Node* LLS_Top( LinkedListStack* Stack )
{
    return Stack->Top;
}

int LLS_GetSize( LinkedListStack* Stack )
{
    int    Count = 0;
    Node*  Current = Stack->List;

    while ( Current != NULL )
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

int LLS_IsEmpty( LinkedListStack* Stack )
{
    return (Stack->List == NULL);
}

#endif	//LINKEDLIST_STACK_H
