/*
===============================================================================
Program Name    : Binary Search Tree - Preorder Traversal
Program Number  : 004
File Name       : Tree_04.c

Description     : This program demonstrates Preorder Traversal
                  (Data -> Left -> Right) in a Binary Search Tree. 
                  The traversal visits the root node first,
                  followed by the left subtree and then the
                  right subtree.

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Self-Referential Structure
2. Dynamic Memory Allocation
3. Binary Search Tree (BST)
4. Recursion
5. Tree Traversal

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

int main()
{
    PNODE head = NULL;

    Insert(&head,11);
    Insert(&head,5);
    Insert(&head,17);

    printf("Inorder Display: \n");
    Inorder(head);

    printf("Preorder Display: \n");
    Preorder(head);
    
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

===============================================================================
Memory Representation:
===============================================================================

        11
       /  \
      5    17

===============================================================================
Traversal Sequence:
===============================================================================

DLR (Data -> Left -> Right)

Step 1 : Visit Root Node
Step 2 : Visit Left Subtree
Step 3 : Visit Right Subtree

For Tree:

        11
       /  \
      5    17

Traversal Order:

11 -> 5 -> 17

===============================================================================
Algorithm:
===============================================================================

1. Display current node data.
2. Traverse Left Subtree recursively.
3. Traverse Right Subtree recursively.
4. Repeat until all nodes are visited.

===============================================================================
Time Complexity:
===============================================================================

Insert()   : O(log n) Average
Insert()   : O(n) Worst Case

Inorder()  : O(n)

Preorder() : O(n)

Space Complexity : O(h)
                                                                               
where h = Height of Tree

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates Preorder Traversal of a Binary Search
Tree using recursion. In this traversal, the root node is
visited before its left and right subtrees.

===============================================================================
*/
