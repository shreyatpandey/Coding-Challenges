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



//Approach-2 :
//TC: O(1)
//Space Complexity: O(m+n) where m is the space for hashmap and n is the space for list
class LRUCache {
public:
    const int capacity;
    list<pair<int,int>> l; // This is cache
    unordered_map<int, list<pair<int,int > >::iterator> m; // This is used to make 
    // Least Recently = Map + Cache = List
    
    int remove(list<pair<int,int > >::iterator it) 
    {
        int key = it->first;
        int val = it->second ;
        l.erase(it);
        m.erase(key);
        return (val);
    }
    
    void add(const int & key, const int & value) 
    {
        l.push_back({key, value});
        auto it = l.end();
        m[key] = --(l.end());
    }
    
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) 
    {
        if(!m.count(key)) 
        {
            return -1;
        }
        int value = remove(m[key]);
        add(key, value);
        return value;
    }
    
    void put(int key, int value) 
    {
        if(m.count(key))
        {
            remove(m[key]);
        }
        if(l.size() == capacity) 
            remove(l.begin());
        
        add(key, value);
    }
};
