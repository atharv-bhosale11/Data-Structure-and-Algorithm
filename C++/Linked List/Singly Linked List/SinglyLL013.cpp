/*
=====================================================================

Program Name    : Singly Linked List - Display Using FOR Loop
Program Number  : 013
Description     : This program demonstrates the implementation of a
                  Singly Linked List in C++ where the Display()
                  function traverses the linked list using a FOR loop
                  instead of the traditional WHILE loop.

                  The loop executes exactly iCount times, making use
                  of the node count maintained by the linked list.

                  The program also demonstrates insertion at the
                  beginning and end of the linked list.

Concepts Used   : C++, Classes, Objects,
                  Constructor,
                  Self-Referential Structure,
                  Dynamic Memory Allocation,
                  Encapsulation,
                  FOR Loop Traversal,
                  InsertFirst(),
                  InsertLast(),
                  Node Counter (iCount)

Input           : Node values inserted through function calls.

Output          : Displays all linked list elements and total
                  number of nodes.

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale

=====================================================================
*/

#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class SinglyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        SinglyLL();
        void Display();
        int Count();
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

SinglyLL::SinglyLL()
{
    this -> first = NULL;
    this -> iCount = 0;
}

void SinglyLL:: Display()
{
    int i = 0;
    PNODE temp = NULL;
    temp = this -> first;

    for(i = 1; i <= this -> iCount; i++, temp = temp -> next)            // Insetad of WHILE use FOR Loop
    {
        cout<<"| "<<temp -> data<<" |-> ";
    }
    cout<<"NULL"<<endl;
}

int SinglyLL:: Count()
{
    return this -> iCount;
}

void  SinglyLL:: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;

    if(iCount == 0)                         // 2nd Approach
    {
        this -> first = newn;
    }
    else
    {
        newn -> next = this -> first;
        this -> first = newn;
    }
    this -> iCount++;                               // Important
}

void  SinglyLL:: InsertLast(int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;

    if(iCount == 0)                         // 2nd Approach
    {
        this -> first = newn;
    }
    else
    {
        temp = this -> first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;  
        }
        temp -> next = newn;
    }
    this -> iCount++;                              // Important
}

void  SinglyLL:: InsertAtPos(int iNo, int iPos)
{}

void  SinglyLL:: DeleteFirst()
{}

void  SinglyLL:: DeleteLast()
{}

void  SinglyLL:: DeleteAtPos(int iPos)
{}

int main()
{
    SinglyLL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);                // InsertFirst(sobj,51)
    sobj.InsertFirst(21);                // InsertFirst(sobj,21)
    sobj.InsertFirst(11);                // InsertFirst(sobj,11)

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of Elements are: "<<iRet<<endl;

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Elements are: "<<iRet<<endl;

    return 0;
}

/*
=====================================================================

Expected Output :

| 11 |-> | 21 |-> | 51 |-> NULL
Number of Elements are: 3

| 11 |-> | 21 |-> | 51 |-> | 101 |-> | 111 |-> | 121 |-> NULL
Number of Elements are: 6

Explanation :

Initially :

first = NULL
iCount = 0

InsertFirst() Operations :

InsertFirst(51)
InsertFirst(21)
InsertFirst(11)

Linked List :

first
  |
  v
[11|*] -> [21|*] -> [51|NULL]

iCount = 3

InsertLast() Operations :

InsertLast(101)
InsertLast(111)
InsertLast(121)

Linked List :

first
  |
  v
[11] -> [21] -> [51] -> [101] -> [111] -> [121|NULL]

iCount = 6

Display() Traversal :

Instead of :

while(temp != NULL)
{
    cout << temp->data;
    temp = temp->next;
}

This program uses :

for(i = 1; i <= iCount; i++, temp = temp->next)
{
    cout << temp->data;
}

Advantages :

1. Traversal count is controlled by iCount.
2. Demonstrates use of FOR loop in linked list traversal.
3. Useful when node count is already maintained.
4. Loop executes exactly iCount times.

Operations Performed :

1. Created Singly Linked List object.
2. Inserted nodes using InsertFirst().
3. Displayed linked list using FOR loop.
4. Counted total nodes.
5. Inserted nodes using InsertLast().
6. Displayed updated linked list.
7. Verified node count.

Conclusion :

This program demonstrates an alternative traversal
technique for a Singly Linked List using a FOR loop.
Since the exact number of nodes is available through
iCount, the traversal can be controlled without
checking temp against NULL in every iteration.

=====================================================================
*/
