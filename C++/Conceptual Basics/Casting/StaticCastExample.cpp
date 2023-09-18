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
