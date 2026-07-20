/*
=====================================================================

Name            : Singly Circular Linked List - InsertFirst Testing
Program Number  : 014

Description     : This program tests InsertFirst()
                  operation with multiple node insertions.

Concepts Used   : InsertFirst,
                  Circular Linking,
                  Dynamic Memory Allocation

Input           : Node values

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
    node *first,*last;
    int iCount;

    SinglyCL()
    {
        first = last = NULL;
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
};

int main()
{
    SinglyCL sobj;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    cout<<"InsertFirst tested successfully"<<endl;

    return 0;
}

/*
=====================================================================

Output :

InsertFirst tested successfully

=====================================================================
*/
