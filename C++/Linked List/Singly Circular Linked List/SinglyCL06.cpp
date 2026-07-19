/*
=====================================================================

Name            : Singly Circular Linked List - Display Using do-while
Program Number  : 006

Description     : This program demonstrates how to display all
                  nodes of a Singly Circular Linked List using
                  a do-while loop.

                  The traversal stops when the temporary pointer
                  reaches the first node again.

Concepts Used   : Singly Circular Linked List,
                  Circular Traversal,
                  do-while Loop,
                  Pointer Manipulation

Input           : None

Output          : Displays all nodes in circular list

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
    PNODE temp = NULL;

    first->data = 11;
    first->next = second;

    second->data = 21;
    second->next = third;

    third->data = 51;
    third->next = first;

    temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }while(temp != first);

    cout<<endl;

    return 0;
}

/*
=====================================================================

Output :

| 11 | -> | 21 | -> | 51 | ->

=====================================================================
*/
