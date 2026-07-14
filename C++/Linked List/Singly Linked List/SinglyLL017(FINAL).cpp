/*
=====================================================================

Program Name    : Singly Linked List - Menu Driven Application 
Program Number  : 017
Description     : This program implements a menu-driven
                  Singly Linked List using C++ classes.
                  The user can perform various operations
                  such as insertion, deletion, display,
                  and counting nodes through an interactive
                  menu system.

Concepts Used   : C++, Classes, Objects,
                  Dynamic Memory Allocation,
                  Linked List Operations,
                  Menu Driven Programming,
                  Encapsulation

Operations      :
                  1. Insert First
                  2. Insert Last
                  3. Insert At Position
                  4. Delete First
                  5. Delete Last
                  6. Delete At Position
                  7. Display List
                  8. Count Nodes
                  0. Exit

Input           : User Choice, Data, Position

Output          : Displays updated linked list
                  and operation results.

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

    int iChoice = 1;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    while(iChoice != 0)
    {
        cout<<"\n-------------------------------------------------\n";
        cout<<"Singly Linked List Menu\n";
        cout<<"-------------------------------------------------\n";

        cout<<"1 : Insert First\n";
        cout<<"2 : Insert Last\n";
        cout<<"3 : Insert At Position\n";
        cout<<"4 : Delete First\n";
        cout<<"5 : Delete Last\n";
        cout<<"6 : Delete At Position\n";
        cout<<"7 : Display Elements\n";
        cout<<"8 : Count Elements\n";
        cout<<"0 : Exit\n";

        cout<<"\nEnter your choice : ";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter data : ";
                cin>>iValue;

                sobj.InsertFirst(iValue);
                break;

            case 2:
                cout<<"Enter data : ";
                cin>>iValue;

                sobj.InsertLast(iValue);
                break;

            case 3:
                cout<<"Enter data : ";
                cin>>iValue;

                cout<<"Enter position : ";
                cin>>iPos;

                sobj.InsertAtPos(iValue,iPos);
                break;

            case 4:
                sobj.DeleteFirst();
                cout<<"First node deleted\n";
                break;

            case 5:
                sobj.DeleteLast();
                cout<<"Last node deleted\n";
                break;

            case 6:
                cout<<"Enter position : ";
                cin>>iPos;

                sobj.DeleteAtPos(iPos);
                break;

            case 7:
                sobj.Display();
                break;

            case 8:
                iRet = sobj.Count();
                cout<<"Number of elements are : "<<iRet<<endl;
                break;

            case 0:
                cout<<"Thank you for using the application...\n";
                break;

            default:
                cout<<"Invalid choice\n";
                break;
        }
    }

    return 0;
}

/*
=====================================================================

Sample Execution :

-------------------------------------------------
Singly Linked List Menu
-------------------------------------------------

1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display Elements
8 : Count Elements
0 : Exit

Enter your choice : 1
Enter data : 51

Enter your choice : 1
Enter data : 21

Enter your choice : 1
Enter data : 11

Enter your choice : 7

| 11 |-> | 21 |-> | 51 |-> NULL

Enter your choice : 8

Number of elements are : 3

Explanation :

The program continuously displays a menu
and accepts user input.

Depending upon the selected option,
the corresponding linked list operation
is executed.

Insertion operations create new nodes
and connect them appropriately.

Deletion operations remove nodes and
release dynamically allocated memory.

Display operation traverses the entire
linked list and prints all nodes.

Count operation returns the total
number of nodes currently present
in the linked list.

Conclusion :

This program combines all previously
implemented Singly Linked List operations
into a complete menu-driven application,
allowing users to interactively manage
the linked list.

=====================================================================
*/
