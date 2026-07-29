/*
===============================================================================
Program Name    : Doubly Linear Linked List - Menu Driven Program
Program Number  : 010
File Name       : DoublyLL10.java

Description     : This program demonstrates a complete Menu Driven
                  implementation of a Doubly Linear Linked List using
                  Java. It allows the user to perform various insertion,
                  deletion, display, and counting operations
                  interactively through a user-friendly menu.

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class and Object
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Dynamic Memory Allocation
5. Doubly Linear Linked List
6. Encapsulation
7. Pointer Manipulation (References)
8. Menu Driven Programming
9. Switch Case
10. Constructor

Key Learning Points:
- Create and manage a Doubly Linear Linked List.
- Perform insertion at the beginning, end, and any position.
- Perform deletion from the beginning, end, and any position.
- Display all nodes of the linked list.
- Count the total number of nodes.
- Validate user input before performing operations.
- Build an interactive menu-driven linked list application.

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

    public void InsertAtPos(int iNo, int iPos)
    {
        int i = 0;

        if((iPos < 1) || (iPos > iCount + 1))
        {
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(iNo);
        }
        else if(iPos == iCount + 1)
        {
            InsertLast(iNo);
        }
        else
        {
            node newn = new node(iNo);
            node temp = first;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;

            temp.next = newn;
            newn.prev = temp;

            iCount++;
        }
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

    public void DeleteLast()
    {
        node temp = first;

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
            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
        }

        iCount--;
    }

    public void DeleteAtPos(int iPos)
    {
        int i = 0;

        if((iPos < 1) || (iPos > iCount))
        {
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount)
        {
            DeleteLast();
        }
        else
        {
            node temp = first;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;

            iCount--;
        }
    }
}

class DoublyLL10
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        java.util.Scanner sobj = new java.util.Scanner(System.in);

        int iChoice = 0;
        int iValue = 0;
        int iPos = 0;
        int iRet = 0;

        while(true)
        {
            System.out.println("\n--------------------------------------------------");
            System.out.println("        Doubly Linear Linked List");
            System.out.println("--------------------------------------------------");

            System.out.println("1. Insert First:");
            System.out.println("2. Insert Last:");
            System.out.println("3. Insert At Position");
            System.out.println("4. Delete First:");
            System.out.println("5. Delete Last:");
            System.out.println("6. Delete At Position:");
            System.out.println("7. Display:");
            System.out.println("8. Count:");
            System.out.println("0. Exit:");

            System.out.print("\nEnter your choice : ");
            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                case 1:
                    System.out.print("Enter data : ");
                    iValue = sobj.nextInt();

                    dobj.InsertFirst(iValue);
                    break;

                case 2:
                    System.out.print("Enter data : ");
                    iValue = sobj.nextInt();

                    dobj.InsertLast(iValue);
                    break;

                case 3:
                    System.out.print("Enter data : ");
                    iValue = sobj.nextInt();

                    System.out.print("Enter position : ");
                    iPos = sobj.nextInt();

                    dobj.InsertAtPos(iValue, iPos);
                    break;

                case 4:
                    dobj.DeleteFirst();
                    System.out.println("First node deleted successfully.");
                    break;

                case 5:
                    dobj.DeleteLast();
                    System.out.println("Last node deleted successfully.");
                    break;

                case 6:
                    System.out.print("Enter position : ");
                    iPos = sobj.nextInt();

                    dobj.DeleteAtPos(iPos);
                    System.out.println("Node deleted successfully.");
                    break;

                case 7:
                    dobj.Display();
                    break;

                case 8:
                    iRet = dobj.Count();
                    System.out.println("Number of Nodes : " + iRet);
                    break;

                case 0:
                    System.out.println("Thank you for using Doubly Linear Linked List.");
                    sobj.close();
                    return;

                default:
                    System.out.println("Invalid Choice...");
                    break;
            }
        }
    }
}
