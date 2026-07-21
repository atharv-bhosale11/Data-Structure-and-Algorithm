# Singly Circular Linked List in C

## Overview

This repository contains the implementation of a **Singly Circular Linked List** using the C programming language.

A Singly Circular Linked List is a linear data structure where each node contains data and a pointer to the next node. The last node points back to the first node, forming a circular structure.

The repository demonstrates the complete implementation of Singly Circular Linked List operations with well-structured and documented programs.

---

## Features

* Node Creation
* Dynamic Memory Allocation
* Insert First
* Insert Last
* Insert At Position
* Delete First
* Delete Last
* Delete At Position
* Display Linked List
* Count Total Nodes
* Menu Driven Implementation
* Position Validation
* Circular Node Linking

---

## Data Structure Used

```c
struct node
{
    int data;
    struct node *next;
};
```

---

## Operations Implemented

### Insert Operations

* InsertFirst()
* InsertLast()
* InsertAtPos()

### Delete Operations

* DeleteFirst()
* DeleteLast()
* DeleteAtPos()

### Utility Operations

* Display()
* Count()

---

## Concepts Covered

* Self Referential Structures
* Dynamic Memory Allocation
* Pointer Manipulation
* Circular Linked List Traversal
* Function Based Design
* Menu Driven Programming
* Data Structure Fundamentals

---

## Sample Output

```text
-------------------------------------
Singly Circular Linked List
-------------------------------------

1. Insert First
2. Insert Last
3. Insert At Position
4. Delete First
5. Delete Last
6. Delete At Position
7. Display
8. Count
0. Exit

Enter your choice :
```

---

## Learning Objectives

After completing these programs, you will understand:

* How circular linked lists work internally
* Memory allocation using malloc()
* Node insertion techniques
* Node deletion techniques
* Traversing circular structures
* Position based operations
* Building menu driven applications

---

## Repository Structure

```text
Singly-Circular-Linked-List-C/
│
├── Program001.c
├── Program002.c
├── Program003.c
├── ...
├── Program022.c
└── README.md
```

---

## Requirements

* GCC Compiler
* CodeBlocks / VS Code / Dev-C++
* Windows, Linux or macOS

---

## Compilation

```bash
gcc Program.c -o Program
```

## Execution

```bash
./Program
```

---

## Author

Atharv Tushar Bhosale

---

