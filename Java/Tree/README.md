# 🌳 Tree Data Structure in Java

## 📌 Overview

This repository contains implementations and practice programs related to the **Tree Data Structure in Java**.

A Tree is a **non-linear data structure** in which elements are organized in a hierarchical manner. Each element is represented as a node, and nodes are connected through parent-child relationships.

This repository focuses mainly on **Binary Trees** and **Binary Search Trees (BST)**, along with important tree operations and traversal techniques.

---

## 📚 Topics Covered

### 1. Tree Basics

* Tree Data Structure
* Root Node
* Parent Node
* Child Node
* Leaf Node
* Internal / Parent Node
* Subtree
* Height of Tree
* Depth of Node
* Binary Tree
* Binary Search Tree

---

### 2. Binary Search Tree

Binary Search Tree follows the following rule:

* Elements smaller than the current node are stored in the **left subtree**.
* Elements greater than the current node are stored in the **right subtree**.
* Duplicate elements can be handled according to the implementation.

Example:

```text
              11
            /    \
           5      17
          / \    /  \
         4   7  15  21
```

---

## 🔧 Operations Covered

### 1. Insert Node

Insert a new node into the Binary Search Tree according to the BST property.

```java
Insert(11);
Insert(5);
Insert(17);
```

---

### 2. Search Node

Search for a particular element in the Binary Search Tree.

The search uses the BST property to decide whether to move towards the left or right subtree.

---

### 3. Inorder Traversal

Traversal order:

```text
Left → Data → Right
```

For the tree:

```text
              11
            /    \
           5      17
          / \    /  \
         4   7  15  21
```

Output:

```text
4
5
7
11
15
17
21
```

**Important:** Inorder traversal of a Binary Search Tree produces elements in **ascending order**.

---

### 4. Preorder Traversal

Traversal order:

```text
Data → Left → Right
```

Output:

```text
11
5
4
7
17
15
21
```

---

### 5. Postorder Traversal

Traversal order:

```text
Left → Right → Data
```

Output:

```text
4
7
5
15
21
17
11
```

---

### 6. Count Total Nodes

Counts the total number of nodes present in the tree.

Example:

```text
Total Nodes = 7
```

---

### 7. Count Leaf Nodes

A leaf node is a node that does not have any child.

For the above tree:

```text
Leaf Nodes:
4
7
15
21
```

Therefore:

```text
Leaf Nodes = 4
```

---

### 8. Count Parent Nodes

A parent node is a node having at least one child.

For the above tree:

```text
Parent Nodes:
11
5
17
```

Therefore:

```text
Parent Nodes = 3
```

---

## 🔄 Tree Traversals

| Traversal | Order               |
| --------- | ------------------- |
| Inorder   | Left → Data → Right |
| Preorder  | Data → Left → Right |
| Postorder | Left → Right → Data |

---

## 🧠 Concepts Used

The programs in this repository demonstrate:

1. Class and Object
2. Self-Referential Node
3. Dynamic Memory Allocation
4. Binary Tree
5. Binary Search Tree
6. Recursion
7. Iteration
8. Tree Traversals
9. Searching
10. Insertion
11. Counting Nodes
12. Menu Driven Programming

---

## 📂 Program Sequence

The Tree programs are developed gradually from basic implementation to a complete menu-driven application.

```text
01 - Tree Skeleton
02 - Insert Node
03 - Inorder Traversal
04 - Preorder Traversal
05 - Postorder Traversal
06 - Search Node
07 - Count Total Nodes
08 - Count Leaf Nodes
09 - Count Parent Nodes
10 - Complete Binary Search Tree Program
11 - Menu Driven Binary Search Tree Application
```

---

## 🌳 Example Binary Search Tree

After inserting:

```text
11
5
17
4
7
15
21
```

The tree becomes:

```text
              11
            /    \
           5      17
          / \    /  \
         4   7  15  21
```

### Inorder

```text
4 5 7 11 15 17 21
```

### Preorder

```text
11 5 4 7 17 15 21
```

### Postorder

```text
4 7 5 15 21 17 11
```

---

## ⏱️ Time Complexity

For a reasonably balanced Binary Search Tree:

| Operation          | Average Case |
| ------------------ | -----------: |
| Insert             |     O(log n) |
| Search             |     O(log n) |
| Inorder            |         O(n) |
| Preorder           |         O(n) |
| Postorder          |         O(n) |
| Count Nodes        |         O(n) |
| Count Leaf Nodes   |         O(n) |
| Count Parent Nodes |         O(n) |

In the worst case, when the BST becomes skewed:

```text
Insert  → O(n)
Search  → O(n)
```

### Space Complexity

Tree operations that use recursion require:

```text
O(h)
```

where `h` is the height of the tree.

---

## 🛠️ Technologies Used

* **Language:** Java
* **Concept:** Data Structures
* **Data Structure:** Tree / Binary Search Tree
* **IDE:** Any Java-supported IDE
* **Compiler:** Java JDK

---

## 🎯 Learning Objectives

By completing these programs, you will understand:

* How a tree is represented using nodes.
* How a Binary Search Tree is constructed.
* How insertion works in a BST.
* How searching works in a BST.
* How recursion is used for tree traversal.
* Difference between Inorder, Preorder and Postorder traversal.
* How to count total, leaf and parent nodes.
* How to build a complete menu-driven BST application in Java.

---

## 👨‍💻 Author

**Atharv Tushar Bhosale**


The programs are designed to strengthen understanding of **Trees, Binary Search Trees, Recursion, Traversals, Searching and Dynamic Node-based Data Structures**.
