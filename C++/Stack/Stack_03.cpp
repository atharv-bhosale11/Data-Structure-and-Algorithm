////////////////////////////////////////////////////////////
//
//  Program Name    : Stack Using Singly Linear Linked List 
//  Program Number  : 003
//  Description     : Implementation of Stack Data Structure
//                    using Singly Linear Linked List.
//
//                    Operations:
//                    1. Push
//                    2. Pop
//                    3. Peep
//                    4. Display
//                    5. Count
//
//  Concepts Used   : Class, Object, Linked List,
//                    Dynamic Memory Allocation, Stack
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
    return 0;
}           

int Stack :: Peep()   
{}

void Stack :: Display()
{}

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

    return 0;
}

////////////////////////////////////////////////////////////
//
//  End of Program
//
//  Stack Using Singly Linear Linked List
//
//  Author : Atharv Tushar Bhosale
//  Date   : August 2026
//
////////////////////////////////////////////////////////////
