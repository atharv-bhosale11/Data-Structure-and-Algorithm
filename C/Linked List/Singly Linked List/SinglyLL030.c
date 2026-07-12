/*
=====================================================================

Program Name    : Singly Linked List - InsertFirst and InsertLast
Program Number  : 030
Description     : This program demonstrates the implementation of
                  InsertFirst() and InsertLast() operations in a
                  Singly Linked List. Nodes can be inserted at the
                  beginning as well as at the end of the linked list.
                  The program also displays the linked list and
                  counts the total number of nodes.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Dynamic Memory Allocation,
                  Pointer Manipulation, Linked List Traversal,
                  Insert First Operation, Insert Last Operation,
                  Node Counting

Input           : None

Output          : Displays the linked list after insertion
                  operations and prints the total number
                  of nodes.

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first)
{
    while (first!= NULL)
    {
        printf("|%d| -> ",first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{   
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}

void InsertFirst(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(NULL == *first)          
    {
        *first = newn;
    }
    else                       
    {
        newn -> next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*first == NULL)          // Linked List is Empty
    {
        *first = newn;
    }
    else                       // Linked List at lest contain one Node
    {
        temp = *first;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{

}

void DeleteFirst(PPNODE first)
{

}

void DeleteLast(PPNODE first)
{

}

void DeleteAtPos(PPNODE first, int iPos)
{

}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    // INSERT AT FIRST
    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes: %d\n",iRet);


    // INSERT AT LAST
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes: %d\n",iRet);

    return 0;
}

/*
=====================================================================

Expected Output :

|11| -> |21| -> |51| -> |101| -> NULL
Number of Nodes: 4

|11| -> |21| -> |51| -> |101| -> |111| -> |121| -> NULL
Number of Nodes: 6

Explanation :

Initially, four nodes are inserted using the
InsertFirst() function.

Insertion Sequence :

InsertFirst(101)
InsertFirst(51)
InsertFirst(21)
InsertFirst(11)

Linked List :

|11| -> |21| -> |51| -> |101| -> NULL

The InsertLast() function is then used to add
new nodes at the end of the linked list.

InsertLast(111)
InsertLast(121)

Final Linked List :

|11| -> |21| -> |51| -> |101| -> |111| -> |121| -> NULL

InsertLast Working :

Step 1 :
Create a new node and initialize it.

Step 2 :
Traverse the linked list using a temporary
pointer until the last node is reached.

Step 3 :
Connect the last node to the newly created node.

Traversal Example :

temp
 |
 v
|11| -> |21| -> |51| -> |101| -> NULL

temp moves until:

|101| -> NULL

Then:

|101| -> |111| -> NULL

Operations Performed :

1. Created a self-referential structure.
2. Inserted nodes at the beginning.
3. Inserted nodes at the end.
4. Traversed the linked list.
5. Counted total nodes.
6. Displayed the final linked list.

Conclusion :

This program demonstrates both InsertFirst()
and InsertLast() operations. These operations
form the foundation for building dynamic linked
list applications and advanced insertion
techniques such as InsertAtPosition().

=====================================================================
*/
