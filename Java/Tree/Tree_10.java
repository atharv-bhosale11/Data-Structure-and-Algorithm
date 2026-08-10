/*
===============================================================================
Program Name    : Complete Binary Search Tree Application
Program Number  : 010
File Name       : Tree_10.java

Description     : This program demonstrates a complete
                  Binary Search Tree application with
                  insertion, searching, traversals and
                  counting operations.

                  Operations:
                  1. Insert Node
                  2. Search Node
                  3. Inorder Traversal
                  4. Preorder Traversal
                  5. Postorder Traversal
                  6. Count Total Nodes
                  7. Count Leaf Nodes
                  8. Count Parent Nodes

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Binary Search Tree
4. Dynamic Memory Allocation
5. Recursion
6. Tree Traversals
7. Searching
8. Counting Nodes

Date            : August 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================
*/

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

class Tree_10
{
    public static void main(String A[])
    {
        Tree tobj = new Tree();

        tobj.Insert(11);
        tobj.Insert(5);
        tobj.Insert(17);
        tobj.Insert(4);
        tobj.Insert(7);
        tobj.Insert(15);
        tobj.Insert(21);

        System.out.println("==================================");
        System.out.println("      Binary Search Tree");
        System.out.println("==================================");

        System.out.println("\nInorder Traversal :");
        tobj.Inorder();

        System.out.println("\nPreorder Traversal :");
        tobj.Preorder();

        System.out.println("\nPostorder Traversal :");
        tobj.Postorder();

        System.out.println("\nTotal Nodes : " + tobj.Count());

        System.out.println("Leaf Nodes : " + tobj.CountLeaf());

        System.out.println("Parent Nodes : " + tobj.CountParent());

        int iNo = 15;

        System.out.println("\nSearching Element : " + iNo);

        if(tobj.Search(iNo) == true)
        {
            System.out.println("Element is Present");
        }
        else
        {
            System.out.println("There is no such element");
        }
    }
}

/*
===============================================================================
Sample Output

==================================
      Binary Search Tree
==================================

Inorder Traversal :

4
5
7
11
15
17
21

Preorder Traversal :

11
5
4
7
17
15
21

Postorder Traversal :

4
7
5
15
21
17
11

Total Nodes : 7
Leaf Nodes : 4
Parent Nodes : 3

Searching Element : 15
Element is Present

===============================================================================
Tree Structure:

              11
            /    \
           5      17
          / \    /  \
         4   7  15  21

===============================================================================
Time Complexity:

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
