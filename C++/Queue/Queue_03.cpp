/*
===============================================================================
Program Name    : Queue Display Operation
Program Number  : 003
File Name       : Queue03.cpp

Description     : This program demonstrates insertion
                  and display operation in Queue using
                  Singly Linear Linked List.

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
// Function Name : Display
// Description   : Display Queue elements
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
// Function Name : Dequeue
//
///////////////////////////////////////////////////////////////////////////////

int Queue :: Dequeue()
{
    return 0;
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

    qobj.Enqueue(11);
    qobj.Enqueue(21);
    qobj.Enqueue(51);
    qobj.Enqueue(101);

    qobj.Display();

    return 0;
}

/*
===============================================================================
Sample Output

| 11 |
| 21 |
| 51 |
| 101 |

===============================================================================
End of Program
===============================================================================
*/
