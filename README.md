# AVL Trees README

## Introduction

Welcome to the README for AVL trees! AVL trees are a type of self-balancing binary search tree (BST) that maintains its height balance to ensure efficient search, insert, and delete operations. This README provides an overview of AVL trees and includes information about the provided programs.

## AVL Trees Overview

AVL trees are binary search trees that automatically adjust their shape to maintain a balance factor, ensuring that the tree remains relatively balanced. This balance is achieved by performing rotations on nodes during insertion and deletion operations. AVL trees guarantee a worst-case time complexity of O(log N) for search, insert, and delete operations, making them efficient for many applications.

### Key Concepts

- **Balance Factor:** The height difference between the left and right subtrees of a node.
- **Rotations:** Single and double rotations are performed to balance the AVL tree.
- **Insertion:** Nodes are inserted recursively, and rotations are performed if the balance factor becomes greater than 1 or less than -1.
- **Deletion:** Nodes are deleted recursively, and rotations are performed if necessary to maintain balance.

## Provided Programs

### lab4_1_avl.c

This program implements basic operations for AVL trees, including insertion, rotation, balance factor calculation, and rebalancing.

### lab4_2_avl.c

Building upon lab4_1_avl.c, this program further explores AVL tree operations, including additional rotation methods and rebalancing techniques.

### lab4_3_bst.c

Although named as a BST program, lab4_3_bst.c is intended to demonstrate the implementation of an AVL tree using BST principles. It includes functions for AVL tree insertion, rotation, rebalancing, and deletion.

### lab4_3_bst.h

This header file contains function declarations and typedefs for the lab4_3_bst.c program.

### lab4_3_main.c

A main program file that demonstrates the usage of AVL tree functions defined in lab4_3_bst.c.

## Contributors

- Hannah Vibien



