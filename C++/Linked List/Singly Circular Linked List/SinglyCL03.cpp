/*
=====================================================================

Name            : Singly Circular Linked List - Manual Linking
Program Number  : 003

Description     : This program demonstrates linking multiple nodes
                  together using next pointers.

                  The list is linear and not circular yet.

Concepts Used   : Node Linking,
                  Pointer Assignment,
                  Linked Structure

Input           : None

Output          : Displays linked node data

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

    first->next = second;
    second->next = third;
    third->next = NULL;

    cout<<first->data<<endl;
    cout<<second->data<<endl;
    cout<<third->data<<endl;

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
