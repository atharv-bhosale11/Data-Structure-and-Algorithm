/*
===============================================================================
Program Name    : Binary Search Tree Inorder Traversal
Program Number  : 003
File Name       : Tree_03.java

Description     : This program demonstrates Inorder
                  Traversal of a Binary Search Tree.

                  Inorder Traversal follows:
                  Left -> Data -> Right

                  Inorder traversal of a Binary Search
                  Tree displays elements in ascending order.

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Binary Search Tree
4. Recursion
5. Inorder Traversal

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
    // Function Name : Inorder
    // Description   : Display tree using Inorder Traversal
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

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Inorder
    // Description   : Start Inorder Traversal from first node
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Inorder()
    {
        Inorder(first);
    }
}

class Tree_03
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

        System.out.println("Inorder Traversal : ");

        tobj.Inorder();
    }
}

/*
===============================================================================
Sample Output

Inorder Traversal :

4
5
7
11
15
17
21

===============================================================================
Tree Structure:

              11
            /    \
           5      17
          / \    /  \
         4   7  15  21

Inorder:
Left -> Data -> Right

4 -> 5 -> 7 -> 11 -> 15 -> 17 -> 21

===============================================================================
End of Program
===============================================================================
*/
