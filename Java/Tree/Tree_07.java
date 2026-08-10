/*
===============================================================================
Program Name    : Binary Search Tree Count Nodes
Program Number  : 007
File Name       : Tree_07.java

Description     : This program demonstrates counting the
                  total number of nodes present in a
                  Binary Search Tree.

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Binary Search Tree
4. Recursion
5. Counting Nodes

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

        return Count(temp.lchild) + Count(temp.rchild) + 1;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Count
    // Description   : Start counting from first node
    //
    ///////////////////////////////////////////////////////////////////////////

    public int Count()
    {
        return Count(first);
    }
}

class Tree_07
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

        int iRet = tobj.Count();

        System.out.println("Total Number of Nodes : " + iRet);
    }
}

/*
===============================================================================
Sample Output

Total Number of Nodes : 7

===============================================================================
Tree Structure:

              11
            /    \
           5      17
          / \    /  \
         4   7  15  21

Total Nodes:

7

===============================================================================
Time Complexity:

Count() : O(n)

Space Complexity : O(h)

where h = height of the tree

===============================================================================
End of Program
===============================================================================
*/
