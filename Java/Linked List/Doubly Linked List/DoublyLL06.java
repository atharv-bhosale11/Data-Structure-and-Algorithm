/*
===============================================================================
Program Name    : Doubly Linear Linked List - Delete First
Program Number  : 006
File Name       : DoublyLL06.java

Description     : This program demonstrates the implementation of the
                  DeleteFirst() operation in a Doubly Linear Linked List
                  using Java. The first node of the linked list is
                  deleted while maintaining proper next and previous
                  links.

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Doubly Linear Linked List
4. Delete First Operation
5. Pointer Manipulation
6. Encapsulation

Key Learning Points:
- Delete the first node.
- Handle empty and single node list.
- Update next and previous links.
- Maintain node count.

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
        node temp = first;

        while(temp != null)
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }

        System.out.println("NULL");
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

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
            first.prev = null;
        }

        iCount--;
    }
}

class DoublyLL06
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);

        System.out.println("Before DeleteFirst()");
        dobj.Display();
        System.out.println("Number of Nodes : " + dobj.Count());

        dobj.DeleteFirst();

        System.out.println("After DeleteFirst()");
        dobj.Display();
        System.out.println("Number of Nodes : " + dobj.Count());
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Before DeleteFirst()
| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL
Number of Nodes : 5

After DeleteFirst()
| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL
Number of Nodes : 4

===============================================================================
Memory Representation:
===============================================================================

Before Deletion

first
 │
 ▼

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] -> NULL

After Deletion

first
 │
 ▼

NULL <- [21] <=> [51] <=> [101] <=> [111] -> NULL

===============================================================================
Algorithm:
===============================================================================

1. Check whether the linked list is empty.
2. If only one node is present, make first NULL.
3. Otherwise move first to the next node.
4. Set first.prev to NULL.
5. Decrement node count.
6. Display the updated linked list.

===============================================================================
Time Complexity:
===============================================================================

DeleteFirst() : O(1)

Display()     : O(n)

Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates the DeleteFirst() operation in a Doubly Linear
Linked List using Java. It removes the first node efficiently while
maintaining the correct links and updating the node count.

===============================================================================
*/
