#include<iostream>
#include<memory>
using namespace std;

class B;

class A
{
    shared_ptr<B> sP1; // use weak_ptr instead to avoid CD

public:
    A() {  cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }

    void setShared(shared_ptr<B>& p)
    {
        sP1 = p;
    }
};

class B
{
    shared_ptr<A> sP1;

public:
    B() {  cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }

    void setShared(shared_ptr<A>& p)
    {
        sP1 = p;
    }
};

int main()
{
    shared_ptr<A> aPtr(new A);
    shared_ptr<B> bPtr(new B);

    aPtr->setShared(bPtr);
    bPtr->setShared(aPtr);

    return 0;  
}
//Destructor is never called hence there is memory leak
