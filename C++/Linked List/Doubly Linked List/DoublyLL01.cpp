/*
=====================================================================

Name            : Doubly Linear Linked List - Node Creation
Program Number  : 001
 
Description     : This program demonstrates creation of
                  nodes in a Doubly Linear Linked List
                  and connecting them manually using
                  next and prev pointers.

Concepts Used   : Classes and Objects,
                  Dynamic Memory Allocation,
                  Doubly Linked List,
                  Pointer Connections

Input           : No user input

Output          : Displays connected nodes

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale

=====================================================================
*/\

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
    Node *First = NULL;

    Node *newn1 = new Node;
    Node *newn2 = new Node;
    Node *newn3 = new Node;

    newn1->data = 11;
    newn1->next = newn2;
    newn1->prev = NULL;

    newn2->data = 21;
    newn2->next = newn3;
    newn2->prev = newn1;

    newn3->data = 51;
    newn3->next = NULL;
    newn3->prev = newn2;

    First = newn1;

    while(First != NULL)
    {
        cout<<"| "<<First->data<<" | <=> ";
        First = First->next;
    }

    cout<<"NULL"<<endl;

    return 0;
}

/*
=====================================================================

Output :

| 11 | <=> | 21 | <=> | 51 | <=> NULL

=====================================================================
*/
