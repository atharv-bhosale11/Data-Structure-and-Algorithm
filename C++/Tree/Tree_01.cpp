/*
===============================================================================
Program Name    : Binary Search Tree Skeleton
Program Number  : 001
File Name       : Tree_01.cpp

Description     : This program demonstrates the basic
                  structure of Binary Search Tree (BST).

                  It contains:
                  1. Node Structure
                  2. BST Class
                  3. Constructor

Concepts Used:
1. Self Referential Structure
2. Class and Object
3. Dynamic Memory Management
4. Binary Search Tree

Date            : August 2026
Language        : C++
Author          : Atharv Tushar Bhosale
===============================================================================
*/

// BST SKELETON

#include<iostream>

using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

class BST
{
    private:
        struct node *first;

    public:
        BST();
};

///////////////////////////////////////////////////////////////////////////////
//
// Constructor
//
///////////////////////////////////////////////////////////////////////////////

BST :: BST()
{
    first = NULL;
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    BST bobj;

    cout<<"Binary Search Tree Skeleton Created Successfully\n";

    return 0;
}

/*
===============================================================================
Sample Output

Binary Search Tree Skeleton Created Successfully

===============================================================================
End of Program
===============================================================================
*/
