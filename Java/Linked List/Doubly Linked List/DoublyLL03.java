/*
===============================================================================
Program Name    : Doubly Linear Linked List - Insert Last
Program Number  : 003
File Name       : DoublyLL03.java

Description     : This program demonstrates the implementation of the
                  InsertLast() operation in a Doubly Linear Linked List
                  using Java. The new node is inserted at the end of
                  the linked list while maintaining both next and
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
5. Insert Last Operation
6. Traversing Linked List
7. Pointer Manipulation
8. Encapsulation

Key Learning Points:
- Create a new node dynamically.
- Traverse to the last node.
- Insert the new node at the end.
- Update next and previous links.
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

    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);
        node temp = first;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
            newn.prev = temp;
        }

        iCount++;
    }
}

class DoublyLL03
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        dobj.InsertLast(11);
        dobj.InsertLast(21);
        dobj.InsertLast(51);
        dobj.InsertLast(101);

        dobj.Display();

        System.out.println("Number of Nodes : " + dobj.Count());
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> NULL
Number of Nodes : 4

===============================================================================
Memory Representation:
===============================================================================

first
 │
 ▼

NULL <- [11] <=> [21] <=> [51] <=> [101] -> NULL

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. If the list is empty, make it the first node.
3. Otherwise, traverse till the last node.
4. Link the new node after the last node.
5. Update the previous pointer.
6. Increment node count.
7. Display the linked list.

===============================================================================
Time Complexity:
===============================================================================

InsertLast()  : O(n)

Display()     : O(n)

Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 003 demonstrates the InsertLast() operation in a Doubly Linear
Linked List using Java. It appends a new node at the end of the list
while correctly maintaining both next and previous links.

===============================================================================
*/
