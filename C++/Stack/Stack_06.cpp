////////////////////////////////////////////////////////////
//
//  Program Name    : Stack Using Singly Linear Linked List
//  Program Number  : 006
//  Description     : Implementation of Stack Data Structure
//                    using Singly Linear Linked List.
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

// Stack 

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
        void Push(int iNo);             // Insert First
        int Pop();                     // Delete First
        int Peep();                    // Delete First (it will give data only not deleting data)
        void Display();
        int Count();
};

Stack :: Stack()
{
    this -> first = NULL;
    this -> iCount = 0;
}

void Stack :: Push(int iNo)           
{
    struct node* newn = NULL;

    newn = new struct node();
    newn -> data = iNo;
    newn -> next = NULL;
    
    newn -> next = first;
    first = newn;

    iCount++;
}

int Stack :: Pop()
{
    int iValue = 0;
    struct node* temp = NULL;

    if(first == NULL)
    {
        cout<<"Stack is Empty!!!\n";
        return  -1;
    }
    else
    {
        iValue = first -> data;
        temp = first;

        first = first -> next;
        delete temp;
        iCount--;
        return iValue;
    }
}           

int Stack :: Peep()   
{
    int iValue = 0;

    if(first == NULL)
    {
        cout<<"Stack is Empty!!!\n";
        return  -1;
    }
    else
    {
        iValue = first -> data;
        return iValue;
    }
}

void Stack :: Display()
{
    struct node* temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp = temp -> next;
    }
}

int Stack :: Count()
{
    return iCount;
}

int main()
{
    Stack sobj;
    int iRet = 0;

    sobj.Push(11);
    sobj.Push(21);
    sobj.Push(51);
    sobj.Push(101);

    iRet = sobj.Count();
    cout<<"Elements of this stack:"<<iRet<<endl;

    sobj.Display();

    iRet = sobj.Pop();
    cout<<"Pop elements: "<<iRet<<endl;

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Elements of this stack:"<<iRet<<endl;

    iRet = sobj.Peep();
    cout<<"Peep elements: "<<iRet<<endl;
    iRet = sobj.Count();
    cout<<"Elements of this stack:"<<iRet<<endl;

    sobj.Display();
    
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
