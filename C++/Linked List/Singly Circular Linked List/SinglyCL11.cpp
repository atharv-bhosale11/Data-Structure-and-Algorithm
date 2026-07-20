/*
=====================================================================

Name            : Singly Circular Linked List - InsertLast Operation
Program Number  : 011

Description     : This program implements the InsertLast()
                  operation for a Singly Circular Linked List.

                  A new node is inserted at the end of the list
                  while maintaining the circular connection.

Concepts Used   : Singly Circular Linked List,
                  InsertLast,
                  Dynamic Memory Allocation,
                  Circular Linking

Input           : Node data

Output          : Nodes inserted successfully

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
    node* first;
    node* last;
    int iCount;

    SinglyCL()
    {
        first = NULL;
        last = NULL;
        iCount = 0;
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

    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(51);
    sobj.InsertLast(101);

    cout<<"InsertLast executed successfully"<<endl;

    return 0;
}

/*
=====================================================================

Output :

InsertLast executed successfully

=====================================================================
*/
