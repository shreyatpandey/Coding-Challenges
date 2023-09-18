class Base {};
class Derived : public Base {};
class UnrelatedClass {};

int main() 
{
	Base base;
	Derived derived;

	// #1: valid upcast
	Base *pBase = static_cast<Base *>(&derived;);  

	// #2: valid downcast
	Derived *pDerived = static_cast<Derived *> (&base;);

	// #3: invalid, between unrelated classes
	UnrelatedClass *pUnrelated 
		= static_cast<UnrelatedClass *> (&derived;);
}
/*
1. Static_cast can be used to force implicit conversions such as non-const object to const, int to double. 
	a. It can be also be used to perform the reverse of many conversions such as void* pointers to typed pointers, 
	base pointers to derived pointers. 
	b. But it cannot cast from const to non-const object. This can only be done by const_cast operator.
 
 2. As we saw in the example, static_cast can perform conversions between pointers to related classes, 
   not only from the derived class to its base, but also from a base class to its derived.
	a. This ensures that at least the classes are compatible if the proper object is converted, 
	b but no safety check is performed during runtime to check 
 	  if the object being converted is in fact a full object of the destination type
*/
