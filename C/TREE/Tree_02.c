/*
===============================================================================
Program Name    : Binary Search Tree - Insert Operation
Program Number  : 002
File Name       : BST_02.c

Description     : This program demonstrates insertion of nodes
                  in a Binary Search Tree (BST). New nodes are
                  inserted according to BST rules.

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Self-Referential Structure
2. Dynamic Memory Allocation
3. Binary Search Tree (BST)
4. Pointer Manipulation
5. Tree Traversal Logic

===============================================================================
*/

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

void Insert(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

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
                printf("Unable to insert as element is duplicate\n");
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

    printf("Nodes inserted successfully\n");

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Nodes inserted successfully

===============================================================================
Memory Representation:
===============================================================================

        11
       /  \
      5    17

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. If tree is empty, make it root node.
3. Compare new data with current node.
4. If data is smaller, move to left child.
5. If data is greater, move to right child.
6. Repeat until empty position is found.
7. Insert the node.
8. Stop.

===============================================================================
Time Complexity:
===============================================================================

Insert() : O(log n) Average Case
Insert() : O(n) Worst Case

Space Complexity : O(1)  

===============================================================================
Conclusion:
===============================================================================

Program 002 demonstrates insertion of nodes in a Binary
Search Tree. Nodes are inserted according to BST rules,
where smaller elements are stored in the left subtree and
greater elements are stored in the right subtree.

===============================================================================
*/
