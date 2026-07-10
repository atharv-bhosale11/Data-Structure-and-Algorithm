# Singly Linked List in C

## Overview

This repository contains the implementation of a Singly Linked List using the C programming language. It covers the fundamental concepts of node creation, memory allocation, pointer manipulation, traversal, insertion, deletion, searching, and counting operations. The repository is designed to provide a step-by-step understanding of how a singly linked list works internally.

## What is a Singly Linked List?

A Singly Linked List is a dynamic linear data structure composed of nodes. Each node contains:

1. **Data** – Stores the actual value.
2. **Next Pointer** – Stores the address of the next node.

The last node of the list contains `NULL` in its next pointer, indicating the end of the linked list.

## Node Structure

```c
struct node
{
    int data;
    struct node *next;
};
```

## Topics Covered

### Basic Concepts

1. Node Structure
2. Memory Layout and Structure Padding
3. Structure Packing using `#pragma pack(1)`
4. Node Initialization
5. Node Linking
6. Pointer Traversal
7. Dynamic Memory Allocation using `malloc()`

### Insertion Operations

1. Insert First
2. Insert Last
3. Insert At Position

### Deletion Operations

1. Delete First
2. Delete Last
3. Delete At Position

### Utility Operations

1. Display Linked List
2. Count Nodes
3. Search Element

## Concepts Used

* Structures
* Self-Referential Structures
* Pointers
* Dynamic Memory Allocation
* Memory Management
* Pointer Traversal
* Linked Data Organization

## Applications

* Dynamic Memory Management
* Implementation of Stacks
* Implementation of Queues
* Graph Representation
* Hash Tables
* Polynomial Manipulation

## Technologies Used

* C Programming Language
* GCC Compiler
* Visual Studio Code
* Git & GitHub

## Learning Objectives

1. Understand the internal working of a singly linked list.
2. Master pointer-based programming concepts.
3. Learn dynamic memory allocation techniques.
4. Improve problem-solving and logical thinking skills.
5. Build a strong foundation for advanced Data Structures and Algorithms.

## Repository Features

* Well-Documented Programs
* Numbered Learning Approach
* Detailed Program Headers and Explanations
* Beginner-Friendly Code
* Step-by-Step Progression from Basics to Operations

## Author

Atharv Tushar Bhosale
