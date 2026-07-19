/*
=====================================================================

Name            : Singly Circular Linked List - Traversal Using Temp
Program Number  : 005

Description     : This program demonstrates traversal of a
                  Singly Circular Linked List using a temporary
                  pointer.

                  The temporary pointer moves through each node
                  manually to observe the circular behavior of
                  the linked list.

Concepts Used   : Singly Circular Linked List,
                  Dynamic Memory Allocation,
                  Pointer Traversal,
                  Circular Linking

Input           : None

Output          : Displays node data while traversing

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

    cout<<temp->data<<endl;

    temp = temp->next;
    cout<<temp->data<<endl;

    temp = temp->next;
    cout<<temp->data<<endl;

    temp = temp->next;
    cout<<temp->data<<endl;

    return 0;
}

/*
=====================================================================

Output :

11
21
51
11

=====================================================================
*/
