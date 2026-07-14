/*
=====================================================================

Program Name    : Singly Linked List - InsertAtPos and DeleteAtPos
Program Number  : 033
Description     : This program demonstrates the implementation of
                  InsertAtPos() and DeleteAtPos() operations in a
                  Singly Linear Linked List. These operations allow
                  insertion and deletion of nodes at any valid
                  position in the linked list.

Concepts Used   : Singly Linked List,
                  Dynamic Memory Allocation,
                  Position-Based Insertion,
                  Position-Based Deletion,
                  Pointer Manipulation,
                  Traversal, Node Counting

Input           : Node values and position specified in function
                  calls.

Output          : Displays the linked list after performing
                  insertion and deletion operations at a
                  specified position.

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
    while (first!= NULL)        // Type 1
    {
        printf("|%d| -> ",first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{   
    int iCount = 0;

    while (first != NULL)       // Type 1
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
        while(temp -> next != NULL)     // Type 2
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void InsertAtPos(PPNODE first, int no, int iPos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int i = 0;
    int iCount = 0;
    iCount = Count(*first);

    if((iPos < 1) || (iPos > iCount + 1))      
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first,no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(first,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *first;

        for(i= 1; i< iPos-1; i++)
        {
            temp = temp ->next;
        }

        newn->next = temp->next;    
        temp->next = newn;          
    }
}

void DeleteFirst(PPNODE first)
{   
    PNODE temp = NULL;
    if(*first == NULL)                  // Linked List is Empty
    {   
        return;
    }
    else if((*first) -> next == NULL)     // Linked List contains one node
    {
        free(*first);
        *first = NULL;
    }
    else                                // Linked List more than one nodes
    {
        temp = *first;

        *first = (*first) -> next;

        free(temp);
    }
}

void DeleteLast(PPNODE first)
{   
    PNODE temp = NULL;
    if(*first == NULL)                  // Linked List is Empty
    {   
        return;
    }
    else if((*first) -> next == NULL)     // Linked List contains one node
    {
        free(*first);
        *first = NULL;
    }
    else                                // Linked List more than one nodes
    {   
        temp = *first;
        while(temp -> next -> next != NULL)
        {   
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
    }
}

void DeleteAtPos(PPNODE first, int pos)
{
    int iCount = 0;
    int i = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first);

    if((pos < 1) || (pos > iCount))      
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp->next;

        temp -> next = target -> next;        
        free(target);                       
    }
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

    // DELETE AT FIRST
    DeleteFirst(&head);
    Display(head);

    iRet = Count(head);
    printf("Number of Nodes: %d\n",iRet);

    // DELETE LAST
    DeleteLast(&head);
    Display(head);

    iRet = Count(head);
    printf("Number of Nodes: %d\n",iRet);

    // INSERT AT POSITION

    InsertAtPos(&head,105,4);
    Display(head);

    iRet = Count(head);
    printf("Number of Nodes: %d\n",iRet);

    // DELETE AT POSITION

    DeleteAtPos(&head,4);
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

|21| -> |51| -> |101| -> |111| -> |121| -> NULL
Number of Nodes: 5

|21| -> |51| -> |101| -> |111| -> NULL
Number of Nodes: 4

|21| -> |51| -> |101| -> |105| -> |111| -> NULL
Number of Nodes: 5

|21| -> |51| -> |101| -> |111| -> NULL
Number of Nodes: 4

Explanation :

After DeleteLast():

21 -> 51 -> 101 -> 111 -> NULL

InsertAtPos(105,4)

Traversal stops at node 101.

21 -> 51 -> 101 -> 111 -> NULL
                 |
                 v
                105

After insertion:

21 -> 51 -> 101 -> 105 -> 111 -> NULL

DeleteAtPos(4)

Target node = 105

21 -> 51 -> 101 -> 105 -> 111 -> NULL
                 ^      ^
                 |      |
               temp   target

After deletion:

21 -> 51 -> 101 -> 111 -> NULL

Operations Performed :

1. Inserted nodes at first position.
2. Inserted nodes at last position.
3. Deleted first node.
4. Deleted last node.
5. Inserted node at position 4.
6. Deleted node from position 4.
7. Displayed updated linked list.
8. Verified node count after each operation.

Conclusion :

InsertAtPos() and DeleteAtPos() successfully
perform position-based insertion and deletion
while maintaining proper link connections and
memory management within the linked list.

=====================================================================
*/
