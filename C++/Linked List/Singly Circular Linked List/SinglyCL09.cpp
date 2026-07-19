/*
=====================================================================

Name            : Singly Circular Linked List - Function Prototypes
Program Number  : 009

Description     : This program declares all major operations
                  required for implementation of a Singly
                  Circular Linked List.

                  Function declarations are added for future
                  insertion, deletion, display and count
                  operations.

Concepts Used   : Classes,
                  Member Functions,
                  Function Prototypes,
                  Linked List Design

Input           : None

Output          : Program executed successfully

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

        void Display()
        {}

        int Count()
        {
            return iCount;
        }

        void InsertFirst(int no)
        {}

        void InsertLast(int no)
        {}

        void InsertAtPos(int no,int pos)
        {}

        void DeleteFirst()
        {}

        void DeleteLast()
        {}

        void DeleteAtPos(int pos)
        {}
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
