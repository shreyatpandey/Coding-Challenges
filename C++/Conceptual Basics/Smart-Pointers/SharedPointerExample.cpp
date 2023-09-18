#include<iostream>
#include<memory>
using namespace std;

int main()
{
//create an int, make ptr1 the owner
std::shared_ptr<int> ptr1 (new int(10));

// make ptr2 an owner of the int created on previous line.
// now, both ptr1 and ptr2 own the int
std::shared_ptr<int> ptr2 (ptr1); // copy constructor

// create one more int, make ptr3 the owner
std::shared_ptr<int> ptr3 (new int(15));

// invalidate ptr3, ptr4 becomes the new owner
std::shared_ptr<int> ptr4 (std::move(ptr3)); // move constructor

std::cout << ptr1.use_count() << std::endl; // 2
std::cout << ptr2.use_count() << std::endl; // 2
std::cout << ptr3.use_count() << std::endl; // 0
std::cout << ptr4.use_count() << std::endl; // 1

return 0;  
}
