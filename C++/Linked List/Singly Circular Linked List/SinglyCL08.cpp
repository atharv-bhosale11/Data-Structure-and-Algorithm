/*
=====================================================================

Name            : Singly Circular Linked List - Class Skeleton
Program Number  : 008

Description     : This program demonstrates the basic class
                  structure required for implementation of a
                  Singly Circular Linked List.

                  The class contains first pointer, last pointer
                  and node counter.

Concepts Used   : Classes,
                  Constructors,
                  Encapsulation,
                  Linked List Design

Input           : None

Output          : Object creation successful

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
};

int main()
{
    SinglyCL sobj;

    return 0;
}

/*
=====================================================================

Output :

Program executed successfully

=====================================================================
*/
