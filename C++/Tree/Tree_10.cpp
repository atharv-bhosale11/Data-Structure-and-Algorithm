/*
===============================================================================
Program Name    : Binary Search Tree - Complete Application
Program Number  : 010
File Name       : Tree_10.cpp

Description     : This program demonstrates various
                  Binary Search Tree operations.

                  Operations:
                  1. Insert Node
                  2. Search Node
                  3. Inorder Traversal
                  4. Preorder Traversal
                  5. Postorder Traversal
                  6. Count Total Nodes
                  7. Count Leaf Nodes
                  8. Count Parent Nodes

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

// COMPLETE BST APPLICATION

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

        void Inorder(struct node *first);
        void Preorder(struct node *first);
        void Postorder(struct node *first);

        int Count(struct node *first);
        int CountLeaf(struct node *first);
        int CountParent(struct node *first);

        void DisplayInorder();
        void DisplayPreorder();
        void DisplayPostorder();

        int CountNode();
        int CountLeafNode();
        int CountParentNode();
};

BST :: BST()
{
    first = NULL;
}

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

void BST :: Inorder(struct node *first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        cout<<first->data<<"\n";
        Inorder(first->rchild);
    }
}

void BST :: Preorder(struct node *first)
{
    if(first != NULL)
    {
        cout<<first->data<<"\n";
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

void BST :: Postorder(struct node *first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        cout<<first->data<<"\n";
    }
}

int BST :: Count(struct node *first)
{
    if(first == NULL)
    {
        return 0;
    }

    return Count(first->lchild) +
           Count(first->rchild) + 1;
}

int BST :: CountLeaf(struct node *first)
{
    if(first == NULL)
    {
        return 0;
    }

    if((first->lchild == NULL) &&
       (first->rchild == NULL))
    {
        return 1;
    }

    return CountLeaf(first->lchild) +
           CountLeaf(first->rchild);
}

int BST :: CountParent(struct node *first)
{
    if(first == NULL)
    {
        return 0;
    }

    if(first->lchild != NULL || first->rchild != NULL)
    {
        return 1 +
               CountParent(first->lchild) +
               CountParent(first->rchild);
    }

    return 0;
}

void BST :: DisplayInorder()
{
    Inorder(first);
}

void BST :: DisplayPreorder()
{
    Preorder(first);
}

void BST :: DisplayPostorder()
{
    Postorder(first);
}

int BST :: CountNode()
{
    return Count(first);
}

int BST :: CountLeafNode()
{
    return CountLeaf(first);
}

int BST :: CountParentNode()
{
    return CountParent(first);
}

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

    cout<<"Inorder Traversal\n";
    bobj.DisplayInorder();

    cout<<"\nPreorder Traversal\n";
    bobj.DisplayPreorder();

    cout<<"\nPostorder Traversal\n";
    bobj.DisplayPostorder();

    cout<<"\nTotal Nodes : "<<bobj.CountNode()<<endl;
    cout<<"Leaf Nodes : "<<bobj.CountLeafNode()<<endl;
    cout<<"Parent Nodes : "<<bobj.CountParentNode()<<endl;

    if(bobj.Search(15))
    {
        cout<<"Element Found\n";
    }

    return 0;
}

/*
===============================================================================
Sample Output

Inorder Traversal
4
5
7
11
15
17
21

Preorder Traversal
11
5
4
7
17
15
21

Postorder Traversal
4
7
5
15
21
17
11

Total Nodes : 7
Leaf Nodes : 4
Parent Nodes : 3

Element Found

===============================================================================
End of Program
===============================================================================
*/
