/*
===============================================================================
Program Name    : Doubly Linear Linked List - Insert First
Program Number  : 002
File Name       : DoublyLL02.java

Description     : This program demonstrates the implementation of the
                  InsertFirst() operation in a Doubly Linear Linked List
                  using Java. The new node is inserted at the beginning
                  of the linked list while maintaining both next and
                  previous links.

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Dynamic Memory Allocation
4. Doubly Linear Linked List
5. Insert First Operation
6. Pointer Manipulation
7. Encapsulation

Key Learning Points:
- Create a new node dynamically.
- Insert the node at the beginning.
- Update next and previous references.
- Display the linked list.
- Count total number of nodes.

===============================================================================
*/

class node
{
    public int data;
    public node next;
    public node prev;

    node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLL
{
    private node first;
    private int iCount;

    public DoublyLL()
    {
        first = null;
        iCount = 0;
    }

    public void Display()
    {

    }

    public int Count()
    {
        return iCount;
    }

    public void InsertFirst(int iNo)
    {
        node newn = new node(iNo);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }

        iCount++;
    }
}

class DoublyLL01
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.Display();

        System.out.println("Number of Nodes : " + dobj.Count());
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> NULL
Number of Nodes : 3

===============================================================================
Memory Representation:
===============================================================================

first
 │
 ▼

NULL <- [11] <=> [21] <=> [51] -> NULL

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. If the linked list is empty, make it the first node.
3. Otherwise,
   - Link the new node with the current first node.
   - Update the previous pointer of the old first node.
   - Make the new node the first node.
4. Increment the node count.
5. Display the linked list.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)
Display()     : O(n)
Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 demonstrates the InsertFirst() operation in a Doubly Linear
Linked List using Java. It inserts new nodes at the beginning of the list
while correctly maintaining both next and previous links.

===============================================================================
*/
