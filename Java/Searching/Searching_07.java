/*
===============================================================================
Program Name    : Searching Menu Driven Application
Program Number  : 007
File Name       : Searching_07.java

Description     : This program demonstrates a complete
                  Menu Driven Searching Application
                  using an array.

                  Operations:
                  1. Accept Elements
                  2. Display Elements
                  3. Linear Search
                  4. Bi-Directional Search
                  5. Exit

Concepts Used:
1. Class and Object
2. Dynamic Memory Allocation
3. Array Handling
4. Linear Search
5. Bi-Directional Search
6. Boolean Flag
7. Menu Driven Programming

Date            : August 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================
*/

import java.util.*;

class Searching
{
    private int Arr[];
    private int iSize;

    public Searching(int iNo)
    {
        iSize = iNo;
        Arr = new int[iSize];
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Accept
    // Description   : Accept elements from user
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Accept()
    {
        Scanner sobj = new Scanner(System.in);

        int i = 0;

        System.out.println("\nEnter the Elements : ");

        for(i = 0; i < iSize; i++)
        {
            Arr[i] = sobj.nextInt();
        }

        System.out.println("Elements accepted successfully");
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Display
    // Description   : Display elements of the array
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Display()
    {
        int i = 0;

        System.out.println("\nElements of the Array are : ");

        for(i = 0; i < iSize; i++)
        {
            System.out.println(Arr[i]);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : LinearSearch
    // Description   : Search element sequentially
    //
    ///////////////////////////////////////////////////////////////////////////

    public boolean LinearSearch(int iNo)
    {
        boolean bFlag = false;

        int i = 0;

        for(i = 0; i < iSize; i++)
        {
            if(Arr[i] == iNo)
            {
                bFlag = true;
                break;
            }
        }

        return bFlag;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : BiDirectionalSearch
    // Description   : Search element from both ends
    //
    ///////////////////////////////////////////////////////////////////////////

    public boolean BiDirectionalSearch(int iNo)
    {
        int iStart = 0;
        int iEnd = 0;

        boolean bFlag = false;

        iStart = 0;
        iEnd = iSize - 1;

        while(iStart <= iEnd)
        {
            if(Arr[iStart] == iNo || Arr[iEnd] == iNo)
            {
                bFlag = true;
                break;
            }

            iStart++;
            iEnd--;
        }

        return bFlag;
    }
}

class Searching_07
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        Searching sobjSearch = new Searching(5);

        int iChoice = 0;
        int iNo = 0;

        while(true)
        {
            System.out.println("\n==============================================");
            System.out.println("       SEARCHING MENU DRIVEN APPLICATION");
            System.out.println("==============================================");

            System.out.println("1. Accept Elements");
            System.out.println("2. Display Elements");
            System.out.println("3. Linear Search");
            System.out.println("4. Bi-Directional Search");
            System.out.println("5. Exit");

            System.out.println("==============================================");

            System.out.print("Enter your choice : ");
            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                case 1:

                    sobjSearch.Accept();
                    break;

                case 2:

                    sobjSearch.Display();
                    break;

                case 3:

                    System.out.print("Enter element to search : ");
                    iNo = sobj.nextInt();

                    if(sobjSearch.LinearSearch(iNo) == true)
                    {
                        System.out.println("Element is Present");
                    }
                    else
                    {
                        System.out.println("There is no such element");
                    }

                    break;

                case 4:

                    System.out.print("Enter element to search : ");
                    iNo = sobj.nextInt();

                    if(sobjSearch.BiDirectionalSearch(iNo) == true)
                    {
                        System.out.println("Element is Present");
                    }
                    else
                    {
                        System.out.println("There is no such element");
                    }

                    break;

                case 5:

                    System.out.println("Thank you for using Searching Application");
                    System.exit(0);

                default:

                    System.out.println("Invalid Choice");
                    break;
            }
        }
    }
}

/*
===============================================================================
Sample Output

==============================================
       SEARCHING MENU DRIVEN APPLICATION
==============================================

1. Accept Elements
2. Display Elements
3. Linear Search
4. Bi-Directional Search
5. Exit

Enter your choice : 1

Enter the Elements :
10
20
30
40
50

Elements accepted successfully

Enter your choice : 2

Elements of the Array are :
10
20
30
40
50

Enter your choice : 3
Enter element to search : 30

Element is Present

Enter your choice : 4
Enter element to search : 40

Element is Present

Enter your choice : 5

Thank you for using Searching Application

===============================================================================
Time Complexity:

Accept()                  : O(n)
Display()                 : O(n)
LinearSearch()            : O(n)
BiDirectionalSearch()     : O(n)

Space Complexity          : O(n)

===============================================================================
End of Program
===============================================================================
*/
