# Doubly Circular Linked List in C

## Overview

This repository contains the implementation of a **Doubly Circular Linked List (DCLL)** using the C programming language.

A Doubly Circular Linked List is a linear data structure in which:

* Each node contains **data**, a **next pointer**, and a **previous pointer**.
* The **last node points to the first node**.
* The **first node's previous pointer points to the last node**.
* Traversal can be performed in both forward and backward directions.

This repository is designed for learning and understanding the fundamentals of Doubly Circular Linked Lists and their operations.

---

## Features

### Basic Operations

* InsertFirst()
* InsertLast()
* InsertAtPos()

### Deletion Operations

* DeleteFirst()
* DeleteLast()
* DeleteAtPos()

### Utility Operations

* Display()
* Count()

---

## Concepts Covered

* Dynamic Memory Allocation
* Self-Referential Structures
* Pointer Manipulation
* Forward Traversal
* Backward Traversal
* Circular Linking
* Position-Based Insertion
* Position-Based Deletion
* Memory Management using malloc() and free()

---

## Node Structure

```c
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
```

---

## Operations Flow

### Insertion

* Insert node at beginning
* Insert node at end
* Insert node at specified position

### Deletion

* Delete first node
* Delete last node
* Delete node from specified position

### Traversal

* Display all nodes
* Count total number of nodes

---

## Sample Output

```text
<=> |11| <=> |21| <=> |51| <=> |101| <=> |111| <=>

Number of Nodes : 5

After InsertAtPos(105,4)

<=> |11| <=> |21| <=> |51| <=> |105| <=> |101| <=> |111| <=>

After DeleteAtPos(4)

<=> |11| <=> |21| <=> |51| <=> |101| <=> |111| <=>
```

---

## Learning Objectives

By studying these programs, you will understand:

* How doubly linked nodes are connected
* How circular linking works
* How insertion and deletion are performed efficiently
* How forward and backward navigation is achieved
* How memory is allocated and released dynamically

---

## Requirements

* C Compiler (GCC recommended)
* Code::Blocks / VS Code / Dev-C++
* Windows, Linux, or macOS

---

## Compile and Run

```bash
gcc program.c -o program
./program
```

---

## Repository Contents

* Node Structure Creation
* Display Function
* Count Function
* InsertFirst
* InsertLast
* InsertAtPos
* DeleteFirst
* DeleteLast
* DeleteAtPos
* Menu Driven Programs

---

## Author

**Atharv Tushar Bhosale**

