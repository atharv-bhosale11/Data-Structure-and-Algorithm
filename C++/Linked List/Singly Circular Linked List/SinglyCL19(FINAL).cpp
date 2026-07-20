/*
=====================================================================

Name            : Singly Circular Linked List - Menu Driven Program
Program Number  : 022

Description     : This program demonstrates a menu driven
                  implementation of Singly Circular Linked List.

                  User can perform the following operations:

                  1. InsertFirst()
                  2. InsertLast()
                  3. InsertAtPos()
                  4. DeleteFirst()
                  5. DeleteLast()
                  6. DeleteAtPos()
                  7. Display()
                  8. Count()

Concepts Used   : Classes and Objects,
                  Dynamic Memory Allocation,
                  Circular Linked List,
                  Menu Driven Programming

Input           : User Choice and Node Data

Output          : Updated linked list after every operation

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
typedef struct node* PNODE;

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;
        
    public:
        SinglyCL();
        void Display();
        int Count();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

SinglyCL :: SinglyCL()
{
    cout<<"Inside Constructor\n";
    this -> first = NULL;
    this -> last = NULL;
    this -> iCount = 0;
}

void SinglyCL :: Display()
{
    PNODE temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }

    temp = first;

    do
    {
        cout<<"| "<<temp -> data<<" | ->";
        temp = temp -> next;
    }while(last -> next != temp);
    cout<<"\n";

}

int SinglyCL :: Count()
{
    return iCount;
}

void SinglyCL :: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE();

    newn -> data = iNo;
    newn -> next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn -> next = first;
        first = newn;
        
    }
    last -> next = first;
    iCount++;
}

void SinglyCL :: InsertLast(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE();

    newn -> data = iNo;
    newn -> next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        last = newn;
    }
    last -> next = first;
    iCount++;
}

void SinglyCL ::InsertAtPos(int iNo, int iPos)
{
    int i = 0;

    if(iPos < 1 || iPos > iCount + 1)
    {
        cout<<"Invalid Positions\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE temp = NULL;
        PNODE newn = NULL;

        newn = new NODE();

        newn -> data = iNo;
        newn -> next = NULL;

        temp = first;
        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
        iCount++;
    }
}

void SinglyCL :: DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last -> next;
        last -> next = first;
    }
    iCount--;
}

void SinglyCL :: DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        PNODE temp = NULL;

        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }
        delete last;
        last = temp;
        last -> next = first;
    }
    iCount--;
}

void SinglyCL :: DeleteAtPos(int iPos)
{
    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Positions\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = NULL;
        PNODE target = NULL;

        temp = first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;
        temp -> next = target -> next;
        delete target;
        iCount--;
    }
}

int main()
{
    SinglyCL sobj;

    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    while(true)
    {
        cout<<"\n-----------------------------------\n";
        cout<<"    Singly Circular Linked List\n";
        cout<<"-----------------------------------\n";

        cout<<"1 : Insert First\n";
        cout<<"2 : Insert Last\n";
        cout<<"3 : Insert At Position\n";
        cout<<"4 : Delete First\n";
        cout<<"5 : Delete Last\n";
        cout<<"6 : Delete At Position\n";
        cout<<"7 : Display\n";
        cout<<"8 : Count\n";
        cout<<"0 : Exit\n";

        cout<<"Enter your choice : ";
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
                break;

            case 5:
                sobj.DeleteLast();
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
                cout<<"Number of Nodes are : "<<iRet<<"\n";
                break;

            case 0:
                cout<<"Thank you for using the application\n";
                return 0;

            default:
                cout<<"Invalid choice\n";
                break;
        }
    }

    return 0;
}

/*
=====================================================================

Program Summary :

-> Implemented Singly Circular Linked List
-> Performed insertion operations
-> Performed deletion operations
-> Displayed linked list elements
-> Counted total number of nodes
-> Used menu driven approach for user interaction

=====================================================================
*/
