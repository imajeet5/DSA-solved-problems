HashMap other name is hashTable, there is very little difference between the two are they are used interchangeably.

## HashMap

- There are two type of maps in STL:
  1. Ordered Map
  2. Unordered Map

### Ordered Map

- Ordered Map in STL are implemented using balanced BST, so all the operation like insert, delete, search will take O(logN) time. We can iterate this map in sorted manner because this is sorted. Map will sort on the basis of keys not on values

### Unordered Map

- Unordered Map are implemented using Hash Tables, in this all the function will take O(1) time.
- Unordered map stored the key-value in form of Pair.

### Maps vs Sets

- Map stores key value pair but Set will store only keys, it will not store values, rest everything is same.

## Hash Map Implementation

### Collision handling techniques

There are three collision handling techniques

1. Close Addressing or Separate Chaining
2. Open Addressing
3. Separate hashing
