/*
===============================================================================
Program Name    : Binary Search Tree Search Operation
Program Number  : 006
File Name       : Tree_06.java

Description     : This program demonstrates searching of
                  an element in a Binary Search Tree.

                  If the element is smaller than the
                  current node, the search moves to the
                  left subtree.

                  If the element is greater than the
                  current node, the search moves to the
                  right subtree.

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Binary Search Tree
4. Iteration
5. Searching

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
}

class Tree_06
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

        int iNo = 15;

        System.out.println("Searching Element : " + iNo);

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

Searching Element : 15

Element is Present

===============================================================================
Tree Structure:

              11
            /    \
           5      17
          / \    /  \
         4   7  15  21

Search for 15:

11 -> 17 -> 15

Element is Present

===============================================================================
Time Complexity:

Search() : O(log n) Average Case
Search() : O(n) Worst Case

Space Complexity : O(1)

===============================================================================
End of Program
===============================================================================
*/
