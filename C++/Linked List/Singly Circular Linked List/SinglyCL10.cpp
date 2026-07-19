/*
=====================================================================

Name            : Singly Circular Linked List - InsertFirst Operation
Program Number  : 010

Description     : This program implements the InsertFirst()
                  operation for a Singly Circular Linked List.

                  A new node is created and inserted at the
                  beginning of the linked list.

                  If the list is empty, both first and last
                  pointers point to the new node.

                  After insertion, the circular connection is
                  maintained by connecting the last node to
                  the first node.

Concepts Used   : Singly Circular Linked List,
                  Dynamic Memory Allocation,
                  InsertFirst Operation,
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
                first = newn;
                last = newn;
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

    cout<<"Nodes inserted successfully"<<endl;

    return 0;
}

/*
=====================================================================

Output :

Nodes inserted successfully

=====================================================================
*/
