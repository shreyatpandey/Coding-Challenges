class Base
{
    public:
         void show() { cout<<"In Base:"<<endl;}
};
class Derived: public Base
{
  public:
    void show() { cout<<"In Derived:"<<endl;}
};

int main()
{
    Base* bp = new Derived;
    bp->show();
    // Being non polymorphic , it would output:- In Base
    
    
    /* Dynamic casting will not work on non-polymorphic*/
    /*
    Derived *d ;
    Base* bp1 = dynamic_cast<Base*>(d);
    Derived* d1 = dynamic_cast<Derived*>(bp1);
    if(d1)
    {
        d1->show();
    }
    else
    {
        cout<<"Is null:"<<endl;
    }
    */

    return 0;
}
