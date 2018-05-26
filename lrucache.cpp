/*to implement a LRU cache */

#include<bits/stdc++.h>
using namespace std;

class LRUcache
{
   protected: 
   list<int>queue;
   unordered_map<int,list<int>::iterator> hash;
   int capacity;
   public:
   LRUcache(int cap)
   {
    capacity = cap;
    }
   int get(int key)
   {
    /*chech if the key exists in the cache or not */
   if(hash.find(key)!=hash.end())
   {
     list<int>::iterator it = hash[key];
     queue.erase(it);
     queue.push_front(key);
     hash[key] = queue.begin();
     return key;
   }
  else   /* if the key does not exist in the cache*/
  {
    return -1;
  }
 }
void put(int key)
{
  if(hash.find(key) == hash.end())
  {
    if (queue.size() == capacity)
    {
      hash.erase(queue.back());
      queue.pop_back();
    }
  queue.push_front(key);
  hash.insert({key,queue.begin()});
  }
 else
{
    
   list<int>::iterator it = hash[key];
     queue.erase(it);
     queue.push_front(key);
     hash[key] = queue.begin();
   }
}
void cachedisplay()
{
  if(queue.empty())
  {
   cout<<"Empty cache"<<endl;
   }
  list<int>::iterator it;
  for(it=queue.begin();it!=queue.end();++it)
   {
    cout<<(*it)<<"";
   cout<<endl;
  }
}
};
int main()
{
  LRUcache lruc(2);
  
  lruc.put(4);
  lruc.put(2);
  lruc.cachedisplay();

  return 0;
} 
