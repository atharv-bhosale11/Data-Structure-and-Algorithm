/*
=====================================================================

Name            : Singly Circular Linked List - Count Operation
Program Number  : 016

Description     : This program demonstrates Count() function
                  along with insertion and display operations.

Concepts Used   : Node Counter,
                  Circular Linked List,
                  Member Functions

Input           : Node data

Output          : Displays node count

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale

=====================================================================
*/

#include<iostream>
using namespace std;

// Same node and SinglyCL class as Program 016

int main()
{
    SinglyCL sobj;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);

    sobj.Display();

    cout<<"Number of Nodes : "<<sobj.Count()<<endl;

    return 0;
}

/*
=====================================================================

Output :

-> | 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | ->

Number of Nodes : 5

=====================================================================
*/
