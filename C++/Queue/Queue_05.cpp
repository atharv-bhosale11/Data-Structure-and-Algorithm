/*
===============================================================================
Program Name    : Queue Dequeue Operation
Program Number  : 005
File Name       : Queue05.cpp

Description     : This program demonstrates insertion,
                  display, count and deletion operation
                  in Queue using Singly Linear Linked List.

Date            : August 2026
Language        : C++
Author          : Atharv Tushar Bhosale
===============================================================================
*/

#include<iostream>

using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node* next;
};

class Queue
{
    private:
        struct node* first;
        int iCount;

    public:
        Queue();
        void Enqueue(int iNo);
        int Dequeue();
        void Display();
        int Count();
};

///////////////////////////////////////////////////////////////////////////////
//
// Constructor
//
///////////////////////////////////////////////////////////////////////////////

Queue :: Queue()
{
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Enqueue
// Description   : Insert element at Last position
//
///////////////////////////////////////////////////////////////////////////////

void Queue :: Enqueue(int iNo)
{
    struct node* newn = NULL;
    struct node* temp = NULL;

    newn = new struct node();

    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Dequeue
// Description   : Delete element from First position
//
///////////////////////////////////////////////////////////////////////////////

int Queue :: Dequeue()
{
    int iValue = 0;
    struct node* temp = NULL;

    if(first == NULL)
    {
        cout<<"Queue is Empty!!!\n";
        return -1;
    }

    iValue = first->data;

    temp = first;
    first = first->next;

    delete temp;

    iCount--;

    return iValue;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
//
///////////////////////////////////////////////////////////////////////////////

void Queue :: Display()
{
    struct node* temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |"<<endl;
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
//
///////////////////////////////////////////////////////////////////////////////

int Queue :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    Queue qobj;
    int iRet = 0;

    qobj.Enqueue(11);
    qobj.Enqueue(21);
    qobj.Enqueue(51);
    qobj.Enqueue(101);

    qobj.Display();

    iRet = qobj.Count();
    cout<<"\nNumber of Elements in Queue are : "<<iRet<<endl;

    iRet = qobj.Dequeue();
    cout<<"\nRemoved Element : "<<iRet<<endl;

    qobj.Display();

    iRet = qobj.Count();
    cout<<"\nNumber of Elements in Queue are : "<<iRet<<endl;

    return 0;
}

/*
===============================================================================
Sample Output

| 11 |
| 21 |
| 51 |
| 101 |

Number of Elements in Queue are : 4

Removed Element : 11

| 21 |
| 51 |
| 101 |

Number of Elements in Queue are : 3

===============================================================================
End of Program
===============================================================================
*/Added Program 05: Implemented Dequeue Operation in Queue using Singly Linear Linked List
