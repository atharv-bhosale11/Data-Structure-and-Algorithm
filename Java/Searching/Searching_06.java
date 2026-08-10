/*
===============================================================================
Program Name    : Complete Searching Application
Program Number  : 006
File Name       : Searching_06.java

Description     : This program demonstrates complete
                  Searching operations on an array.

                  Operations:
                  1. Accept Elements
                  2. Display Elements
                  3. Linear Search
                  4. Bi-Directional Search

Concepts Used:
1. Class and Object
2. Dynamic Memory Allocation
3. Array Handling
4. Linear Search
5. Bi-Directional Search
6. Boolean Flag

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

class Searching_06
{
    public static void main(String A[])
    {
        Searching sobj = new Searching(5);

        sobj.Accept();
        sobj.Display();

        ///////////////////////////////////////////////////////////////////////
        // Linear Search
        ///////////////////////////////////////////////////////////////////////

        if(sobj.LinearSearch(30) == true)
        {
            System.out.println("\nLinear Search : Element is Present");
        }
        else
        {
            System.out.println("\nLinear Search : There is no such element");
        }

        ///////////////////////////////////////////////////////////////////////
        // Bi-Directional Search
        ///////////////////////////////////////////////////////////////////////

        if(sobj.BiDirectionalSearch(30) == true)
        {
            System.out.println("Bi-Directional Search : Element is Present");
        }
        else
        {
            System.out.println("Bi-Directional Search : There is no such element");
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

Linear Search : Element is Present

Bi-Directional Search : Element is Present

===============================================================================
Time Complexity:

LinearSearch()           : O(n)
BiDirectionalSearch()    : O(n)
Display()                : O(n)
Accept()                 : O(n)

Space Complexity         : O(n)

===============================================================================
End of Program
===============================================================================
*/
