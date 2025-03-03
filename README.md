# SET Implementation 📂🔢

## 📌 Project Overview
This project is a **C-based implementation of a SET data structure** as part of the Data Structures course. The implementation includes **general SET operations** as well as a **Binary Search Tree (BST)-based specialized implementation**.

The project features efficient insertion, traversal, merging, and finding the k-th smallest element within a SET.

## 🚀 Features
- Implementation of **Abstract Data Type (ADT) SET**.
- Support for both **general and BST-specific implementations**.
- Efficient **traversal, merging, and k-th smallest element search**.
- **Optimized insertion and sorting** using `merge_sort`.
- **Memory leak detection using Valgrind**.
- **Unit testing with Acutest framework**.

## 🛠️ Technologies Used
- **Language:** C
- **Data Structures:** Binary Search Tree (BST), Vectors
- **Memory Management:** Dynamic allocation for efficient data handling
- **Debugging:** Valgrind for memory leak detection
- **Testing:** Acutest framework for unit testing

## 📂 File Structure
```
/SET-Implementation
 ├── include
 │   ├── ADTSet.h                 # Header file for SET ADT
 │   ├── ADTVector.h               # Header file for vectors
 │   ├── set_utils.h               # Utility functions for SET
 │   ├── common_types.h            # Common data types
 │   ├── valgrind.h                # Memory debugging support
 │   ├── acutest.h                 # Unit testing framework
 │
 ├── modules
 │   ├── UsingADTSet/              # General SET implementation
 │   ├── UsingBinarySearchTree/    # BST-based implementation
 │   ├── UsingBTree/               # Alternative tree structure implementation
 │   ├── UsingDynamicArray/        # Vector-based SET implementation
 │
 ├── tests
 │   ├── set_utils_test.c          # General SET test file
 │   ├── Makefile                  # Test Makefile
 │   ├── set_utils_test.d          # For Valgrind test
 │
 ├── Makefile                      # Compilation setup
 ├── README.md                     # Project documentation
```

## 🏃‍♂️ How to Compile & Run
### **1. Compilation**
To compile the project, use the following command:
```sh
make
```

### **2. Running Tests**
To run the test cases for both implementations:
```sh
make run
```

### **3. Running with Valgrind**
To check for memory leaks:
```sh
make valgrind
```

## 🏗️ Comparison of the Two Implementations

### **1️⃣ General SET Implementation (Using ADTSet)

Uses a generic approach, allowing flexibility with different underlying data structures.

Works well with dynamic arrays, linked lists, or other tree-based structures.

Designed to be modular and extensible, making it adaptable for various use cases.

Operations are implemented using function pointers to allow interchangeable data structures.

-   Time Complexity:

    -   set_from_vector: O(n log n) (depends on set_insert, assumed O(log n)).

    -   set_to_vector: O(n log n) (vector_insert_last is O(1), set_next is O(log n)).

    -   set_traverse: O(n log n) (Iterates over the set once, set_next is O(log n)).

    -   set_merge: O(n log n) (set_next and set_insert are O(log n), iterated n times).

    -   set_find_k_smallest: O(n) (worst case k = n).

### **2️⃣ BST-Based Implementation (UsingBinarySearchTree)

Uses a Binary Search Tree (BST) as the core structure for SET operations.

Optimized for fast ordered retrieval of elements.

Provides logarithmic time complexity for insertions and lookups (O(log n)).

Supports efficient k-th smallest element retrieval.

BST operations ensure that elements remain sorted.

-   Time Complexity:

    -   Insertion & Lookup: O(log n) due to the nature of BSTs.

    -   Traversal: O(n log n) as elements are iterated in sorted order.

    -   Merge: O(n log n) as BST properties must be maintained.

    -   Finding k-th smallest element: O(n) (involves traversing the tree structure).

## 🎯 Future Improvements
- Implement **alternative tree-based structures** for SET.
- Improve **sorting efficiency** for larger datasets.
- Explore **self-balancing trees** for optimized performance.

## 📜 License
This project is licensed under the **MIT License**.

## 👤 Author
**Giorgos Theodorou**

