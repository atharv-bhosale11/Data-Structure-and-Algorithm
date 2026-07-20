/*
=====================================================================

Name            : Singly Circular Linked List - Display Operation
Program Number  : 012

Description     : This program implements the Display()
                  function to display all nodes from the
                  circular linked list.

Concepts Used   : Traversal,
                  do-while Loop,
                  Circular Linked List

Input           : None

Output          : Displays linked list contents

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale

=====================================================================
*/

#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int no)
    {
        data = no;
        next = NULL;
    }
};

class SinglyCL
{
public:
    node *first,*last;
    int iCount;

    SinglyCL()
    {
        first = last = NULL;
        iCount = 0;
    }

    void Display()
    {
        node* temp = first;

        if(first == NULL && last == NULL)
        {
            return;
        }

        cout<<"-> ";

        do
        {
            cout<<"| "<<temp->data<<" | -> ";
            temp = temp->next;
        }while(temp != last->next);

        cout<<endl;
    }
};

int main()
{
    cout<<"Display Function Implemented"<<endl;

    return 0;
}

/*
=====================================================================

Output :

Display Function Implemented

=====================================================================
*/
