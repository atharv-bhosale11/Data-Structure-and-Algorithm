/*
===============================================================================
Program Name    : Binary Search Tree - Count Nodes
Program Number  : 006
File Name       : BST_06.c

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

Key Learning Points:
- Create a Binary Search Tree.
- Insert nodes according to BST rules.
- Perform Inorder Traversal.
- Count total nodes recursively.
- Understand recursive tree processing.

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
    Insert(&head,21);
    Insert(&head,4);
    Insert(&head,7);
    Insert(&head,15);

    printf("Inorder Display: \n");
    Inorder(head);

    iRet = Count(head);
    printf("Number of Nodes are: %d\n",iRet);

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

Number of Nodes are : 7

===============================================================================
Memory Representation:
===============================================================================

                11
              /    \
             5      17
            / \    /  \
           4   7  15  21

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Insert node according to BST rules.
3. Perform Inorder Traversal.
4. Visit each node recursively.
5. Count current node.
6. Count left subtree nodes.
7. Count right subtree nodes.
8. Return total count.

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

Insert()   : O(log n) Average Case
Insert()   : O(n) Worst Case

Inorder()  : O(n)

Count()    : O(n)
                                                                          
Space Complexity : O(h)

where,
n = Number of Nodes
h = Height of Tree

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates how to count the total number of
nodes present in a Binary Search Tree using recursion.
Each node is visited exactly once, making the algorithm
simple and efficient.

===============================================================================
*/
