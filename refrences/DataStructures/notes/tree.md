## Tree DataStructure

- The data structure that that we can use to store the organization structure is called a tree.
- Tree is very similar to linked list. Like linked list if we know that head we can iterate over the entire list, in tree also if we know the root node then we know the complete tree.
- In tree each node is storing the address of many nodes
- A generic tree mean a node can have many children, there is not constrains on number of children a node can have.
- Depth of a node is how from the root node.

#### Pre-Order Traversal

This is another way to printing a tree. First print root then print it's children. Printing node and it's children's recursively.

#### Post-Order Traversal

This is opposite of the pre order traversal, it say first you print the children then you print the node/root.

## Binary Tree

A binary tree is a tree, in which every node will have maximum two children's.

#### In-order Traversal

**L->D->N** First you visit the left sub tree, then the current root node data and then visit the right sub-tree.

#### Pre-Order Traversal

**D->L->R** First we visit the data then the left sub-tree and then the right sub-tree. This is a top down approach. We are visiting from top to down.

#### Post-Order Traversal

**L->R->D** First we visit the left sub-tree and then the right sub-tree and finally data. This is bottom up approach.

## Binary Search Tree

There are two main properties of BST, for every node, N:-

1. Everything in N's left sub-tree is less then N's data.
2. Everything in N's right sub-tree is greater then N's data.

- Inorder traversal of the BST is sorted
