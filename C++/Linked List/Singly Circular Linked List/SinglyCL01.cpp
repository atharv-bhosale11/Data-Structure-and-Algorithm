/*
=====================================================================

Name            : Singly Circular Linked List - Node Structure Size
Program Number  : 001

Description     : This program demonstrates the basic node structure
                  used in a Singly Circular Linked List.

                  Each node contains:
                  - Data field
                  - Pointer to next node

                  The program displays the size occupied by the node
                  structure in memory.

Concepts Used   : Structure, Self Referential Structure,
                  Memory Layout, sizeof Operator

Input           : None

Output          : Size of node structure

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale

=====================================================================
*/

#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

int main()
{
    cout<<"Size of node is : "<<sizeof(NODE)<<endl;

    return 0;
}

/*
=====================================================================

Output :

Size of node is : 12

=====================================================================

*/
