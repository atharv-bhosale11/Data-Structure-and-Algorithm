/*
=====================================================================

Name            : Singly Circular Linked List - Count Operation
Program Number  : 013

Description     : This program implements Count() function
                  which returns the total number of nodes.

Concepts Used   : Node Counter,
                  Member Functions,
                  Linked List Management

Input           : None

Output          : Number of nodes

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
        first = last = NULL;
        iCount = 0;
    }

    int Count()
    {
        return iCount;
    }
};

int main()
{
    SinglyCL sobj;

    cout<<"Number of nodes : "<<sobj.Count()<<endl;

    return 0;
}

/*
=====================================================================

Output :

Number of nodes : 0

=====================================================================
*/
