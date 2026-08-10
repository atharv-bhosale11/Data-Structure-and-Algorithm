/*
===============================================================================
Program Name    : Bi-Directional Search
Program Number  : 005
File Name       : Searching_05.java

Description     : This program demonstrates Bi-Directional
                  Search operation on an array.

                  The search starts simultaneously from
                  both ends of the array and moves towards
                  the center.

Concepts Used:
1. Class and Object
2. Dynamic Memory Allocation
3. Array Handling
4. Bi-Directional Search
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

class Searching_05
{
    public static void main(String A[])
    {
        Searching sobj = new Searching(5);

        sobj.Accept();
        sobj.Display();

        if(sobj.BiDirectionalSearch(30) == true)
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
