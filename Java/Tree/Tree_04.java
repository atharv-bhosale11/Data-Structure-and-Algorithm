/*
===============================================================================
Program Name    : Binary Search Tree Preorder Traversal
Program Number  : 004
File Name       : Tree_04.java

Description     : This program demonstrates Preorder
                  Traversal of a Binary Search Tree.

                  Preorder Traversal follows:
                  Data -> Left -> Right

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Binary Search Tree
4. Recursion
5. Preorder Traversal

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
    // Function Name : Preorder
    // Description   : Display tree using Preorder Traversal
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

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Preorder
    // Description   : Start Preorder Traversal from first node
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Preorder()
    {
        Preorder(first);
    }
}

class Tree_04
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

        System.out.println("Preorder Traversal : ");

        tobj.Preorder();
    }
}

/*
===============================================================================
Sample Output

Preorder Traversal :

11
5
4
7
17
15
21

===============================================================================
Tree Structure:

              11
            /    \
           5      17
          / \    /  \
         4   7  15  21

Preorder:
Data -> Left -> Right

11 -> 5 -> 4 -> 7 -> 17 -> 15 -> 21

===============================================================================
End of Program
===============================================================================
*/
