# Steps to Solve the Problem
1. **Trim the Strings**: Create arrays for each trim length.
1. **Sort Each Trimmed Array**: Use a non-comparison based sorting algorithm (Radix Sort).

3. **Find the k-th Smallest Element**: Return the k-th smallest element for each trimmed array.

## Pseudocode
1. **Trim Strings**:
For each length from 1 to the maximum length of the strings, trim the strings from the LSB position and store them in separate arrays.
2. **Radix Sort**:
Use Radix Sort to sort each trimmed array.

3. **Find k-th Smallest Element**:
Return the k-th smallest element from each sorted trimmed array.