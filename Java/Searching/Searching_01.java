/*
===============================================================================
Program Name    : Searching Skeleton
Program Number  : 001
File Name       : Searching_01.java

Description     : This program demonstrates the basic
                  structure of Searching Application.

Concepts Used:
1. Class and Object
2. Dynamic Memory Allocation
3. Array Handling

Date            : August 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================
*/

class Searching
{
    private int Arr[];
    private int iSize;

    public Searching(int iNo)
    {
        iSize = iNo;
        Arr = new int[iSize];
    }
}

class Searching_01
{
    public static void main(String A[])
    {
        Searching sobj = new Searching(5);

        System.out.println("Searching object created successfully");
    }
}

/*
===============================================================================
Sample Output

Searching object created successfully

===============================================================================
End of Program
===============================================================================
*/
