/*
===============================================================================
Program Name    : Binary Search Tree - Menu Driven Application
Program Number  : 011
File Name       : Tree_11.java

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
                  0. Exit

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Binary Search Tree
4. Dynamic Memory Allocation
5. Recursion
6. Tree Traversals
7. Searching
8. Counting Nodes
9. Menu Driven Programming

Date            : August 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================
*/

import java.util.*;

class node
{
    public int data;
    public node lchild;
    public node rchild;
}

class Tree
{
    private node first;

    public Tree()
    {
        first = null;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Insert
    // Description   : Insert element into Binary Search Tree
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Insert(int iNo)
    {
        node newn = null;
        node temp = null;

        newn = new node();

        newn.data = iNo;
        newn.lchild = null;
        newn.rchild = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(true)
            {
                if(iNo > temp.data)
                {
                    if(temp.rchild == null)
                    {
                        temp.rchild = newn;
                        break;
                    }

                    temp = temp.rchild;
                }
                else if(iNo < temp.data)
                {
                    if(temp.lchild == null)
                    {
                        temp.lchild = newn;
                        break;
                    }

                    temp = temp.lchild;
                }
                else
                {
                    System.out.println("Duplicate element not allowed");
                    break;
                }
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Search
    // Description   : Search element in Binary Search Tree
    //
    ///////////////////////////////////////////////////////////////////////////

    public boolean Search(int iNo)
    {
        node temp = null;

        temp = first;

        while(temp != null)
        {
            if(iNo == temp.data)
            {
                return true;
            }
            else if(iNo > temp.data)
            {
                temp = temp.rchild;
            }
            else
            {
                temp = temp.lchild;
            }
        }

        return false;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Inorder
    // Description   : Left -> Data -> Right
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Inorder(node temp)
    {
        if(temp != null)
        {
            Inorder(temp.lchild);
            System.out.println(temp.data);
            Inorder(temp.rchild);
        }
    }

    public void Inorder()
    {
        Inorder(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Preorder
    // Description   : Data -> Left -> Right
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Preorder(node temp)
    {
        if(temp != null)
        {
            System.out.println(temp.data);
            Preorder(temp.lchild);
            Preorder(temp.rchild);
        }
    }

    public void Preorder()
    {
        Preorder(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Postorder
    // Description   : Left -> Right -> Data
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Postorder(node temp)
    {
        if(temp != null)
        {
            Postorder(temp.lchild);
            Postorder(temp.rchild);
            System.out.println(temp.data);
        }
    }

    public void Postorder()
    {
        Postorder(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Count
    // Description   : Count total number of nodes
    //
    ///////////////////////////////////////////////////////////////////////////

    public int Count(node temp)
    {
        if(temp == null)
        {
            return 0;
        }

        return Count(temp.lchild) +
               Count(temp.rchild) + 1;
    }

    public int Count()
    {
        return Count(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : CountLeaf
    // Description   : Count leaf nodes
    //
    ///////////////////////////////////////////////////////////////////////////

    public int CountLeaf(node temp)
    {
        if(temp == null)
        {
            return 0;
        }

        if(temp.lchild == null && temp.rchild == null)
        {
            return 1;
        }

        return CountLeaf(temp.lchild) +
               CountLeaf(temp.rchild);
    }

    public int CountLeaf()
    {
        return CountLeaf(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : CountParent
    // Description   : Count parent nodes
    //
    ///////////////////////////////////////////////////////////////////////////

    public int CountParent(node temp)
    {
        if(temp == null)
        {
            return 0;
        }

        if(temp.lchild != null || temp.rchild != null)
        {
            return 1 +
                   CountParent(temp.lchild) +
                   CountParent(temp.rchild);
        }

        return 0;
    }

    public int CountParent()
    {
        return CountParent(first);
    }
}

class Tree_11
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        Tree tobj = new Tree();

        int iChoice = 0;
        int iNo = 0;

        while(true)
        {
            System.out.println("\n==============================================");
            System.out.println("       BINARY SEARCH TREE MENU");
            System.out.println("==============================================");

            System.out.println("1. Insert Node");
            System.out.println("2. Search Node");
            System.out.println("3. Inorder Traversal");
            System.out.println("4. Preorder Traversal");
            System.out.println("5. Postorder Traversal");
            System.out.println("6. Count Total Nodes");
            System.out.println("7. Count Leaf Nodes");
            System.out.println("8. Count Parent Nodes");
            System.out.println("0. Exit");

            System.out.println("==============================================");

            System.out.print("Enter your choice : ");
            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                case 1:

                    System.out.print("Enter element : ");
                    iNo = sobj.nextInt();

                    tobj.Insert(iNo);

                    break;

                case 2:

                    System.out.print("Enter element to search : ");
                    iNo = sobj.nextInt();

                    if(tobj.Search(iNo) == true)
                    {
                        System.out.println("Element is Present");
                    }
                    else
                    {
                        System.out.println("Element is Not Present");
                    }

                    break;

                case 3:

                    System.out.println("\nInorder Traversal :");

                    tobj.Inorder();

                    break;

                case 4:

                    System.out.println("\nPreorder Traversal :");

                    tobj.Preorder();

                    break;

                case 5:

                    System.out.println("\nPostorder Traversal :");

                    tobj.Postorder();

                    break;

                case 6:

                    System.out.println("Total Nodes : " + tobj.Count());

                    break;

                case 7:

                    System.out.println("Leaf Nodes : " + tobj.CountLeaf());

                    break;

                case 8:

                    System.out.println("Parent Nodes : " + tobj.CountParent());

                    break;

                case 0:

                    System.out.println("\nThank you for using Binary Search Tree Application");

                    System.exit(0);

                    break;

                default:

                    System.out.println("Invalid Choice");

                    break;
            }
        }
    }
}

/*
===============================================================================
Sample Input / Output

==============================================
       BINARY SEARCH TREE MENU
==============================================

1. Insert Node
2. Search Node
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Count Total Nodes
7. Count Leaf Nodes
8. Count Parent Nodes
0. Exit

Enter your choice : 1
Enter element : 11

Enter your choice : 1
Enter element : 5

Enter your choice : 1
Enter element : 17

Enter your choice : 1
Enter element : 4

Enter your choice : 1
Enter element : 7

Enter your choice : 1
Enter element : 15

Enter your choice : 1
Enter element : 21

Enter your choice : 3

Inorder Traversal :
4
5
7
11
15
17
21

Enter your choice : 4

Preorder Traversal :
11
5
4
7
17
15
21

Enter your choice : 5

Postorder Traversal :
4
7
5
15
21
17
11

Enter your choice : 6
Total Nodes : 7

Enter your choice : 7
Leaf Nodes : 4

Enter your choice : 8
Parent Nodes : 3

Enter your choice : 2
Enter element to search : 15
Element is Present

Enter your choice : 0

Thank you for using Binary Search Tree Application

===============================================================================
Tree Structure

              11
            /    \
           5      17
          / \    /  \
         4   7  15  21

===============================================================================
Time Complexity

Insert()          : O(log n) Average
Search()          : O(log n) Average
Inorder()         : O(n)
Preorder()        : O(n)
Postorder()       : O(n)
Count()           : O(n)
CountLeaf()       : O(n)
CountParent()     : O(n)

Worst Case for Insert/Search : O(n)

Space Complexity : O(h)

where h = height of the tree

===============================================================================
End of Program
===============================================================================
*/
