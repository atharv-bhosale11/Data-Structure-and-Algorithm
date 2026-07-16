# Doubly Linked List in C

## 📌 Overview

This repository contains implementations of **Doubly Linked List** data structure in the C programming language.

A Doubly Linked List is a linear data structure where each node contains:

* Data
* Pointer to the Next Node
* Pointer to the Previous Node

This allows traversal in both forward and backward directions, making insertion and deletion operations more flexible compared to a Singly Linked List.

---

## 🎯 Objectives

* Understand the structure of a Doubly Linked List
* Learn dynamic memory allocation using `malloc()`
* Practice pointer manipulation
* Implement insertion and deletion operations
* Perform forward and backward traversal
* Build a strong foundation in Data Structures

---

## 📂 Programs Included

### Basic Programs

* Node Structure Creation
* Structure Packing using `#pragma pack(1)`
* Dynamic Memory Allocation
* Node Linking Demonstration
* Forward Traversal
* Backward Traversal

### Insertion Operations

* Insert First
* Insert Last
* Insert At Position

### Deletion Operations

* Delete First
* Delete Last
* Delete At Position

### Utility Operations

* Display Forward
* Display Reverse
* Count Nodes
* Search Element
* Frequency Count
* First Occurrence
* Last Occurrence

---

## 🛠 Technologies Used

* Language: C
* Compiler: GCC / Clang / Turbo C
* Platform: Windows / Linux

---

## 📖 Concepts Covered

* Structures
* Self-Referential Structures
* Dynamic Memory Allocation
* Pointers
* Double Pointers
* Memory Management
* Data Structures
* Linked List Operations
* Traversal Techniques

---

## 🧠 Data Structure Representation

```text
NULL <- |11| <=> |21| <=> |51| <=> |101| -> NULL
```

Each node contains:

```c
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
```

---

## 🚀 Learning Outcomes

After completing these programs, you will be able to:

* Create and manage doubly linked lists
* Perform insertion and deletion efficiently
* Traverse lists in both directions
* Understand memory allocation and deallocation
* Develop advanced linked list applications

---

## 📚 Repository Purpose

This repository is part of my Data Structures learning journey and contains step-by-step implementations of Doubly Linked List concepts in C with proper documentation, comments, and examples.

---

## 👨‍💻 Author

**Atharv Tushar Bhosale**


