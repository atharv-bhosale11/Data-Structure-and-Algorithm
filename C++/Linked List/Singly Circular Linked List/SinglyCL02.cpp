/*
=====================================================================

Name            : Singly Circular Linked List - Manual Node Creation
Program Number  : 002

Description     : This program demonstrates creation of nodes using
                  dynamic memory allocation.

                  Three nodes are created and initialized with data.

Concepts Used   : Dynamic Memory Allocation,
                  Structure Pointer,
                  new Operator

Input           : None

Output          : Displays node data

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
    second->data = 21;
    third->data = 51;

    cout<<first->data<<endl;
    cout<<second->data<<endl;
    cout<<third->data<<endl;

    delete first;
    delete second;
    delete third;

    return 0;
}

/*
=====================================================================

Output :

11
21
51

=====================================================================

*/
