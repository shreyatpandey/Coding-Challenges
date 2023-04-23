# Usage of Shared Pointers
Unique pointers does not support multiple owner concept wherein it has the single owner of resource.

It does not support the following:-
* Copy constructor
* Copy assignment

However unique pointers does support these:-
* Move constructor
* Move assignment

# Shared Pointers
Key thing to remember in shared pointers is:-

* Referencecounting:- 
  * We can have any number of shared_ptrs to the same resource. shared_ptr really does share the resource, if we change the resource with one shared_ptr, the changes also will be seen by the other shared_ptrs. The internal pointer is deleted once the last shared_ptr to the resource is destroyed. shared_ptr uses reference counting to determine how many shared_ptrs point to the resource. Each time a new shared_ptr to the resource is created, the reference count increases, and each time one is destroyed, the reference count decreases. When the reference count reaches zero, the internal pointer is deleted and the memory is released.
  
Semantics of shared pointer:-
* https://www.codementor.io/@sandesh87/1jaohbuey8

# Links for reference and further reading:-
* https://www.bogotobogo.com/cplusplus/boost.php
