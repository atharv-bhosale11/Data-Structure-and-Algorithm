# Singly Circular Linked List in Java

## 📌 Overview

This repository contains a basic implementation of a **Singly Circular Linked List (SCLL)** in Java using Object-Oriented Programming concepts.

In a Singly Circular Linked List, the last node points back to the first node, forming a circular structure. This project demonstrates the fundamental operations performed on a circular linked list.

---

## 🚀 Operations Implemented

### Insertion

* InsertFirst()
* InsertLast()
* InsertAtPos()

### Deletion

* DeleteFirst()
* DeleteLast()
* DeleteAtPos()

### Other Operations

* Display()
* Count()

---

## 📂 Node Structure

```java
class Node
{
    public int data;
    public Node next;

    public Node(int no)
    {
        data = no;
        next = null;
    }
}
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

* Java
* Object-Oriented Programming (OOP)
* Dynamic Memory Allocation

---

## ▶️ Sample Output

```text
Elements of Linked List:

|11| -> |21| -> |51| -> (Back to First)

Total Nodes : 3
```

---

## 📚 Concepts Covered

* Classes and Objects
* Constructors
* Circular Linked List
* Insertion Operations
* Deletion Operations
* Traversal
* Node Counting

---

## 👨‍💻 Author

Atharv Bhosale

