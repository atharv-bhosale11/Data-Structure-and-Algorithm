/*
===============================================================================
Program Name    : Binary Search Tree - Height Calculation
Program Number  : 011
File Name       : Tree_11.cpp

Description     : This program demonstrates insertion
                  of nodes and calculation of Height
                  of Binary Search Tree.

                  Operations:
                  1. Insert Node
                  2. Calculate Height

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

// BST HEIGHT CALCULATION

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

        int Height(struct node *first);
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
// Function Name : Height
// Description   : Calculate Height of BST
//
///////////////////////////////////////////////////////////////////////////////

int BST :: Height(struct node *first)
{
    int iLeftHeight = 0;
    int iRightHeight = 0;

    if(first == NULL)
    {
        return 0;
    }

    iLeftHeight = Height(first->lchild);
    iRightHeight = Height(first->rchild);

    if(iLeftHeight > iRightHeight)
    {
        return iLeftHeight + 1;
    }
    else
    {
        return iRightHeight + 1;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : CalculateHeight
// Description   : Wrapper Function
//
///////////////////////////////////////////////////////////////////////////////

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

    int iRet = 0;

    bobj.Insert(11);
    bobj.Insert(5);
    bobj.Insert(17);
    bobj.Insert(4);
    bobj.Insert(7);
    bobj.Insert(15);
    bobj.Insert(21);

    iRet = bobj.CalculateHeight();

    cout<<"Height of BST is : "<<iRet<<endl;

    return 0;
}

/*
===============================================================================
Sample Output

Height of BST is : 3

BST Structure

            11
          /    \
         5      17
        / \    /  \
       4   7  15  21

Level 1 : 11
Level 2 : 5, 17
Level 3 : 4, 7, 15, 21

Height = 3

===============================================================================
Time Complexity : O(n)
Space Complexity: O(h)

End of Program
===============================================================================
*/
