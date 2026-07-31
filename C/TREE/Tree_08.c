/*
===============================================================================
Program Name    : Binary Search Tree - Search Operation
Program Number  : 007
File Name       : BST_08.c

Description     : This program demonstrates searching an
                  element in a Binary Search Tree (BST).
                  The search operation follows BST rules
                  to efficiently locate an element.

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Self-Referential Structure
2. Dynamic Memory Allocation
3. Binary Search Tree (BST)
4. Tree Traversal
5. Searching
6. Boolean Data Type

Key Learning Points:
- Create a Binary Search Tree.
- Insert nodes according to BST rules.
- Perform tree traversals.
- Count total nodes.
- Search an element efficiently.

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

    if(Search(head,17) == true)
    {
        printf("17 is present in BST");
    }
    else
    {
        printf("17 is not present in BST");
    }
    
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

17 is present in BST

===============================================================================
Memory Representation:
===============================================================================

                11
              /    \
             5      17
            / \    /  \
           4   7  15  21

===============================================================================
Search Operation:
===============================================================================

Searching : 17

Step 1 : Compare 17 with 11
         17 > 11
         Move Right

Step 2 : Compare 17 with 17
         Match Found

===============================================================================
Algorithm:
===============================================================================

1. Start from root node.
2. Compare target value with current node.
3. If equal, return true.
4. If greater, move to right subtree.
5. If smaller, move to left subtree.
6. Repeat until element is found or NULL occurs.
7. Return result.

===============================================================================
Time Complexity:
===============================================================================

Insert()    : O(log n) Average
Insert()    : O(n) Worst Case

Search()    : O(log n) Average
Search()    : O(n) Worst Case

Inorder()   : O(n)

Count()     : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 007 demonstrates the Search operation in a Binary
Search Tree. By utilizing BST properties, searching becomes
faster than linear searching in many cases and efficiently
locates the desired element.

===============================================================================
*/
