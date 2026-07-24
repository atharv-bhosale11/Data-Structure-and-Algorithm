/*
=====================================================================

Name            : Doubly Circular Linked List - Node Structure
Program Number  : 001

Description     : This program demonstrates the basic structure
                  of a Doubly Circular Linked List node.

                  Each node contains:
                  1. Data
                  2. Next Pointer
                  3. Previous Pointer

Concepts Used   : Structure,
                  Self-Referential Structure,
                  Doubly Circular Linked List

Input           : N/A

Output          : Displays size of node structure

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

// Doubly Circular Linked List

#include<stdio.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

int main()
{
    printf("Size of NODE is : %d\n",(int)sizeof(NODE));

    return 0;
}

