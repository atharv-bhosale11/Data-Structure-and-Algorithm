/*
===============================================================================
Program Name    : Doubly Circular Linked List - Menu Driven Program
Program Number  : 010
File Name       : DoublyCL10.java

Description     : This program demonstrates a complete Menu Driven
                  implementation of a Doubly Circular Linked List
                  using Java. It allows the user to perform various
                  insertion, deletion, display, and counting
                  operations interactively.

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class and Object
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Dynamic Memory Allocation
5. Circular Linked List
6. Position Validation
7. Menu Driven Programming
8. Switch Case
9. Scanner Class

Key Learning Points:
- Insert nodes at beginning, end, and any position.
- Delete nodes from beginning, end, and any position.
- Display all nodes.
- Count total nodes.
- Validate positions.
- Build a complete interactive linked list application.

===============================================================================
*/

import java.util.*;

class node
{
    public int data;
    public node next;
    public node prev;

    node(int no)
    {
        data = no;
        next = null;
        prev = null;
    }
}

class DoublyCL
{
    private node first;
    private node last;
    private int iCount;

    public DoublyCL()
    {
        first = null;
        last = null;
        iCount = 0;
    }

    public void Display()
    {
        if(first == null)
        {
            System.out.println("Linked List is empty");
            return;
        }

        node temp = first;

        do
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }while(temp != first);

        System.out.println();
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
            first = last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }

        first.prev = last;
        last.next = first;

        iCount++;
    }

    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);

        if(first == null)
        {
            first = last = newn;
        }
        else
        {
            last.next = newn;
            newn.prev = last;
            last = newn;
        }

        first.prev = last;
        last.next = first;

        iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            first.prev = last;
            last.next = first;
        }

        iCount--;
    }

    public void DeleteLast()
    {
        if(first == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            last = last.prev;
            last.next = first;
            first.prev = last;
        }

        iCount--;
    }

    public void InsertAtPos(int iNo,int iPos)
    {
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

            for(int i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            newn.prev = temp;

            temp.next.prev = newn;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteAtPos(int iPos)
    {
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

            for(int i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;

            iCount--;
        }
    }
}

class DoublyCL10
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        DoublyCL dobj = new DoublyCL();

        int iChoice = 0;
        int iValue = 0;
        int iPos = 0;

        while(true)
        {
            System.out.println("\n------------------------------------------------");
            System.out.println("      Doubly Circular Linked List");
            System.out.println("------------------------------------------------");

            System.out.println("1  : Insert First");
            System.out.println("2  : Insert Last");
            System.out.println("3  : Insert At Position");
            System.out.println("4  : Delete First");
            System.out.println("5  : Delete Last");
            System.out.println("6  : Delete At Position");
            System.out.println("7  : Display");
            System.out.println("8  : Count");
            System.out.println("0  : Exit");

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

                    dobj.InsertAtPos(iValue,iPos);
                    break;

                case 4:
                    dobj.DeleteFirst();
                    break;

                case 5:
                    dobj.DeleteLast();
                    break;

                case 6:
                    System.out.print("Enter position : ");
                    iPos = sobj.nextInt();

                    dobj.DeleteAtPos(iPos);
                    break;

                case 7:
                    dobj.Display();
                    break;

                case 8:
                    System.out.println("Number of Nodes : " + dobj.Count());
                    break;

                case 0:
                    System.out.println("Thank you for using the application...");
                    sobj.close();
                    System.exit(0);

                default:
                    System.out.println("Invalid Choice");
            }
        }
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

------------------------------------------------
      Doubly Circular Linked List
------------------------------------------------

1  : Insert First
2  : Insert Last
3  : Insert At Position
4  : Delete First
5  : Delete Last
6  : Delete At Position
7  : Display
8  : Count
0  : Exit

Enter your choice :

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()  : O(1)

InsertLast()   : O(1)

InsertAtPos()  : O(n)

DeleteFirst()  : O(1)

DeleteLast()   : O(1)

DeleteAtPos()  : O(n)

Display()      : O(n)

Count()        : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 010 demonstrates a complete Menu Driven implementation
of a Doubly Circular Linked List in Java. The application
supports insertion, deletion, display, and counting operations
while maintaining proper circular links between nodes.

===============================================================================
*/

