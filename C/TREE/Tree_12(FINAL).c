/*
===============================================================================
Program Name    : Binary Search Tree - Menu Driven Application
Program Number  : 012
File Name       : Tree_12.c

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

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Self-Referential Structure
2. Dynamic Memory Allocation
3. Binary Search Tree (BST)
4. Recursion
5. Menu Driven Programming

===============================================================================
*/

// TREE MENU DRIVEN APPLICATION

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

// L D R
void Inorder(PNODE first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        printf("%d\n", first->data);
        Inorder(first->rchild);
    }
}

// D L R
void Preorder(PNODE first)
{
    if(first != NULL)
    {
        printf("%d\n", first->data);
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

// L R D
void Postorder(PNODE first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        printf("%d\n", first->data);
    }
}

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
                printf("Duplicate element not allowed\n");
                free(newn);
                break;
            }
        }
    }
}

bool Search(PNODE first, int iNo)
{
    while(first != NULL)
    {
        if(iNo == first->data)
        {
            return true;
        }
        else if(iNo > first->data)
        {
            first = first->rchild;
        }
        else
        {
            first = first->lchild;
        }
    }

    return false;
}

int Count(PNODE first)
{
    if(first == NULL)
    {
        return 0;
    }

    return Count(first->lchild) +
           Count(first->rchild) + 1;
}

int CountLeaf(PNODE first)
{
    if(first == NULL)
    {
        return 0;
    }

    if((first->lchild == NULL) && (first->rchild == NULL))
    {
        return 1;
    }

    return CountLeaf(first->lchild) +
           CountLeaf(first->rchild);
}

int CountParent(PNODE first)
{
    if(first == NULL)
    {
        return 0;
    }

    if(first->lchild != NULL || first->rchild != NULL)
    {
        return 1 + CountParent(first->lchild)
                 + CountParent(first->rchild);
    }

    return 0;
}

int main()
{
    PNODE head = NULL;

    int iChoice = 1;
    int iNo = 0;

    while(iChoice != 0)
    {
        printf("\n====================================\n");
        printf("      Binary Search Tree Menu\n");
        printf("====================================\n");

        printf("1. Insert Node\n");
        printf("2. Search Node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Count Total Nodes\n");
        printf("7. Count Leaf Nodes\n");
        printf("8. Count Parent Nodes\n");
        printf("0. Exit\n");

        printf("Enter your choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter element : ");
                scanf("%d",&iNo);

                Insert(&head,iNo);
                break;

            case 2:
                printf("Enter element to search : ");
                scanf("%d",&iNo);

                if(Search(head,iNo))
                {
                    printf("Element Found\n");
                }
                else
                {
                    printf("Element Not Found\n");
                }
                break;

            case 3:
                printf("\nInorder Traversal:\n");
                Inorder(head);
                break;

            case 4:
                printf("\nPreorder Traversal:\n");
                Preorder(head);
                break;

            case 5:
                printf("\nPostorder Traversal:\n");
                Postorder(head);
                break;

            case 6:
                printf("Total Nodes : %d\n", Count(head));
                break;

            case 7:
                printf("Leaf Nodes : %d\n", CountLeaf(head));
                break;

            case 8:
                printf("Parent Nodes : %d\n", CountParent(head));
                break;

            case 0:
                printf("Thank you for using BST Application\n");
                break;

            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}

/*
===============================================================================
Sample Input:
===============================================================================

Insert : 11
Insert : 5
Insert : 17
Insert : 4
Insert : 7
Insert : 15
Insert : 21

===============================================================================
Memory Representation:
===============================================================================

                11
              /    \
             5      17
            / \    /  \
           4   7  15  21

===============================================================================
Time Complexity:
===============================================================================

Insert()       : O(log n) Average
Search()       : O(log n) Average

Inorder()      : O(n)
Preorder()     : O(n)
Postorder()    : O(n)

Count()        : O(n)
CountLeaf()    : O(n)
CountParent()  : O(n)

Space Complexity : O(h)

===============================================================================
Conclusion:
===============================================================================

Program 010 demonstrates a complete Menu Driven Binary
Search Tree application. It performs insertion, searching,
tree traversals and counting operations using recursion.

===============================================================================
*/
