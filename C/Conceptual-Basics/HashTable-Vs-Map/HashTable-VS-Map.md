# Hash Table vs STL Map

## Question
**Hash Table vs STL Map:** Compare and contrast a hash table and an STL map. How is a hash table implemented? If the number of inputs is small, which data structure options can be used instead of a hash table?

## Answer

### Hash Table Overview
In a hash table, a value is stored by calling a hash function on a key. Values are **not stored in sorted order**. Additionally, since hash tables use the key to find the index that will store the value, an insert or lookup can be done in **amortized O(1) time** (assuming few collisions in the hash table).

#### Collision Handling
In a hash table, one must also handle potential collisions. This is often done by **chaining**, which means to create a linked list of all the values whose keys map to a particular index.

*Alternative: Linear Probing*

### STL Map Overview
An STL map inserts the key/value pairs into a **binary search tree** based on the keys. There is no need to handle collisions, and, since the tree is balanced, the insert and lookup time is guaranteed to be **O(log N)**.

## Hash Table Implementation

A hash table is traditionally implemented with an **array of linked lists**.

### Process:
1. When we want to insert a key/value pair, we map the key to an index in the array using a hash function
2. The value is then inserted into the linked list at that position

### Important Note:
The elements in a linked list at a particular index of the array do **not** have the same key. Rather, `hashFunction(key)` is the same for these values. Therefore, in order to retrieve the value for a specific key, we need to store in each node both the **exact key** and the **value**.

### Summary:
The hash table will be implemented with an array of linked lists, where each node in the linked list holds two pieces of data:
- The **value**
- The **original key**

## Design Criteria

In addition, we will want to note the following design criteria:

### 1. Good Hash Function
We want to use a good hash function to ensure that the keys are well distributed. If they are not well distributed, then we would get a lot of collisions and the speed to find an element would decline.

### 2. Collision Handling
No matter how good our hash function is, we will still have collisions, so we need a method for handling them. This often means chaining via a linked list, but it's not the only way.

### 3. Dynamic Resizing
We may also wish to implement methods to dynamically increase or decrease the hash table size depending on capacity. 

**Example:** When the ratio of the number of elements to the table size exceeds a certain threshold, we may wish to increase the hash table size. This would mean:
- Creating a new hash table
- Transferring the entries from the old table to the new table

Because this is an expensive operation, we want to be careful to not do it too often.

## Alternatives for Small Input Sizes

### What can be used instead of a hash table, if the number of inputs is small?

You can use:
- **STL map**
- **Binary tree**

Although this takes **O(log(n))** time, the number of inputs may be small enough to make this time negligible.

## Comparison Summary

| Feature | Hash Table | STL Map |
|---------|------------|---------|
| **Time Complexity** | O(1) average | O(log n) |
| **Ordering** | No inherent order | Sorted by keys |
| **Implementation** | Array + Linked Lists | Balanced Binary Search Tree |
| **Collision Handling** | Required (chaining/probing) | Not applicable |
| **Memory Usage** | Can have overhead from empty buckets | Consistent per node |
| **Best Use Case** | Fast lookups, large datasets | Small datasets, need sorted order |
