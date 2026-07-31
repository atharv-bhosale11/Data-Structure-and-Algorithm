/*
===============================================================================
Program Name    : Binary Search Tree - Count Parent Nodes
Program Number  : 011
File Name       : Tree_11.c

Description     : This program demonstrates how to count the
                  total number of Parent Nodes present in a
                  Binary Search Tree using recursion.

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Self-Referential Structure
2. Dynamic Memory Allocation
3. Binary Search Tree (BST)
4. Recursion
5. Parent Node Counting

Key Learning Points:
- Create a Binary Search Tree.
- Insert nodes according to BST rules.
- Search elements in BST.
- Count total nodes.
- Count leaf nodes.
- Count parent nodes recursively.

===============================================================================
*/

// TREE

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

// L    D   R
void Inorder(PNODE first)
{
    if(first != NULL)
    {
        Inorder(first -> lchild);
        printf("%d\n",first -> data);
        Inorder(first -> rchild);
    }
}

// D    L   R
void Preorder(PNODE first)
{
    if(first != NULL)
    {
        printf("%d\n",first -> data);
        Preorder(first -> lchild);
        Preorder(first -> rchild);
    }
}

// L    R   D
void Postorder(PNODE first)
{
    if(first != NULL)
    {
        Postorder(first -> lchild);
        Postorder(first -> rchild);
        printf("%d\n",first -> data);
    }
}

void Insert(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> lchild = NULL;
    newn -> rchild = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(1)
        {
            if(iNo > temp -> data)
            {
                if(temp -> rchild == NULL)
                {
                    temp -> rchild = newn;
                    break;
                }
                temp = temp -> rchild;
            }
            else if(iNo < temp -> data)
            {
                if(temp -> lchild == NULL)
                {
                    temp -> lchild = newn;
                    break;
                }
                temp = temp -> lchild;
            }
            else if(iNo == temp -> data)
            {
                printf("Unable to Insert as Elements is Duplicate");
                free(newn);
                break;
            }
        }
    }
}

bool Search(PNODE first, int iNo)
{
    bool bFlag = false;

    while(first != NULL)
    {
        if(iNo == first -> data)
        {
            bFlag = true;
            break;
        }
        else if(iNo > first -> data)
        {
            first = first -> rchild;
        }
        else if(iNo < first -> data)
        {
            first = first -> lchild;
        }
    }
    return bFlag;
}

int Count(PNODE first)
{
    static int iCount = 0;
    

    if(first != NULL)
    {
        iCount++;
        Count(first -> lchild);
        Count(first -> rchild);
    }
    return iCount;
}

int CountLeaf(PNODE first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        if(first -> lchild == NULL && first -> rchild == NULL)
        {
            iCount++;
        }
        CountLeaf(first -> lchild);
        CountLeaf(first -> rchild);
    }
    return iCount;
}

int CountParent(PNODE first)
{
    static int iCount = 0;

    if(first != NULL)
    {
        if(first -> lchild != NULL || first -> rchild != NULL)
        {
            iCount++;
        }
        CountParent(first -> lchild);
        CountParent(first -> rchild);
    }
    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    Insert(&head,11);
    Insert(&head,5);
    Insert(&head,17);
    Insert(&head,21);
    Insert(&head,4);
    Insert(&head,7);
    Insert(&head,15);

    printf("Inorder Display: \n");
    Inorder(head);

    iRet = Count(head);
    printf("Number of Nodes are: %d\n",iRet);

    if(Search(head,25) == true)
    {
        printf("25 is present in BST\n");
    }
    else
    {
        printf("25 is not present in BST\n");
    }
    
    iRet = CountLeaf(head);
    printf("Number of Leaf Nodes are: %d\n",iRet);

    iRet = CountParent(head);
    printf("Number of Parent Nodes are: %d\n",iRet);

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Inorder Display:

4
5
7
11
15
17
21

Number of Nodes are: 7

25 is not present in BST

Number of Leaf Nodes are: 4

Number of Parent Nodes are: 3

===============================================================================
Memory Representation:
===============================================================================

                11
              /    \
             5      17
            / \    /  \
           4   7  15  21

Parent Nodes : 11, 5, 17
Leaf Nodes   : 4, 7, 15, 21

===============================================================================
Algorithm:
===============================================================================

1. Start from root node.
2. Check whether current node has at least one child.
3. If left child or right child exists, increment count.
4. Recursively traverse left subtree.
5. Recursively traverse right subtree.
6. Return total parent node count.

===============================================================================
Condition Used:
===============================================================================

if(first->lchild != NULL || first->rchild != NULL)

A Parent Node is a node having at least one child.

===============================================================================
Time Complexity:
===============================================================================

Insert()       : O(log n) Average
Search()       : O(log n) Average

Count()        : O(n)

CountLeaf()    : O(n)

CountParent()  : O(n)

Space Complexity : O(h)

where,

n = Number of Nodes
h = Height of Tree

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates how to count Parent Nodes in a
Binary Search Tree using recursion. A Parent Node is a node
that contains at least one child node. Each node is visited
exactly once during traversal.

===============================================================================
*/
