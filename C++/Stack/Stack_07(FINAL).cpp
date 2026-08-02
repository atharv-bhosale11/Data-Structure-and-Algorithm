////////////////////////////////////////////////////////////
//
//  Program Name    : Stack Using Singly Linear Linked List
//  Program Number  : 648
//  Description     : Menu Driven Implementation of Stack
//                    Data Structure using Singly Linear
//                    Linked List.
//
//  Operations:
//      1. Push
//      2. Pop
//      3. Peep
//      4. Display
//      5. Count
//
//  Concepts Used   : Stack, Linked List, Class,
//                    Dynamic Memory Allocation
//
//  Language        : C++
//
//  Author          : Atharv Tushar Bhosale
//  Date            : August 2026
//
////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node* next;
};

class Stack
{
    private:
        struct node* first;
        int iCount;

    public:
        Stack();

        void Push(int iNo);
        int Pop();
        int Peep();
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////
//
//  Constructor
//
////////////////////////////////////////////////////////////

Stack :: Stack()
{
    first = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////
//
//  Push Operation
//
////////////////////////////////////////////////////////////

void Stack :: Push(int iNo)
{
    struct node* newn = NULL;

    newn = new struct node();

    newn->data = iNo;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

////////////////////////////////////////////////////////////
//
//  Pop Operation
//
////////////////////////////////////////////////////////////

int Stack :: Pop()
{
    int iValue = 0;
    struct node* temp = NULL;

    if(first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }

    iValue = first->data;
    temp = first;

    first = first->next;

    delete temp;

    iCount--;

    return iValue;
}

////////////////////////////////////////////////////////////
//
//  Peep Operation
//
////////////////////////////////////////////////////////////

int Stack :: Peep()
{
    if(first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }

    return first->data;
}

////////////////////////////////////////////////////////////
//
//  Display Operation
//
////////////////////////////////////////////////////////////

void Stack :: Display()
{
    struct node* temp = first;

    if(first == NULL)
    {
        cout<<"Stack is Empty\n";
        return;
    }

    cout<<"\nElements of Stack are :\n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp = temp->next;
    }
}

////////////////////////////////////////////////////////////
//
//  Count Operation
//
////////////////////////////////////////////////////////////

int Stack :: Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////
//
//  Entry Point Function
//
////////////////////////////////////////////////////////////

int main()
{
    Stack sobj;

    int iChoice = 0;
    int iNo = 0;
    int iRet = 0;

    while(true)
    {
        cout<<"\n=====================================\n";
        cout<<"          STACK APPLICATION\n";
        cout<<"=====================================\n";

        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peep\n";
        cout<<"4. Display\n";
        cout<<"5. Count\n";
        cout<<"0. Exit\n";

        cout<<"Enter your choice : ";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter element : ";
                cin>>iNo;

                sobj.Push(iNo);

                cout<<"Element inserted successfully\n";
                break;

            case 2:
                iRet = sobj.Pop();

                if(iRet != -1)
                {
                    cout<<"Popped element is : "<<iRet<<"\n";
                }
                break;

            case 3:
                iRet = sobj.Peep();

                if(iRet != -1)
                {
                    cout<<"Topmost element is : "<<iRet<<"\n";
                }
                break;

            case 4:
                sobj.Display();
                break;

            case 5:
                cout<<"Number of elements are : "
                    <<sobj.Count()<<"\n";
                break;

            case 0:
                cout<<"Thank you for using Stack Application\n";
                return 0;

            default:
                cout<<"Invalid Choice\n";
                break;
        }
    }

    return 0;
}

////////////////////////////////////////////////////////////
//
//  End of Program
//
//  Stack Using Singly Linear Linked List
//
//  Operations Implemented:
//      - Push
//      - Pop
//      - Peep
//      - Display
//      - Count
//
//  Author : Atharv Tushar Bhosale
//  Date   : August 2026
//
////////////////////////////////////////////////////////////
