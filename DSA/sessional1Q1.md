# Preferred Data Structure: Sparse Matrix
## Why Sparse Matrix?

- Efficiency: Since most intersections have zero traffic, a sparse matrix efficiently stores only the non-zero values, saving memory.
- Speed: Sparse matrices allow for faster computations and updates, as operations are performed only on non-zero elements.
- Scalability: They can handle large matrices with minimal memory usage, making them ideal for real-time traffic data.

## Advantages:
- Memory Efficient: Only non-zero elements are stored, reducing memory usage.
- Faster Computations: Operations are performed only on non-zero elements, speeding up calculations.
- Scalability: Can handle large datasets efficiently.

## Disadvantages:
- Complexity: Implementing and managing sparse matrices can be more complex than dense matrices.
- Overhead: Additional data structures (like linked lists or dictionaries) are needed to store the non-zero elements and their positions.
# Handling Updates in Sparse Matrix
## Updating Traffic Density:

- From Zero to Non-Zero: Add the new non-zero value to the sparse matrix data structure.
- From Non-Zero to Zero: Remove the element from the sparse matrix data structure.