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

## 📊 Time Complexity Analysis
### **Exercise 1**
- **set_from_vector:** `O(n log n)` (depends on `set_insert`, assumed `O(log n)`).
- **set_to_vector:** `O(n log n)` (`vector_insert_last` is `O(1)`, `set_next` is `O(log n)`).

### **Exercise 2**
- **set_traverse:** `O(n log n)` (Iterates over the set once, `set_next` is `O(log n)`).
- **set_merge:** `O(n log n)` (`set_next` and `set_insert` are `O(log n)`, iterated `n` times).
- **set_find_k_smallest:** `O(n)` (worst case `k = n`).

### **Exercise 4**
- Two vectors are created: one **sorted**, one **unsorted**.
- Elements are split, inserting sorted values into the sorted vector.
- The unsorted vector is **sorted using `merge_sort`** (`O(n log n)`).
- The two vectors are merged into one **fully sorted vector**.
- The **BST-SET is created** from this sorted vector.

### **Exercise 5**
- To implement `set_find_k_smallest`, modifications were made to `struct set_node` in `ADTSet.c`, adding:
  - `int sub_size` (size of the subtree rooted at `node`).
- New helper functions:
  - `static int node_size`
  - `static void node_inc_size`
  - `static void node_dec_size`
- The following functions were modified to maintain correctness:
  - `static SetNode node_insert`
  - `static SetNode node_remove_min`
  - `static SetNode node_remove`

## 🎯 Future Improvements
- Implement **alternative tree-based structures** for SET.
- Improve **sorting efficiency** for larger datasets.
- Explore **self-balancing trees** for optimized performance.

## 📜 License
This project is licensed under the **MIT License**.

## 👤 Author
**Giorgos Theodorou**

