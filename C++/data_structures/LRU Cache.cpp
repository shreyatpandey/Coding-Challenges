/*to implement a LRU cache */
//Most Recently used page would be in the front and least recently used page would be int the last
//Approach 
//TC: O(1)
//Space Complexity: O(m+n) where m is the space for hashmap and n is the space for list
using LRU = std::unordered_map<int,list<pair<int,int>>::iterator>; // constant operation:- O(1)
using Cache = std::list<pair<int,int>>; //doubly linked list
class LRUCache {
public:
    const int capacity;
    Cache cache; // This is Cache
    LRU lru;// This is LRU
    
    int remove(list<pair<int,int > >::iterator it) 
    {
        int key = it->first;
        int val = it->second ;
        cache.erase(it);
        lru.erase(key);
        return (val);
    }
    
    void add(const int & key, const int & value) 
    {
        auto  KeyValuePair = make_pair(key,value);
        cache.push_back(KeyValuePair);
        auto it = cache.end();
        lru[key] = --(it);
    }
    
    LRUCache(int capacity) : capacity(capacity) {}
    ~LRUCache()
    {
        lru.clear();
        cache.erase(cache.begin(),cache.end());
    }
    
    int get(int key) 
    {
        if(lru.count(key) == 0 ) 
        {
            return -1;
        }
        int value = remove(lru[key]);
        add(key, value);
        return value;
    }
    
    void put(int key, int value) 
    {
        if(lru.count(key))
        {
            remove(lru[key]);
        }
        if(cache.size() == capacity) 
            remove(cache.begin());
        
        add(key, value);
    }
};
