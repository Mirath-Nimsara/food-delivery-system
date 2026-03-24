# food-delivery-system
IN1111_Coding Assignment

# Food Delivery Management System 🍔🚀

A modular, console-based C application designed to streamline restaurant operations, from menu management to fair rider assignment. This project was developed as part of the **IN1111 - Data Structures and Algorithms 1** course at the **University of Moratuwa**.

## 📌 Project Overview
The system simulates a real-world food delivery lifecycle. It ensures that orders are processed fairly (FIFO), mistakes can be undone (LIFO), and riders are assigned work in a balanced rotation (Round-Robin).

## 🛠️ Data Structures & Algorithms Applied
This project demonstrates the practical application of 7 different data structures:

| Feature | Data Structure | Algorithm / Logic |
| :--- | :--- | :--- |
| **Menu Management** | Static Array | Bubble, Selection, & Insertion Sort |
| **Order Placement** | Singly Linked List | Dynamic Memory Allocation (`malloc`) |
| **Order Search** | Singly Linked List | **Recursive** Search |
| **Kitchen Queue** | Linear Queue | FIFO (First-In-First-Out) |
| **Undo System** | Stack | LIFO (Last-In-First-Out) |
| **Rider Assignment** | Circular Linked List | Round-Robin Rotation |
| **Order History** | Doubly Linked List | Bi-directional Traversal |



## 🚀 Features
- **Smart Menu:** Sort food items by ID, Price, or Popularity.
- **Fair Kitchen:** Orders are sent to the kitchen and processed in the exact order they were placed.
- **Safety Net:** Accidentally cancelled an order? Use the **UNDO** function to restore it instantly.
- **Rider Balance:** Uses a circular logic to ensure no single rider is overworked.
- **Audit Logs:** View completed orders chronologically or in reverse.

