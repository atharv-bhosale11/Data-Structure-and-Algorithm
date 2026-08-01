# Doubly Circular Linked List in C++

## Overview

This repository contains the implementation of a **Doubly Circular Linked List (DCLL)** using **C++**. A Doubly Circular Linked List is a linear data structure in which each node contains data along with two links:

- A pointer to the next node.
- A pointer to the previous node.

Unlike a normal Doubly Linked List, the last node points back to the first node and the first node points back to the last node, creating a circular connection in both directions.

This project is designed to help students understand the fundamentals of linked lists, dynamic memory allocation, pointer manipulation, and object-oriented programming concepts in C++.

---

## Objectives

- Understand the structure of a Doubly Circular Linked List.
- Learn how nodes are connected in both forward and backward directions.
- Perform insertion and deletion operations efficiently.
- Understand position-based operations.
- Practice Data Structures using C++.

---

## Data Structure Representation

```text
        +-------------------------------+
        |                               |
        v                               |
+------+ <=> +------+ <=> +------+ <=> +------+
| 11   |     | 21   |     | 51   |     | 101  |
+------+ <=> +------+ <=> +------+ <=> +------+
        ^                               |
        |                               |
        +-------------------------------+
```

---

## Features Implemented

### 1. InsertFirst()

Adds a new node at the beginning of the list.

### 2. InsertLast()

Adds a new node at the end of the list.

### 3. DeleteFirst()

Removes the first node from the list.

### 4. DeleteLast()

Removes the last node from the list.

### 5. InsertAtPos()

Inserts a new node at a specified position.

### 6. DeleteAtPos()

Deletes a node from a specified position.

### 7. Display()

Displays all elements present in the Doubly Circular Linked List.

### 8. Count()

Returns the total number of nodes present in the list.

---

## Concepts Used

- Classes and Objects
- Dynamic Memory Allocation
- Self-Referential Class
- Circular Linked List
- Doubly Linked List
- Traversal Techniques
- Pointer Manipulation
- Position-Based Operations
- Object-Oriented Programming

---

## Operations Demonstrated

### InsertFirst()

```text
Before:
21 <=> 51

After:
11 <=> 21 <=> 51
```

### InsertLast()

```text
Before:
11 <=> 21

After:
11 <=> 21 <=> 51
```

### DeleteFirst()

```text
Before:
11 <=> 21 <=> 51

After:
21 <=> 51
```

### DeleteLast()

```text
Before:
11 <=> 21 <=> 51

After:
11 <=> 21
```

### InsertAtPos()

```text
Before:
11 <=> 51

InsertAtPos(21, 2)

After:
11 <=> 21 <=> 51
```

### DeleteAtPos()

```text
Before:
11 <=> 21 <=> 51

DeleteAtPos(2)

After:
11 <=> 51
```

---

## Time Complexity Analysis

| Operation | Time Complexity |
|------------|----------------|
| InsertFirst() | O(1) |
| InsertLast() | O(1) |
| DeleteFirst() | O(1) |
| DeleteLast() | O(1) |
| Display() | O(n) |
| Count() | O(n) |
| InsertAtPos() | O(n) |
| DeleteAtPos() | O(n) |

Where:

- **n** = Number of nodes in the list.

---

## Sample Output

```text
Elements of Doubly Circular Linked List:

|11| <=> |21| <=> |51| <=> |101|

Number of Nodes : 4

After DeleteFirst():

|21| <=> |51| <=> |101|

After DeleteLast():

|21| <=> |51|
```

---

## Applications

Doubly Circular Linked Lists are commonly used in:

- Music Playlist Applications
- Browser Navigation Systems
- Undo and Redo Operations
- Round Robin CPU Scheduling
- Multiplayer Turn-Based Games
- Circular Buffers
- Task Scheduling Systems

---

## Learning Outcomes

After completing this project, you will be able to:

- Understand the working of Doubly Circular Linked Lists.
- Implement insertion and deletion operations.
- Handle circular connections between nodes.
- Perform position-based manipulations.
- Apply Object-Oriented Programming concepts in Data Structures.
- Improve problem-solving skills using pointers and dynamic memory.

---

## Repository Structure

```text
DoublyCircularLinkedList/
│
├── DoublyCL01.cpp   -> InsertFirst()
├── DoublyCL02.cpp   -> InsertLast()
├── DoublyCL03.cpp   -> Display()
├── DoublyCL04.cpp   -> Count()
├── DoublyCL05.cpp   -> DeleteFirst()
├── DoublyCL06.cpp   -> DeleteLast()
├── DoublyCL07.cpp   -> InsertAtPos()
├── DoublyCL08.cpp   -> DeleteAtPos()
└── DoublyCL09.cpp   -> Menu Driven Application
```

---

## Author

**Atharv Tushar Bhosale**

Passionate about Data Structures, Algorithms, System Programming, and Software Development.

GitHub: https://github.com/atharv-bhosale11
