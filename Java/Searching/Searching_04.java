/*
===============================================================================
Program Name    : Linear Search
Program Number  : 004
File Name       : Searching_04.java

Description     : This program demonstrates Linear Search
                  operation on an array.

                  Linear Search checks each element
                  sequentially until the required element
                  is found.

Concepts Used:
1. Class and Object
2. Dynamic Memory Allocation
3. Array Handling
4. Linear Search
5. Boolean Flag

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
}

class Searching_04
{
    public static void main(String A[])
    {
        Searching sobj = new Searching(5);

        sobj.Accept();
        sobj.Display();

        if(sobj.LinearSearch(30) == true)
        {
            System.out.println("\nElement is Present");
        }
        else
        {
            System.out.println("\nThere is no such element");
        }
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

Element is Present

===============================================================================
End of Program
===============================================================================
*/
