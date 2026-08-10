/*
===============================================================================
Program Name    : Searching Display Operation
Program Number  : 003
File Name       : Searching_03.java

Description     : This program demonstrates accepting
                  and displaying elements of an array
                  used for Searching operations.

Concepts Used:
1. Class and Object
2. Dynamic Memory Allocation
3. Array Handling
4. User Input

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

        System.out.println("Enter the Elements : ");

        for(i = 0; i < iSize; i++)
        {
            Arr[i] = sobj.nextInt();
        }
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
}

class Searching_03
{
    public static void main(String A[])
    {
        Searching sobj = new Searching(5);

        sobj.Accept();
        sobj.Display();
    }
}

/*
===============================================================================
Sample Output

Enter the Elements :

10
20
30
40
50

Elements of the Array are :

10
20
30
40
50

===============================================================================
End of Program
===============================================================================
*/
