/*
===============================================================================
Program Name    : Accept Elements for Searching
Program Number  : 002
File Name       : Searching_02.java

Description     : This program demonstrates accepting
                  elements from user and storing them
                  into an array.

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
}

class Searching_02
{
    public static void main(String A[])
    {
        Searching sobj = new Searching(5);

        sobj.Accept();

        System.out.println("Elements accepted successfully");
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

Elements accepted successfully

===============================================================================
End of Program
===============================================================================
*/
