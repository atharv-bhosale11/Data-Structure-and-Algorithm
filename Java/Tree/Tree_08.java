/*
===============================================================================
Program Name    : Binary Search Tree Count Leaf Nodes
Program Number  : 008
File Name       : Tree_08.java

Description     : This program demonstrates counting the
                  leaf nodes present in a Binary Search Tree.

                  A leaf node is a node which does not have
                  a left child and does not have a right child.

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Binary Search Tree
4. Recursion
5. Leaf Node
6. Counting Nodes

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
    // Function Name : CountLeaf
    // Description   : Count leaf nodes in the tree
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

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : CountLeaf
    // Description   : Start counting leaf nodes from first
    //
    ///////////////////////////////////////////////////////////////////////////

    public int CountLeaf()
    {
        return CountLeaf(first);
    }
}

class Tree_08
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

        int iRet = tobj.CountLeaf();

        System.out.println("Number of Leaf Nodes : " + iRet);
    }
}

/*
===============================================================================
Sample Output

Number of Leaf Nodes : 4

===============================================================================
Tree Structure:

              11
            /    \
           5      17
          / \    /  \
         4   7  15  21

Leaf Nodes:

4
7
15
21

Total Leaf Nodes = 4

===============================================================================
Time Complexity:

CountLeaf() : O(n)

Space Complexity : O(h)

where h = height of the tree

===============================================================================
End of Program
===============================================================================
*/
