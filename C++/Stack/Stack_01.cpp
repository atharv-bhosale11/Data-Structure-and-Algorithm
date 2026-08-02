////////////////////////////////////////////////////////////
//
//  Program Name    : Stack Using Singly Linear Linked List
//  Program Number  : 001
//  Description     : Implementation of Stack Data Structure
//                    using Singly Linear Linked List.
//
//                    Operations Performed:
//                    1. Push
//                    2. Pop
//                    3. Peep
//                    4. Display
//                    5. Count
//
//  Concepts Used   : Class, Dynamic Memory Allocation,
//                    Linked List, Stack (LIFO)
//
//  Input           : Integer Data
//  Output          : Stack Operations Result
//
//  Language        : C++
//  Compiler        : GNU G++
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
{}

void Stack :: Push(int iNo)           
{}

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
