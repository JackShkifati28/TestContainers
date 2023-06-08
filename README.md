# Performance Analysis of Data Structures

This repository includes a detailed comparison of the performance characteristics of different data structures, namely: `Vector`, `List`, `Unordered Set`, and `Set`. The metrics used for this comparison are insertion (at the front and end of the data structure) and element lookup.

## Performance Summary

Based on the data received from our program, we observe the following order from fastest to slowest for insertion at the end and finding:

**Insertion from end:**
1. Vector - O(1)
2. List - O(1)
3. Unordered Set - O(1)
4. Set - O(log n)

**Element Finding:**
1. Unordered Set - O(1) or O(n)
2. Set - O(log n)
3. Vector - O(n)
4. List - O(n)

For insertion at the front, the performance from fastest to slowest is as follows:

1. List - O(1)
2. Unordered Set - O(1)
3. Set - O(log n)
4. Vector - O(n)

## Detailed Analysis

### List
- It generally has an insertion time complexity of O(1) for both front and end. However, since it's a doubly-linked list, it works slower than the vector when inserting from the end.
- It's the fastest when inserting from the beginning.
- For finding - it's linear - goes one by one and takes longer than vector because of the reason mentioned above, it's a double-ended linked list.

### Unordered Set
- Normally has an insertion time complexity (regardless if it’s from the beginning or end) of O(1) but can go up to linear time O(n) in the worst case, depending on the hash functions. Based on our data, we have a time complexity of O(n) because of the number of key collisions.
- For finding, has a time complexity of O(1), making it the fastest one.

### Vector
- Fastest when inserting from the end because it adds a new element at the end of the vector by default. It also effectively increases the container by size one and causes an automatic reallocation of the allocated storage.
- Slowest when inserting from the beginning because it has to traverse all the way back (shifting).
- For finding - it's linear - goes one by one.

### Set
- Insertion for set, regardless whether it’s from the front or the end will be O (logn), therefore, relative to the other containers when inserting from the end it ends up last and when inserting to the containers from the front, ends up third.
- For finding, the time complexity is O(logn). Compared to the time complexity of an unordered set which is O(1), set is slower because it has to take the time to order them first.
