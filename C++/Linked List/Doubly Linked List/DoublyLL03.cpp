/*
=====================================================================

Name            : Doubly Linear Linked List - Count Function
Program Number  : 003

Description     : This program demonstrates counting the
                  number of nodes present in a Doubly
                  Linear Linked List.

                  Display() traverses and displays the 
                  linked list while Count() returns the
                  total number of nodes.

Concepts Used   : Doubly Linear Linked List,
                  Count Function,
                  Display Function,
                  Traversal,
                  Classes and Objects

Input           : No user input

Output          : Displays linked list and total number
                  of nodes

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

        int Count()
        {
            int iCount = 0;
            Node *temp = First;

            while(temp != NULL)
            {
                iCount++;
                temp = temp->next;
            }

            return iCount;
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

    cout<<"Number of nodes are : "
        <<obj.Count()<<endl;

    return 0;
}

/*
=====================================================================

Output :

| 11 | <=> | 21 | <=> | 51 | <=> NULL

Number of nodes are : 3

=====================================================================
*/
