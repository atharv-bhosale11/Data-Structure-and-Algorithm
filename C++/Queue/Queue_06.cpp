/*
===============================================================================
Program Name    : Complete Queue Program
Program Number  : 006
File Name       : Queue06.cpp

Description     : This program demonstrates complete
                  Queue implementation using Singly
                  Linear Linked List.

                  Operations:
                  1. Enqueue
                  2. Dequeue
                  3. Display
                  4. Count

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
// Description   : Insert element at Last
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
// Description   : Delete element from First
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
// Description   : Display Queue
//
///////////////////////////////////////////////////////////////////////////////

void Queue :: Display()
{
    struct node* temp = NULL;

    temp = first;

    cout<<"\nQueue Elements : \n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |"<<endl;
        temp = temp->next;
    }
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

Queue Elements :

| 11 |
| 21 |
| 51 |
| 101 |

Number of Elements in Queue are : 4

Removed Element : 11

Queue Elements :

| 21 |
| 51 |
| 101 |

Number of Elements in Queue are : 3

Removed Element : 21

Queue Elements :

| 51 |
| 101 |

Number of Elements in Queue are : 2

===============================================================================
End of Program
===============================================================================
*/
