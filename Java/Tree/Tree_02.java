/*
===============================================================================
Program Name    : Binary Search Tree Insert Operation
Program Number  : 002
File Name       : Tree_02.java

Description     : This program demonstrates insertion of
                  elements into a Binary Search Tree.

                  Smaller elements are inserted into the
                  left subtree and greater elements are
                  inserted into the right subtree.

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Binary Search Tree
4. Dynamic Memory Allocation
5. Iteration

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
}

class Tree_02
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

        System.out.println("Elements inserted successfully");
    }
}

/*
===============================================================================
Sample Output

Elements inserted successfully

Binary Search Tree:

              11
            /    \
           5      17
          / \    /  \
         4   7  15  21

===============================================================================
End of Program
===============================================================================
*/
