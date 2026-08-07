/*
===============================================================================
Program Name    : Queue Skeleton
Program Number  : 001
File Name       : Queue01.cpp

Description     : This program demonstrates the basic
                  skeleton of Queue using Singly Linear
                  Linked List.

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
// Description   : Insert element at last position
//
///////////////////////////////////////////////////////////////////////////////

void Queue :: Enqueue(int iNo)
{
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Dequeue
// Description   : Delete element from first position
//
///////////////////////////////////////////////////////////////////////////////

int Queue :: Dequeue()
{
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Display Queue elements
//
///////////////////////////////////////////////////////////////////////////////

void Queue :: Display()
{
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Return number of elements
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

    return 0;
}

/*
===============================================================================
Sample Output

Queue Skeleton Created Successfully

===============================================================================
End of Program
===============================================================================
*/
