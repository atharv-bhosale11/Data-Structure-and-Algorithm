# Singly Circular Linked List in C++

## 📌 Overview

This repository contains the implementation of a **Singly Circular Linked List (SCLL)** using C++.

A Singly Circular Linked List is a linked data structure in which the last node points back to the first node, forming a circular chain. Unlike a traditional singly linked list, there is no `NULL` at the end of the list.

This project demonstrates various operations on a Singly Circular Linked List using Object-Oriented Programming (OOP) concepts in C++.

---

## 🚀 Features

### Insertion Operations

* Insert First
* Insert Last
* Insert At Position

### Deletion Operations

* Delete First
* Delete Last
* Delete At Position

### Display & Count

* Display Elements
* Count Total Nodes

### Searching Operations

* Search First Occurrence
* Search Last Occurrence
* Frequency of Element

### Utility Operations

* Summation of Elements
* Find Maximum Element
* Find Minimum Element
* Count Even Numbers
* Count Odd Numbers

---

## 📂 Node Structure

```cpp
struct node
{
    int data;
    struct node* next;
};
```

---

## 🔄 Circular Linked List Representation

```text
+------+     +------+     +------+
| 11 | o---->| 21 | o---->| 51 |
+------+     +------+     +------+
     ^                         |
     |_________________________|
```

The last node points back to the first node, making the list circular.

---

## 🛠️ Technologies Used

* Language: C++
* Concepts: OOP, Classes, Dynamic Memory Allocation
* Compiler: GCC / G++
* IDE: VS Code, Code::Blocks, Dev-C++, Visual Studio

---

## 📖 Concepts Covered

* Classes and Objects
* Constructors and Destructors
* Dynamic Memory Management
* Pointer Manipulation
* Circular Linked List Traversal
* Insertion and Deletion Algorithms
* Searching Techniques

---

## ▶️ Sample Output

```text
Insert First : 51
Insert First : 21
Insert First : 11

Elements of Linked List:
|11| -> |21| -> |51| -> (Back to First)

Total Nodes : 3

Summation : 83
Maximum : 51
Minimum : 11
```

---

## 📚 Operations Implemented

* Create List
* InsertFirst()
* InsertLast()
* InsertAtPos()
* DeleteFirst()
* DeleteLast()
* DeleteAtPos()
* Display()
* Count()
* SearchFirstOcc()
* SearchLastOcc()
* Frequency()
* Summation()
* Maximum()
* Minimum()
* CountEven()
* CountOdd()

---

## 🎯 Learning Outcomes

By working through this repository, you will gain hands-on experience with:

* Circular Linked Lists
* Dynamic Data Structures
* Memory Management
* Object-Oriented Programming in C++
* Problem Solving Using Linked Lists

---

## 👨‍💻 Author

**Atharv Bhosale**


