/*
===============================================================================
Program Name    : Binary Search Tree Postorder Traversal
Program Number  : 005
File Name       : Tree_05.java

Description     : This program demonstrates Postorder
                  Traversal of a Binary Search Tree.

                  Postorder Traversal follows:
                  Left -> Right -> Data

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Binary Search Tree
4. Recursion
5. Postorder Traversal

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
    // Function Name : Postorder
    // Description   : Display tree using Postorder Traversal
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

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Postorder
    // Description   : Start Postorder Traversal from first node
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Postorder()
    {
        Postorder(first);
    }
}

class Tree_05
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

        System.out.println("Postorder Traversal : ");

        tobj.Postorder();
    }
}

/*
===============================================================================
Sample Output

Postorder Traversal :

4
7
5
15
21
17
11

===============================================================================
Tree Structure:

              11
            /    \
           5      17
          / \    /  \
         4   7  15  21

Postorder:
Left -> Right -> Data

4 -> 7 -> 5 -> 15 -> 21 -> 17 -> 11

===============================================================================
End of Program
===============================================================================
*/
