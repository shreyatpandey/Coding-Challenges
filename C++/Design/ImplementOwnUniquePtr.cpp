#include<bits/stdc++.h>
using namespace std;

template<class T>
class My_Unique_Ptr
{
  private:
    typedef T AnyPointer;
    AnyPointer* p_AnyPointer;
 public:
  My_Unique_Ptr():p_AnyPointer(nullptr){};
  My_Unique_Ptr(T* p = 0):p_AnyPointer(p) {}; 
  My_Unique_Ptr(const My_Unique_Ptr & obj) = delete ; //copy constrcutor is deleted
  My_Unique_Ptr&operator = (const My_Unique_Ptr&obj) = delete ; //copy assignment is deleted
  
  My_Unique_Ptr(My_Unique_Ptr &&ObjectGivingUpResource) //move constrcutor
  {
      this->p_AnyPointer = ObjectGivingUpResource ;
      ObjectGivingUpResource.p_AnyPointer = nullptr;
  }
  void operator = (My_Unique_Ptr &&ObjectGivingUpResource) //move assignment
  {
      if ( p_AnyPointer != nullptr)
      {
          delete p_AnyPointer ;
      }
      this->p_AnyPointer = ObjectGivingUpResource ;
      ObjectGivingUpResource.p_AnyPointer = nullptr;
  }
  
  ~My_Unique_Ptr()
  {
      if ( p_AnyPointer != nullptr)
        delete p_AnyPointer ;
  }
};
