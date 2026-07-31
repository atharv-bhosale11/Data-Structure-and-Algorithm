/*
===============================================================================
Program Name    : Binary Search Tree - Count Nodes
Program Number  : 006
File Name       : Tree_06.c

Description     : This program demonstrates how to count the
                  total number of nodes present in a Binary
                  Search Tree using recursion.

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Self-Referential Structure
2. Dynamic Memory Allocation
3. Binary Search Tree (BST)
4. Recursion
5. Node Counting

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
        Preorder(first -> lchild);
        Preorder(first -> rchild);
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

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    Insert(&head,11);
    Insert(&head,5);
    Insert(&head,17);

    printf("Inorder Display: \n");
    Inorder(head);

    printf("Preorder Display: \n");
    Preorder(head);
    
    printf("Postorder Display: \n");
    Postorder(head);

    iRet = Count(head);
    printf("Number of Nodes are: %d\n",iRet);

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Inorder Display:

5
11
17

Preorder Display:

11
5
17

Postorder Display:

5
17
11

Number of Nodes are : 3

===============================================================================
Memory Representation:
===============================================================================

        11
       /  \
      5    17

===============================================================================
Algorithm:
===============================================================================

1. If node is NULL return 0.
2. Recursively count nodes in left subtree.
3. Recursively count nodes in right subtree.
4. Add 1 for current node.
5. Return total count.

===============================================================================
Formula:
===============================================================================

Count(Node) =
Count(Left Subtree) +
Count(Right Subtree) +
1

===============================================================================
Time Complexity:
===============================================================================

Count() : O(n)

where n = Total Number of Nodes

Space Complexity : O(h)

where h = Height of Tree

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates counting the total number of nodes
in a Binary Search Tree using recursion. Every node is visited
exactly once, making the algorithm efficient and easy to
understand. 

===============================================================================
*/
