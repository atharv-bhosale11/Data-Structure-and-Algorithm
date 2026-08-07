/*
===============================================================================
Program Name    : Binary Search Tree - Search Node
Program Number  : 003
File Name       : Tree_03.cpp

Description     : This program demonstrates insertion
                  and searching operation in Binary
                  Search Tree.

                  Operations:
                  1. Insert Node
                  2. Search Node

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

// BST SEARCH NODE

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
        bool Search(int iNo);
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
// Insert Node
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
// Search Node
//
///////////////////////////////////////////////////////////////////////////////

bool BST :: Search(int iNo)
{
    struct node *temp = first;

    while(temp != NULL)
    {
        if(iNo == temp->data)
        {
            return true;
        }
        else if(iNo > temp->data)
        {
            temp = temp->rchild;
        }
        else
        {
            temp = temp->lchild;
        }
    }

    return false;
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

    if(bobj.Search(7) == true)
    {
        cout<<"Element Found\n";
    }
    else
    {
        cout<<"Element Not Found\n";
    }

    if(bobj.Search(21) == true)
    {
        cout<<"Element Found\n";
    }
    else
    {
        cout<<"Element Not Found\n";
    }

    return 0;
}

/*
===============================================================================
Sample Output

Element Found
Element Not Found

BST Structure

            11
          /    \
         5      17
        / \
       4   7

===============================================================================
End of Program
===============================================================================
*/
