### Arrays

- Size is fixed and cannot be extended
- access element is array a[i] -> O(1)
- We can move both in backward and forward direction. We can iterate array from starting to end or end to starting
- Insert/Delete element at i-th position, we have to shift the elements and make space for the new element
- Insertion element at 0th index, data is lost due to shifting of the elements

### Linked List

- We can add as many element as we want
- To access the i-th element we have to iterate over the linked list to reach the the i-th position, then we will return the data. Time complexity is not constant
- In linked list (singly) we can only move in the forward direction.
- In linked list there is no problem of shifting. Shifting is not required in linked list for insertion and delete.
- There is no data lost in insertion of element at the starting position.
