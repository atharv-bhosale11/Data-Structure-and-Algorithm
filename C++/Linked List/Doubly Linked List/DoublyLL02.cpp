/*
=====================================================================

Name            : Doubly Linear Linked List - Display Function
Program Number  : 002

Description     : This program demonstrates creation of a
                  Doubly Linear Linked List using a class.

                  The Display() function traverses the 
                  linked list and displays all nodes.

Concepts Used   : Classes and Objects,
                  Dynamic Memory Allocation,
                  Doubly Linked List,
                  Traversal

Input           : No user input

Output          : Displays all nodes of the linked list

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale

=====================================================================
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

class DoublyLL
{
    public:
        Node *First;

        DoublyLL()
        {
            First = NULL;
        }

        void Display()
        {
            Node *temp = First;

            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" | <=> ";
                temp = temp->next;
            }

            cout<<"NULL"<<endl;
        }
};

int main()
{
    DoublyLL obj;

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

    obj.First = newn1;

    obj.Display();

    return 0;
}

/*
=====================================================================

Output :

| 11 | <=> | 21 | <=> | 51 | <=> NULL

=====================================================================
*/
