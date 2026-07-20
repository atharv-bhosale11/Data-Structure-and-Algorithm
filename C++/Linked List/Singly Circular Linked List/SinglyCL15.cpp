/*
=====================================================================

Name            : Singly Circular Linked List - Display Operation 
Program Number  : 015

Description     : This program implements Display() along with
                  InsertFirst() and InsertLast() operations.

                  The linked list is traversed using a do-while
                  loop and all nodes are displayed.

Concepts Used   : Singly Circular Linked List,
                  Display Operation,
                  InsertFirst,
                  InsertLast,
                  Circular Traversal

Input           : Node data

Output          : Displays all nodes of linked list

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
        first = NULL;
        last = NULL;
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

    int Count()
    {
        return iCount;
    }

    void InsertFirst(int no)
    {
        node* newn = new node(no);

        if(first == NULL && last == NULL)
        {
            first = last = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }

        last->next = first;
        iCount++;
    }

    void InsertLast(int no)
    {
        node* newn = new node(no);

        if(first == NULL && last == NULL)
        {
            first = last = newn;
        }
        else
        {
            last->next = newn;
            last = newn;
        }

        last->next = first;
        iCount++;
    }
};

int main()
{
    SinglyCL sobj;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);

    sobj.Display();

    return 0;
}

/*
=====================================================================

Output :

-> | 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | ->

=====================================================================
*/
