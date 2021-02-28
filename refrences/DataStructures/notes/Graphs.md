## Intro

- In Graph we have set of vertices and set of Edges connecting those vertices.
- Graph can be connected as well as disconnected, but nodes in a tree are always connected to each other and we can reach any node from any node.
- A Graph can be cyclic or acyclic but tree is always acyclic.

## Graph Terminology

1. **Adjacent Vertices**, means there will be a direct edge.
2. **Degree of a Node**, it is defined as number of edges going through that vertex.
3. **Path**, a path is defined as collection of edges through which we can reach from one point to another.
4. **Connected Graph**, In connected graph there will be a path between any two vertices.
5. **Connected Component**, for a disconnected graph, number of group of components that are connected.
6. **Tree**, a tree is a special graph that is connected and acyclic.
7. **Complete Graph**, In complete graph there is a direct edge between any two vertex. So in complete graph there are nC2 edges.

## Graph Properties

- For a connected graph, min number of edges are (n-1) which is basically a tree and max number of edges are nC2.
- So if there is an algorithm and the time complexity of algorithm is O(E), then in the worst case O(n^2) is the time complexity and O(n) will be time complexity in the best case.

## Graph Implementation

1. Edge list
2. Adjacency List
3. Adjacency Matrix
