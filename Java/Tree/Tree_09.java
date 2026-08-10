/*
===============================================================================
Program Name    : Binary Search Tree Count Parent Nodes
Program Number  : 009
File Name       : Tree_09.java

Description     : This program demonstrates counting the
                  parent nodes present in a Binary Search Tree.

                  A parent node is a node which has at least
                  one child.

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Binary Search Tree
4. Recursion
5. Parent Node
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
    // Function Name : CountParent
    // Description   : Count parent nodes in the tree
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

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : CountParent
    // Description   : Start counting parent nodes from first
    //
    ///////////////////////////////////////////////////////////////////////////

    public int CountParent()
    {
        return CountParent(first);
    }
}

class Tree_09
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

        int iRet = tobj.CountParent();

        System.out.println("Number of Parent Nodes : " + iRet);
    }
}

/*
===============================================================================
Sample Output

Number of Parent Nodes : 3

===============================================================================
Tree Structure:

              11
            /    \
           5      17
          / \    /  \
         4   7  15  21

Parent Nodes:

11
5
17

Total Parent Nodes = 3

===============================================================================
Time Complexity:

CountParent() : O(n)

Space Complexity : O(h)

where h = height of the tree

===============================================================================
End of Program
===============================================================================
*/
