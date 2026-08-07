/*
===============================================================================
Program Name    : Queue Menu Driven Application
Program Number  : 007
File Name       : Queue07.cpp    

Description     : This program demonstrates a complete
                  Menu Driven Queue using Singly Linear
                  Linked List.

                  Operations:
                  1. Enqueue
                  2. Dequeue
                  3. Display
                  4. Count
                  5. Exit

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

    if(first == NULL)
    {
        cout<<"Queue is Empty!!!\n";
        return;
    }

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

    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;

    cout<<"--------------------------------------------------\n";
    cout<<"          Queue Menu Driven Application\n";
    cout<<"--------------------------------------------------\n";

    while(1)
    {
        cout<<"\n--------------------------------------------------\n";
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Display\n";
        cout<<"4. Count\n";
        cout<<"5. Exit\n";
        cout<<"--------------------------------------------------\n";

        cout<<"Enter your choice : ";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:

                cout<<"Enter the data : ";
                cin>>iValue;

                qobj.Enqueue(iValue);

                cout<<"Element inserted successfully\n";
                break;

            case 2:

                iRet = qobj.Dequeue();

                if(iRet != -1)
                {
                    cout<<"Removed Element : "<<iRet<<endl;
                }
                break;

            case 3:

                qobj.Display();
                break;

            case 4:

                iRet = qobj.Count();

                cout<<"Number of Elements : "<<iRet<<endl;
                break;

            case 5:

                cout<<"Thank you for using Queue Application\n";
                return 0;

            default:

                cout<<"Invalid Choice\n";
                break;
        }
    }

    return 0;
}

/*
===============================================================================
Sample Output

1. Enqueue
2. Dequeue
3. Display
4. Count
5. Exit

Enter your choice : 1
Enter the data : 11

Enter your choice : 1
Enter the data : 21

Enter your choice : 1
Enter the data : 51

Enter your choice : 3

Queue Elements :

| 11 |
| 21 |
| 51 |

Enter your choice : 4

Number of Elements : 3

Enter your choice : 2

Removed Element : 11

Enter your choice : 3

Queue Elements :

| 21 |
| 51 |

===============================================================================
End of Program
===============================================================================
*/
