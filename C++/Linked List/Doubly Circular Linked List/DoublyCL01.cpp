/*
===============================================================================
Program Name    : Doubly Circular Linked List - Node Creation
Program Number  : 001
File Name       : DoublyCL01.cpp

Description     : This program demonstrates the creation of a
                  node for a Doubly Circular Linked List using
                  dynamic memory allocation.

Date            : August 2026
Language        : C++
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class
2. Dynamic Memory Allocation
3. Self-Referential Class
4. Pointer Manipulation
5. Constructor

===============================================================================
*/

#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node *prev;
};

int main()
{
    Node *newn = NULL;

    newn = new Node;

    newn->data = 11;
    newn->next = newn;
    newn->prev = newn;

    cout<<"Node Created Successfully"<<endl;
    cout<<"Data : "<<newn->data<<endl;

    delete newn;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Node Created Successfully
Data : 11

===============================================================================
Memory Representation:
===============================================================================

        +-------------------+
        | Data : 11         |
        | Next : Self       |
        | Prev : Self       |
        +-------------------+

===============================================================================
Algorithm:
===============================================================================

1. Define a node class.
2. Allocate memory dynamically.
3. Store data in node.
4. Connect next pointer to itself.
5. Connect prev pointer to itself.
6. Display node information.

===============================================================================
Time Complexity:
===============================================================================

Node Creation : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 demonstrates how to create a node for a Doubly
Circular Linked List using dynamic memory allocation.

===============================================================================
*/
