#include <iostream>
using namespace std;
class Base
{
    public:
        virtual void show() { cout<<"In Base:"<<endl;}
};
class Derived: public Base
{
  public:
    virtual void show() { cout<<"In Derived:"<<endl;}
};

int main()
{
    Base* bp = new Derived;
    bp->show();

    /* Following lines of code will throw an erro stating:- "Invaild conversion from Derived to Base" */
    //Derived* d = new Base;
    //d->show();

    return 0;
}
