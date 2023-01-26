# cacheSystem

A simple cache system in C++ with FIFO , LIFO and LRU eviction algorithms. 


It is Flexible and you can use custom eviction policies and storage policies.

## Usage
1. Clone the repository
2. Include the header file in your project
3. Create a cache object with the desired eviction policy and storage policy
4. Use the cache object to store and retrieve data
5. delete all the pointers

## Time Complexity
1. Insertion : O(1)
2. Access : O(n) for LRU and O(1) for FIFO and LIF0
3. Update : O(n) 
