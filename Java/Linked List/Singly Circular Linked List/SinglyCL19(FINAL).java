/*
=====================================================================
 
Name            : Singly Circular Linked List - Complete Implementation
Program Number  : 019

Description     : This program implements a complete Singly Circular
                  Linked List using Java.

                  The application provides a menu-driven interface
                  to perform various operations on the linked list.

                  Supported Operations:

                  - InsertFirst()
                  - InsertLast()
                  - InsertAtPos()
                  - DeleteFirst()
                  - DeleteLast()
                  - DeleteAtPos()
                  - Display()
                  - Count()

                  The circular nature of the linked list is maintained
                  using first and last references where last.next
                  always points to first.

Concepts Used   : Singly Circular Linked List,
                  Dynamic Memory Allocation,
                  Object Oriented Programming,
                  Constructor,
                  Traversal,
                  Insertion,
                  Deletion,
                  Position Based Operations,
                  Menu Driven Programming

Input           : User choice, node data and position

Output          : Displays linked list and operation results

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale

=====================================================================
*/

import java.util.*;

class node
{
    public int data;
    public node next;

    node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyCL
{
    public node first;
    public node last;
    public int iCount;

    public SinglyCL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void Display()
    {
        node temp = null;
        temp = first;

        if(first == null && last == null)
        {
            return;
        }

        System.out.print("->");
        do
        {
            System.out.print("| "+temp.data+" | -> ");
            temp = temp.next;
        }while(temp != last.next);
        System.out.println();
    }

    public int Count()
    {
        return  iCount;
    }

    public void InsertFirst(int no)
    {
        node newn= new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }
        last.next = first;
        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn= new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            last = newn;
        }
        last.next = first;
        iCount++;
    }

    public void InsertAtPos(int no, int iPos)
    {
        int i = 0;
        node temp = null;
        node newn = new node(no);

        if(iPos < 1 || iPos > iCount + 1)
        {
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(no);
        }
        else if(iPos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            temp = first;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            iCount++;
        }
        
    }

    public void DeleteFirst()
    {
        if(first == null && last == null)
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
            last.next = first;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        if(first == null && last == null)
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
            node temp = null;

            temp = first;

            while(temp.next != last)
            {
                temp = temp.next;
            }
            last = temp;
            last.next = first;
        }
        iCount--;
    }

    public void DeleteAtPos(int iPos)
    {
        int i = 0;
        node temp = null;
        node target = null;

        if(iPos < 1 || iPos > iCount)
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
            temp = first;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }
            target = temp.next;
            temp.next = target.next;
            iCount--;
        }
    }
}



class SinglyCL17
{
    public static void main(String A[])
    {
        Scanner sobjScanner = new Scanner(System.in);

        SinglyCL sobj = new SinglyCL();

        int iChoice = 0;
        int iNo = 0;
        int iPos = 0;

        while(true)
        {
            System.out.println("\n-----------------------------");
            System.out.println("Singly Circular Linked List");
            System.out.println("-----------------------------");
            System.out.println("1 : Insert First");
            System.out.println("2 : Insert Last");
            System.out.println("3 : Insert At Position");
            System.out.println("4 : Delete First");
            System.out.println("5 : Delete Last");
            System.out.println("6 : Delete At Position");
            System.out.println("7 : Display");
            System.out.println("8 : Count");
            System.out.println("0 : Exit");
            System.out.print("Enter your choice : ");
            iChoice = sobjScanner.nextInt();

            switch(iChoice)
            {
                case 1:
                    System.out.print("Enter data : ");
                    iNo = sobjScanner.nextInt();
                    sobj.InsertFirst(iNo);
                    break;

                case 2:
                    System.out.print("Enter data : ");
                    iNo = sobjScanner.nextInt();
                    sobj.InsertLast(iNo);
                    break;

                case 3:
                    System.out.print("Enter data : ");
                    iNo = sobjScanner.nextInt();

                    System.out.print("Enter position : ");
                    iPos = sobjScanner.nextInt();

                    sobj.InsertAtPos(iNo, iPos);
                    break;

                case 4:
                    sobj.DeleteFirst();
                    break;

                case 5:
                    sobj.DeleteLast();
                    break;

                case 6:
                    System.out.print("Enter position : ");
                    iPos = sobjScanner.nextInt();

                    sobj.DeleteAtPos(iPos);
                    break;

                case 7:
                    sobj.Display();
                    break;

                case 8:
                    System.out.println("Number of Nodes : " + sobj.Count());
                    break;

                case 0:
                    System.out.println("Thank you for using the application");
                    sobjScanner.close();
                    return;

                default:
                    System.out.println("Invalid choice");
                    break;
            }
        }
    }
}

/*
=====================================================================

Output :
Successfully performs basic operations on Singly Circular Linked List.

Operations Available :
- Insert First
- Insert Last
- Insert At Position
- Delete First
- Delete Last
- Delete At Position
- Display Nodes
- Count Nodes

Concepts Covered :
- Circular Linked List
- Dynamic Memory Allocation using Objects
- Node Traversal using do-while Loop
- Menu Driven Programming
- Object Oriented Programming in Java

Result :
All basic Singly Circular Linked List operations executed successfully.

=====================================================================
*/
