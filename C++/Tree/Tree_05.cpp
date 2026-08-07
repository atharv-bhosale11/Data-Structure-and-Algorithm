/*
===============================================================================
Program Name    : Binary Search Tree - Preorder Traversal
Program Number  : 005
File Name       : Tree_05.cpp

Description     : This program demonstrates insertion
                  and Preorder Traversal of Binary
                  Search Tree.

                  Traversal:
                  D L R
                  (Data -> Left -> Right)

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

// BST PREORDER TRAVERSAL

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

        void Preorder(struct node *first);
        void Display();
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
// Preorder Traversal
// D L R
//
///////////////////////////////////////////////////////////////////////////////

void BST :: Preorder(struct node *first)
{
    if(first != NULL)
    {
        cout<<first->data<<"\n";

        Preorder(first->lchild);

        Preorder(first->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Wrapper Function
//
///////////////////////////////////////////////////////////////////////////////

void BST :: Display()
{
    Preorder(first);
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
    bobj.Insert(15);
    bobj.Insert(21);

    cout<<"Preorder Traversal :\n";

    bobj.Display();

    return 0;
}

/*
===============================================================================
Sample Output

Preorder Traversal :

11
5
4
7
17
15
21

BST Structure

            11
          /    \
         5      17
        / \    /  \
       4   7  15  21

===============================================================================
End of Program
===============================================================================
*/
