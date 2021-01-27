/*to implement a LRU cache */
//Approach 
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
