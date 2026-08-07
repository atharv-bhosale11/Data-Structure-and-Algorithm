/*
===============================================================================
Program Name    : Binary Search Tree - Count Leaf Nodes
Program Number  : 008
File Name       : Tree_08.cpp

Description     : This program demonstrates insertion
                  and counting Leaf Nodes in Binary
                  Search Tree.

                  Operations:
                  1. Insert Node
                  2. Count Leaf Nodes

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

// BST COUNT LEAF NODES

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
        int CountLeaf(struct node *first);
        int CountLeafNode();
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
// Count Leaf Nodes
//
///////////////////////////////////////////////////////////////////////////////

int BST :: CountLeaf(struct node *first)
{
    if(first == NULL)
    {
        return 0;
    }

    if((first->lchild == NULL) && (first->rchild == NULL))
    {
        return 1;
    }

    return CountLeaf(first->lchild) +
           CountLeaf(first->rchild);
}

///////////////////////////////////////////////////////////////////////////////
//
// Wrapper Function
//
///////////////////////////////////////////////////////////////////////////////

int BST :: CountLeafNode()
{
    return CountLeaf(first);
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

    iRet = bobj.CountLeafNode();

    cout<<"Leaf Nodes : "<<iRet<<endl;

    return 0;
}

/*
===============================================================================
Sample Output

Leaf Nodes : 4

BST Structure

            11
          /    \
         5      17
        / \    /  \
       4   7  15  21

Leaf Nodes:
4, 7, 15, 21

===============================================================================
Time Complexity : O(n)
Space Complexity: O(h)

End of Program
===============================================================================
*/
