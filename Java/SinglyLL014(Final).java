///////////////////////////////////////////////////////////////
//
//  File Name   : SinglyLL014.java
//  Description : Menu Driven Singly Linear Linked List
//  Author      : Atharv Bhosale
//
//  Functionality: 
//  1. InsertFirst
//  2. InsertLast
//  3. InsertAtPos
//  4. DeleteFirst
//  5. DeleteLast
//  6. DeleteAtPos
//  7. Display
//  8. Count
//
///////////////////////////////////////////////////////////////

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

class SinglyLL
{
    private  node first;
    private  int iCount;

    public SinglyLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void Display()
    {
        node temp = first;

        while(temp != null)
        {
            System.out.print("| "+temp.data+"| -> ");
            temp = temp.next;
        }
        System.out.print("NULL");
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
            first = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }
        iCount++;
    }

    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            node temp = null;
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        iCount++;
    }

    public void InsertAtPos(int iNo,int iPos)
    {
        node temp = null;
        node newn = null;
        int i = 0;

        if(iPos < 1 || iPos > iCount + 1)
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
            newn = new node(iNo);
    
            temp = first;

            for( i = 1 ; i < iPos - 1; i++)
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
        if(first == null)
        {
            first = null;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        if(first == null)
        {
            first = null;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            node temp = first;

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
        node temp = null;
        int i = 0;

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

            for( i = 1 ; i < iPos - 1; i++)
            {
                temp = temp.next;
            }       

            temp.next = temp.next.next;

            iCount--;
        }
    }

}

class SinglyLL014
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();

        java.util.Scanner sobjX = new java.util.Scanner(System.in);

        int iChoice = 1;
        int iValue = 0;
        int iPos = 0;
        int iRet = 0;

        while(iChoice != 0)
        {
            System.out.println("\n--------------------------------------------------");
            System.out.println("            Singly Linked List Menu");
            System.out.println("--------------------------------------------------");

            System.out.println("1 : Insert First");
            System.out.println("2 : Insert Last");
            System.out.println("3 : Insert At Position");
            System.out.println("4 : Delete First");
            System.out.println("5 : Delete Last");
            System.out.println("6 : Delete At Position");
            System.out.println("7 : Display");
            System.out.println("8 : Count");
            System.out.println("0 : Exit");

            System.out.print("\nEnter your choice : ");
            iChoice = sobjX.nextInt();

            switch(iChoice)
            {
                case 1:
                    System.out.print("Enter data : ");
                    iValue = sobjX.nextInt();

                    sobj.InsertFirst(iValue);
                    break;

                case 2:
                    System.out.print("Enter data : ");
                    iValue = sobjX.nextInt();

                    sobj.InsertLast(iValue);
                    break;

                case 3:
                    System.out.print("Enter data : ");
                    iValue = sobjX.nextInt();

                    System.out.print("Enter position : ");
                    iPos = sobjX.nextInt();

                    sobj.InsertAtPos(iValue, iPos);
                    break;

                case 4:
                    sobj.DeleteFirst();
                    System.out.println("First node deleted");
                    break;

                case 5:
                    sobj.DeleteLast();
                    System.out.println("Last node deleted");
                    break;

                case 6:
                    System.out.print("Enter position : ");
                    iPos = sobjX.nextInt();

                    sobj.DeleteAtPos(iPos);
                    break;

                case 7:
                    sobj.Display();
                    break;

                case 8:
                    iRet = sobj.Count();
                    System.out.println("Number of Nodes : " + iRet);
                    break;

                case 0:
                    System.out.println("Thank you for using the application...");
                    break;

                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        }

        sobjX.close();
    }
}

///////////////////////////////////////////////////////////////
//
//  Output:
//
//  --------------------------------------------------
//              Singly Linked List Menu
//  --------------------------------------------------
//
//  1 : Insert First
//  2 : Insert Last
//  3 : Insert At Position
//  4 : Delete First
//  5 : Delete Last
//  6 : Delete At Position
//  7 : Display
//  8 : Count
//  0 : Exit
//
//  Example:
//
//  | 11| -> | 21| -> | 51| -> | 101| -> NULL
//  Number of Nodes : 4
//
///////////////////////////////////////////////////////////////
