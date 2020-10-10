## Priority Queue

- On the basis of the priority factor assign to the elements we are ordering them.
- In priority Queue we extract elements in some specific order, every element has some importance factor/priority factor attach to them and on the basis of priority factor, we can sort out element.
- Priority Queue like normal queues, we will insert element at the end, but if we want to access the elements, elements will come out on the basis of priority.

### Type of Priority Queue

Priority Queues can be of two types:

1. Min Priority Queue
2. Max Priority Queue

#### Min Priority Queue

In min priority queue the element having the least priority will come first.

#### Max Priority Queue

In max priority queue the element having the highest priority will come first.

### Function needed:

1. Insert
2. get Max/get Min
3. remove Max/remove Min

### Implementation

Balanced BST is best for implementing priority queue, as it gives the time complexity of `NlogN`, while other give the time complexity of `N2`. But BST has some issues, which are:

1. Balancing factor: We have to write out code in such a way that tree is always balanced
2. Storing is very complicated

So instead of using BST for implementing priority queue we have designed a new data structure called **heap**. We will use heap for implementing priority queue.

## Heap

1. Heap is a complete Binary tree or CBT.
2. It has heap order property.

### Complete Binary Tree

1. All levels are completely filled except the last level.
2. We have to fill the levels from left to right.

- Maximum number of nodes in a CBT of height h is `(2^h) - 1` and the minimum number of nodes in a CBT of height h is `(2^(h-1))`.
- So, in CBT height is always equals to `logN`
- Every complete binary tree is balanced but not the other way around.
- Since height is always `logN` so no balancing is required.
- The easy and the best way to store the CBT is using an array.

### Types of Heaps

Heaps are also of two types:

1. Min heap: `root < left` and `root < right`.
2. Max head: `root > left` and `root > right`.

## Time Complexity

- Time complexity for the push function in priority queue is `O(logN)`.
- Time complexity for the pop function in priority queue is `O(logN)`.

