/*
=====================================================================

Program Name    : Singly Linked List - DeleteFirst() Operation
Program Number  : 014
Description     : This program demonstrates the implementation of
                  DeleteFirst() in a Singly Linked List using C++.

                  The program supports insertion at the beginning
                  and end of the linked list and removes the first
                  node using DeleteFirst().

                  Special care is taken to handle all possible
                  cases such as:
                  1. Empty linked list
                  2. Linked list containing a single node
                  3. Linked list containing multiple nodes

Concepts Used   : C++, Classes, Objects,
                  Constructor,
                  Dynamic Memory Allocation,
                  Encapsulation,
                  Linked List Traversal,
                  InsertFirst(),
                  InsertLast(),
                  DeleteFirst(),
                  Node Count Maintenance

Input           : Node values inserted through function calls.

Output          : Displays linked list before and after deletion
                  along with total node count.

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

Explanation :

Initial Linked List :

first
  |
  v
[11] -> [21] -> [51] -> [101] -> [111] -> [121] -> NULL

iCount = 6

DeleteFirst() Working :

Step 1 :
Store address of first node into temp.

temp
 |
 v
[11] -> [21] -> [51] -> [101] -> [111] -> [121]

Step 2 :
Move first to next node.

first
  |
  v
[21] -> [51] -> [101] -> [111] -> [121] -> NULL

Step 3 :
Delete node pointed by temp.

delete(temp);

Final Linked List :

first
  |
  v
[21] -> [51] -> [101] -> [111] -> [121] -> NULL

iCount = 5

Cases Handled :

Case 1 :
Linked List Empty

first = NULL

Function immediately returns.

Case 2 :
Single Node Present

first
 |
 v
[11|NULL]

Node is deleted and first becomes NULL.

Case 3 :
Multiple Nodes Present

First node is removed and remaining
nodes stay connected.

Operations Performed :

1. Inserted nodes using InsertFirst().
2. Inserted nodes using InsertLast().
3. Displayed linked list.
4. Counted total nodes.
5. Deleted first node.
6. Displayed updated linked list.
7. Updated node count.

Conclusion :

This program successfully demonstrates the
DeleteFirst() operation in a Singly Linked List.
The function safely handles empty, single-node,
and multi-node linked lists while maintaining
the correct node count.

=====================================================================
*/
