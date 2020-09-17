## Advantages/Disadvantages Over Singly Linked List

Let us discuss some of the advantages and disadvantages of doubly linked list over the singly linked list.

### Advantages:

- The doubly linked list can be traversed in forward as well as backward directions, unlike singly linked list which can be traversed in the forward direction only.
- Delete operation in a doubly-linked list is more efficient when compared to singly list when a given node is given. In a singly linked list, as we need a previous node to delete the given node, sometimes we need to traverse the list to find the previous node. This hits the performance.
- Insertion operation can be done easily in a doubly linked list when compared to the singly linked list.
  Disadvantages:

- As the doubly linked list contains one more extra pointer i.e. previous, the memory space taken up by the doubly linked list is larger when compared to the singly linked list.
- Since two pointers are present i.e. previous and next, all the operations performed on the doubly linked list have to take care of these pointers and maintain them thereby resulting in a performance bottleneck.

### Applications Of Doubly Linked List

A doubly linked list can be applied in various real-life scenarios and applications as discussed below.

- A Deck of cards in a game is a classic example of a doubly linked list. Given that each card in a deck has the previous card and next card arranged sequentially, this deck of cards can be easily represented using a doubly linked list.
- Browser history/cache – The browser cache has a collection of URLs and can be navigated using the forward and back buttons is another good example that can be represented as a doubly linked list.
- Most recently used (MRU) also can be represented as a doubly linked list.
- Other data structures like Stacks, hash table, the binary tree can also be constructed or programmed using a doubly linked list.

### Conclusion

- A doubly linked list is a variation of the singly linked list. It differs from the singly linked list in that where each node contains an extra pointer to the previous node along with the next pointer.

- This presence of an extra pointer facilitates insert, delete operations on the doubly linked list but at the same time requires extra memory to store these extra pointers.

- As discussed already, the doubly linked list has various uses in real-time scenarios like browser cache, MRUs, etc. We can also represent other data structures like trees, hash tables, etc. using a doubly-linked list.
