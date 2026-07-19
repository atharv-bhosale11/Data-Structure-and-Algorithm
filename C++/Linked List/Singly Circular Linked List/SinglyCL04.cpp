/*
=====================================================================

Name            : Singly Circular Linked List - Circular Connection
Program Number  : 004

Description     : This program demonstrates how to create a
                  Singly Circular Linked List manually.

                  Three nodes are created dynamically and linked
                  together. The last node points back to the first
                  node, forming a circular structure.

                  This is the first example of a circular linked
                  list where traversal can continue indefinitely.

Concepts Used   : Singly Circular Linked List,
                  Dynamic Memory Allocation,
                  Circular Linking,
                  Self-Referential Structure,
                  Pointer Manipulation

Input           : None

Output          : Displays node data and circular links

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale

=====================================================================
*/

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

int main()
{
    PNODE first = new NODE;
    PNODE second = new NODE;
    PNODE third = new NODE;

    first->data = 11;
    first->next = second;

    second->data = 21;
    second->next = third;

    third->data = 51;
    third->next = first;

    cout<<"Data from nodes:"<<endl;

    cout<<first->data<<endl;
    cout<<second->data<<endl;
    cout<<third->data<<endl;

    cout<<"\nAddresses stored in next pointers:"<<endl;

    cout<<first->next<<endl;
    cout<<second->next<<endl;
    cout<<third->next<<endl;

    delete first;
    delete second;
    delete third;

    return 0;
}

/*
=====================================================================

Output :

Data from nodes:

11
21
51

Addresses stored in next pointers:

0x61ff08
0x61ff10
0x61ff00

(Note : Addresses may vary from system to system)

=====================================================================
*/
