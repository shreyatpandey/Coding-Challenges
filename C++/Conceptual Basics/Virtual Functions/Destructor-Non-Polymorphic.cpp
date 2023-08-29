#include <iostream>
using namespace std;

class Base
{
    public:
    ~Base()
    {
        cout<<"Base Destructor:"<<endl;
    }
};
class Derived:public Base
{
    public:
    ~Derived()
    {
        cout<<"Derived Destructor:"<<endl;
    }
};

int main()
{
    Base *ptr = new Derived();
    delete (ptr);
    return 0;
}
// Here there is memory leak , Only the base destructor would be called:- "Base Destructor:". Derived destructor is not called
