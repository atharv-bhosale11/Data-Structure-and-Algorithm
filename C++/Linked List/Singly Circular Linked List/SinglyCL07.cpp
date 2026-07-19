/*
=====================================================================

Name            : Singly Circular Linked List - Node Constructor
Program Number  : 007

Description     : This program demonstrates the use of a
                  parameterized constructor within the node class.

                  The constructor initializes node data and
                  next pointer automatically.

Concepts Used   : Classes,
                  Constructors,
                  Dynamic Memory Allocation,
                  Object Initialization

Input           : None

Output          : Displays initialized node data

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

int main()
{
    node* first = new node(11);

    cout<<first->data<<endl;

    return 0;
}

/*
=====================================================================

Output :

11

=====================================================================
*/
