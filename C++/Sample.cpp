#include <iostream>
using namespace std;

class Base
{
    public:
    virtual void show()
    {
        cout<<"Base class:"<<endl;
    }
};
class Derived:public Base
{
    public:
    virtual void show()
    {
        cout<<"Derived class:"<<endl;
    }
};

int main()
{
    /* Simple call of function*/
    Base* b = new Base();
    Derived* d = new Derived();
    b->show();
    d->show();

    /* usage of virtual function, base pointer holds reference of derived pointer*/
    Base* b1;
    Derived d1;
    b1= &d1;
    b1->show();

    /*
    Following code will throw error:- invalid conversion from base to derived
    */
    //Base b2;
    //Derived *d2;
    //d2 = &b2;
    //d2->show();
    /*
     Following code will throw error because, conversion is required 
     Dynamic cast
    */
    //Derived d1 = new Base();
    //d1->show();
    //Base b1 = new Derived();
    //b1->show();
    return 0;
}
