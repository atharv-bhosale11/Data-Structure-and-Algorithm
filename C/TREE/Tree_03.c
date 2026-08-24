/*
===============================================================================
Program Name    : Binary Search Tree - Inorder Traversal
Program Number  : 003
File Name       : Tree_03.c

Description     : This program demonstrates Inorder Traversal
                  (Left -> Data -> Right) in a Binary Search Tree.
                  The traversal displays the elements in sorted order.

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

===============================================================================
Memory Representation:
===============================================================================

        11
       /  \
      5    17

===============================================================================
Traversal Sequence:
===============================================================================

LDR (Left -> Data -> Right)

Step 1 : Visit Left Subtree
Step 2 : Visit Root Node
Step 3 : Visit Right Subtree

For Tree:

        11
       /  \
      5    17

Traversal Order:

5 -> 11 -> 17

===============================================================================
Algorithm:
===============================================================================

1. Traverse Left Subtree recursively.
2. Display current node data.
3. Traverse Right Subtree recursively.
4. Repeat until all nodes are visited.

===============================================================================
Time Complexity:
===============================================================================

Insert()  : O(log n) Average
Insert()  : O(n) Worst Case  

Inorder() : O(n)

Space Complexity : O(h)

where h = Height of Tree

===============================================================================
Conclusion:
===============================================================================

Program 003 demonstrates Inorder Traversal of a Binary Search
Tree using recursion. Since BST follows ordering properties,
Inorder traversal displays all elements in ascending order.

===============================================================================
*/
