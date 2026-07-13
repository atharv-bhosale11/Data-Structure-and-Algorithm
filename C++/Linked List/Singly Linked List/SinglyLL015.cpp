/*
=====================================================================

Program Name    : Singly Linked List - DeleteLast() Operation
Program Number  : 015
Description     : This program demonstrates the implementation of
                  DeleteLast() in a Singly Linked List using C++.

                  The linked list supports insertion at the beginning
                  and end, deletion from the beginning, and deletion
                  from the end.

                  The DeleteLast() function traverses the linked list
                  up to the second last node, deletes the last node,
                  and updates the link structure accordingly.

Concepts Used   : C++, Classes, Objects,
                  Constructor,
                  Self-Referential Structure,
                  Dynamic Memory Allocation,
                  Linked List Traversal,
                  InsertFirst(),
                  InsertLast(),
                  DeleteFirst(),
                  DeleteLast(),
                  Node Count Maintenance

Input           : Node values inserted through function calls.

Output          : Displays linked list after insertion and deletion
                  operations along with node count.

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
    PNODE temp = NULL;
    temp = this -> first;

    while(temp != NULL)
    {
        cout<<"| "<<temp -> data<<" |-> ";
        temp = temp -> next;
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

    if(this -> first == NULL)
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

    if(this -> first == NULL)
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
{
    PNODE temp = NULL;
    if(this -> first == NULL)
    {
        return;
    }
    else if(this -> first -> next == NULL)
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;       
        this -> first = this -> first -> next;
        delete(temp);
    }

    this -> iCount--;
}

void  SinglyLL:: DeleteLast()
{
    PNODE temp = NULL;
    if(this -> first == NULL)
    {
        return;
    }
    else if(this -> first -> next == NULL)
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = NULL;
    }
    this -> iCount--;
}

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

    sobj.DeleteFirst();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Elements are: "<<iRet<<endl;

    sobj.DeleteLast();
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

| 21 |-> | 51 |-> | 101 |-> | 111 |-> | 121 |-> NULL
Number of Elements are: 5

| 21 |-> | 51 |-> | 101 |-> | 111 |-> NULL
Number of Elements are: 4

Explanation :

Initial Linked List :

first
  |
  v
[11] -> [21] -> [51] -> [101] -> [111] -> [121] -> NULL

iCount = 6

DeleteFirst() Operation :

Node 11 is removed.

first
  |
  v
[21] -> [51] -> [101] -> [111] -> [121] -> NULL

iCount = 5

DeleteLast() Operation :

Before Deletion :

first
  |
  v
[21] -> [51] -> [101] -> [111] -> [121] -> NULL

temp traversal :

21 -> 51 -> 101 -> 111

Loop Condition :

while(temp->next->next != NULL)

When temp reaches node 111 :

temp
 |
 v
[111] -> [121] -> NULL

Delete last node :

delete temp->next;

Set link :

temp->next = NULL;

After Deletion :

first
  |
  v
[21] -> [51] -> [101] -> [111] -> NULL

iCount = 4

Cases Handled :

Case 1 : Empty Linked List

first = NULL

Function returns immediately.

Case 2 : Single Node Linked List

first
 |
 v
[11|NULL]

Node is deleted and first becomes NULL.

Case 3 : Multiple Nodes

Traverse to second last node,
delete last node,
make second last node point to NULL.

Operations Performed :

1. Created Singly Linked List object.
2. Inserted nodes using InsertFirst().
3. Inserted nodes using InsertLast().
4. Displayed linked list.
5. Deleted first node.
6. Deleted last node.
7. Displayed updated linked list.
8. Updated node count after each deletion.

Conclusion :

This program successfully demonstrates the
DeleteLast() operation in a Singly Linked List.
The function correctly handles empty, single-node,
and multi-node scenarios while maintaining the
integrity of the linked list and accurate node count.

=====================================================================
*/
