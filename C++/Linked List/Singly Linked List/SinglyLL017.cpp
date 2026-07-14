/*
=====================================================================

Program Name    : Singly Linked List - DeleteAtPos Function (C++)
Program Number  : 017
Description     : This program demonstrates deletion of a node
                  from a specified position in a Singly Linked
                  List. Position validation is performed before
                  deletion. Special cases such as deletion from
                  the first and last positions are handled by
                  calling existing member functions.

Concepts Used   : C++, Class, Constructor,
                  Dynamic Memory Management,
                  Self-Referential Structure,
                  Linked List Traversal,
                  Position-Based Deletion

Input           : Position of node to be deleted

Output          : Displays the linked list after deleting
                  the node from the desired position.

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
{
    int i = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Position";
        return;
    }

    if(iPos == 1)
    {
        this -> InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        this -> InsertLast(iNo);
    }
    else
    {
        newn = new NODE();
        newn -> data = iNo;
        newn -> next = NULL;

        temp = this -> first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        this -> iCount++;
    }
}

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
{
    int i = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;
    PNODE target = NULL;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position";
        return;
    }

    if(iPos == 1)
    {
        this -> DeleteFirst();
    }
    else if(iPos == iCount)
    {
        this -> DeleteLast();
    }
    else
    {
        temp = this -> first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target -> next;
        delete(target);
        this -> iCount--;
    }
}

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

    sobj.InsertAtPos(105,4);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of Elements are: "<<iRet<<endl;

    sobj.DeleteAtPos(4);
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

| 21 |-> | 51 |-> | 101 |-> | 105 |-> | 111 |-> NULL
Number of Elements are: 5

| 21 |-> | 51 |-> | 101 |-> | 111 |-> NULL
Number of Elements are: 4

Explanation :

DeleteAtPos() removes a node from any valid
position in the linked list.

Validation Performed :

1. Position must be between 1 and iCount.
2. If position is 1, DeleteFirst() is called.
3. If position is iCount, DeleteLast() is called.
4. Otherwise traversal is performed to locate
   the node preceding the target node.

Deletion Logic :

Before Deletion :

21 -> 51 -> 101 -> 105 -> 111 -> NULL

Delete Node at Position 4

After Deletion :

21 -> 51 -> 101 -> 111 -> NULL

Operations Performed :

1. Traversed to position (iPos - 1).
2. Stored target node address.
3. Adjusted links to bypass target node.
4. Released memory using delete.
5. Updated node count.
6. Displayed updated linked list.

Conclusion :

DeleteAtPos() successfully removes a node
from any valid position while maintaining
the integrity of the Singly Linked List.

=====================================================================
*/
