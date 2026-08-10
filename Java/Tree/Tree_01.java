/*
===============================================================================
Program Name    : Binary Search Tree Skeleton
Program Number  : 001
File Name       : Tree_01.java

Description     : This program demonstrates the basic
                  structure of a Binary Search Tree
                  using self-referential nodes.

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Binary Search Tree
4. Left and Right Child References

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
}

class Tree_01
{
    public static void main(String A[])
    {
        Tree tobj = new Tree();

        System.out.println("Binary Search Tree created successfully");
    }
}

/*
===============================================================================
Sample Output

Binary Search Tree created successfully

===============================================================================
End of Program
===============================================================================
*/
