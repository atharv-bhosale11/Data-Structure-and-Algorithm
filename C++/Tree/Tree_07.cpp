/*
===============================================================================
Program Name    : Binary Search Tree - Count Total Nodes
Program Number  : 007
File Name       : Tree_07.cpp

Description     : This program demonstrates insertion
                  and counting total nodes in Binary
                  Search Tree.

                  Operations:
                  1. Insert Node
                  2. Count Total Nodes

Concepts Used:
1. Self Referential Structure
2. Dynamic Memory Allocation
3. Binary Search Tree
4. Recursion
5. Class and Object

Date            : August 2026
Language        : C++
Author          : Atharv Tushar Bhosale
===============================================================================
*/

// BST COUNT TOTAL NODES

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
        int Count(struct node *first);
        int CountNode();
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
// Count Total Nodes
//
///////////////////////////////////////////////////////////////////////////////

int BST :: Count(struct node *first)
{
    if(first == NULL)
    {
        return 0;
    }

    return Count(first->lchild) +
           Count(first->rchild) + 1;
}

///////////////////////////////////////////////////////////////////////////////
//
// Wrapper Function
//
///////////////////////////////////////////////////////////////////////////////

int BST :: CountNode()
{
    return Count(first);
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    BST bobj;
    int iRet = 0;

    bobj.Insert(11);
    bobj.Insert(5);
    bobj.Insert(17);
    bobj.Insert(4);
    bobj.Insert(7);
    bobj.Insert(15);
    bobj.Insert(21);

    iRet = bobj.CountNode();

    cout<<"Total Nodes : "<<iRet<<endl;

    return 0;
}

/*
===============================================================================
Sample Output

Total Nodes : 7

BST Structure

            11
          /    \
         5      17
        / \    /  \
       4   7  15  21

===============================================================================
Time Complexity : O(n)
Space Complexity: O(h)

End of Program
===============================================================================
*/
