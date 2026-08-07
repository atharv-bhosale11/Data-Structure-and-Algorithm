/*
===============================================================================
Program Name    : Binary Search Tree - Menu Driven Application
Program Number  : 012
File Name       : Tree_12.cpp

Description     : This program demonstrates various Binary
                  Search Tree operations using a menu-driven
                  application.

                  Operations:
                  1. Insert Node
                  2. Search Node
                  3. Inorder Traversal
                  4. Preorder Traversal
                  5. Postorder Traversal
                  6. Count Total Nodes
                  7. Count Leaf Nodes
                  8. Count Parent Nodes
                  9. Height of Tree
                  0. Exit

Concepts Used:
1. Self Referential Structure
2. Dynamic Memory Allocation
3. Binary Search Tree (BST)
4. Recursion
5. Menu Driven Programming
6. Class and Object

Date            : August 2026
Language        : C++
Author          : Atharv Tushar Bhosale
===============================================================================
*/

// TREE MENU DRIVEN APPLICATION

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
        int Height(struct node *first);

        void DisplayInorder();
        void DisplayPreorder();
        void DisplayPostorder();

        int CountNode();
        int CountLeafNode();
        int CountParentNode();
        int CalculateHeight();
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
// Traversals
//
///////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////
//
// Counting Functions
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

    if(first->lchild != NULL ||
       first->rchild != NULL)
    {
        return 1 +
               CountParent(first->lchild) +
               CountParent(first->rchild);
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
// Height
//
///////////////////////////////////////////////////////////////////////////////

int BST :: Height(struct node *first)
{
    int iLeft = 0;
    int iRight = 0;

    if(first == NULL)
    {
        return 0;
    }

    iLeft = Height(first->lchild);
    iRight = Height(first->rchild);

    if(iLeft > iRight)
    {
        return iLeft + 1;
    }
    else
    {
        return iRight + 1;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Wrapper Functions
//
///////////////////////////////////////////////////////////////////////////////

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

int BST :: CalculateHeight()
{
    return Height(first);
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    BST bobj;

    int iChoice = 1;
    int iNo = 0;

    while(iChoice != 0)
    {
        cout<<"\n====================================\n";
        cout<<"      Binary Search Tree Menu\n";
        cout<<"====================================\n";

        cout<<"1. Insert Node\n";
        cout<<"2. Search Node\n";
        cout<<"3. Inorder Traversal\n";
        cout<<"4. Preorder Traversal\n";
        cout<<"5. Postorder Traversal\n";
        cout<<"6. Count Total Nodes\n";
        cout<<"7. Count Leaf Nodes\n";
        cout<<"8. Count Parent Nodes\n";
        cout<<"9. Height of Tree\n";
        cout<<"0. Exit\n";

        cout<<"Enter your choice : ";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:

                cout<<"Enter element : ";
                cin>>iNo;

                bobj.Insert(iNo);
                break;

            case 2:

                cout<<"Enter element to search : ";
                cin>>iNo;

                if(bobj.Search(iNo))
                {
                    cout<<"Element Found\n";
                }
                else
                {
                    cout<<"Element Not Found\n";
                }
                break;

            case 3:

                cout<<"\nInorder Traversal\n";
                bobj.DisplayInorder();
                break;

            case 4:

                cout<<"\nPreorder Traversal\n";
                bobj.DisplayPreorder();
                break;

            case 5:

                cout<<"\nPostorder Traversal\n";
                bobj.DisplayPostorder();
                break;

            case 6:

                cout<<"Total Nodes : "
                    <<bobj.CountNode()<<endl;
                break;

            case 7:

                cout<<"Leaf Nodes : "
                    <<bobj.CountLeafNode()<<endl;
                break;

            case 8:

                cout<<"Parent Nodes : "
                    <<bobj.CountParentNode()<<endl;
                break;

            case 9:

                cout<<"Height of Tree : "
                    <<bobj.CalculateHeight()<<endl;
                break;

            case 0:

                cout<<"Thank you for using BST Application\n";
                break;

            default:

                cout<<"Invalid Choice\n";
                break;
        }
    }

    return 0;
}

/*
===============================================================================
Sample Input

Insert : 11
Insert : 5
Insert : 17
Insert : 4
Insert : 7
Insert : 15
Insert : 21

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

Total Nodes : 7
Leaf Nodes : 4
Parent Nodes : 3
Height of Tree : 3

===============================================================================
End of Program
===============================================================================
*/
