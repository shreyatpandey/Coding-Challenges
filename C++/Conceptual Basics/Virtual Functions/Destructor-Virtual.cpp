#include <iostream>
using namespace std;
class Base
{
    public:
    virtual ~Base()
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
/*
  Output:- Derived Destructor 
           Base Destructor
*/
