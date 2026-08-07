/*
===============================================================================
Program Name    : Binary Search Tree - Postorder Traversal
Program Number  : 006
File Name       : Tree_06.cpp

Description     : This program demonstrates insertion
                  and Postorder Traversal of Binary
                  Search Tree.

                  Traversal:
                  L R D
                  (Left -> Right -> Data)

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

// BST POSTORDER TRAVERSAL

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

        void Postorder(struct node *first);
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
// Postorder Traversal
// L R D
//
///////////////////////////////////////////////////////////////////////////////

void BST :: Postorder(struct node *first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);

        Postorder(first->rchild);

        cout<<first->data<<"\n";
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Wrapper Function
//
///////////////////////////////////////////////////////////////////////////////

void BST :: Display()
{
    Postorder(first);
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

    cout<<"Postorder Traversal :\n";

    bobj.Display();

    return 0;
}

/*
===============================================================================
Sample Output

Postorder Traversal :

4
7
5
15
21
17
11

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
