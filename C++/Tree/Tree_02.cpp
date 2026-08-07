/*
===============================================================================
Program Name    : Binary Search Tree - Insert Node
Program Number  : 002
File Name       : Tree_02.cpp

Description     : This program demonstrates insertion
                  of nodes in Binary Search Tree.

                  Operations:
                  1. Insert Node
                  2. Create BST

Concepts Used:
1. Self Referential Structure
2. Dynamic Memory Allocation
3. Binary Search Tree
4. Class and Object

Date            : August 2026
Language        : C++
Author          : Atharv Tushar Bhosale
===============================================================================
*/

// BST INSERT NODE

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
        void Insert(int iNo);
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
// Function Name : Insert
// Description   : Insert new node into BST
//
///////////////////////////////////////////////////////////////////////////////

void BST :: Insert(int iNo)
{
    struct node *newn = NULL;
    struct node *temp = NULL;

    newn = new node;

    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(1)
        {
            if(iNo > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }

                temp = temp->rchild;
            }
            else if(iNo < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }

                temp = temp->lchild;
            }
            else
            {
                cout<<"Duplicate element not allowed\n";
                delete newn;
                break;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    BST bobj;

    bobj.Insert(11);
    bobj.Insert(5);
    bobj.Insert(17);
    bobj.Insert(4);
    bobj.Insert(7);

    cout<<"Nodes inserted successfully into BST\n";

    return 0;
}

/*
===============================================================================
Sample Output

Nodes inserted successfully into BST

BST Created Successfully

            11
          /    \
         5      17
        / \
       4   7

===============================================================================
End of Program
===============================================================================
*/
