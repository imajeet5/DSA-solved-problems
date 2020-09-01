### binary Search

#### Q) Check if X exists in the sorted array or not

`A[] = {1,4,5,8,9}`

`bool = res = binary_search(A, A+n, 3);` // false
`bool = res = binary_search(A, A+n, 4);` // true

### lower_bound:

lower_bound is a STL function, which return the first occurance of the element if it occurs and if it doesn't occurs then it will return the iterator pointing to the element which is immediate next greater of the given element.

`int ind = lower_bound(A, A+n,4)` // return iterator pointing at 4

### upper_bound

upper_bound function will not return the iterator pointing to the passed element but instead it will return iterator which will points to the next greater element. If the element doesn't exist it will return iterator point to the element after the end.
