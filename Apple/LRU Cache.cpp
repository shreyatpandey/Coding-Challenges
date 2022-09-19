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

//Using Doubly Link List
class Node
{
	public:
	int key;
	int value;
	Node* prev, *next;
	Node(int Key,int Value):key(Key),value(Value),prev(nullptr),next(nullptr){}
};

class LRUCache
{
	private:
		int Capacity;
		unordered_map<int,Node*>Cache;
		Node* head ;
		Node* tail;
	public:
		LRUCache(int capacity)
		{
			Capacity = capacity;
			head = new Node(-1,-1);
			tail = new Node(-1,-1);
			head->next = tail;
			tail->prev = head;
		}
		void  remove(Node* removeNode)
		{
			/*
			 No concept of MRU here
			 Just remvoe the Node
			*/
			Node* Previous = removeNode->prev ;
			Node* Next = removeNode->next;
			Previous->next = Next;
			Next->prev = Previous;
		}
		void add(Node* addNode)
		{
			/* put the MRU at the end*/
   			/*AddNode would be the MRU and should be put to the second last*/
    			/* Last Node would be tail/prev which is Initialized to (-1,-1)*/
			Node* secondLast  = tail->prev;
			Node* last = tail;
			secondLast->next = addNode;
			addNode->prev = secondLast;
			last->prev = addNode;
			addNode->next = last; 
		}
		int get(int key)
		{
			if(Cache.count(key) == 0)
			{
				return -1;
			}
			remove(Cache[key]);
			add(Cache[key]);
			return Cache[key]->value;
		}
		void put(int key,int value)
		{
			if (Cache.count(key))
			{
				remove(Cache[key]);
			}
			Cache[key] = new Node(key,value);
			add(Cache[key]);
			if (Cache.size()>Capacity)
			{
				Node* lruNode = head->next;
				remove(lruNode);
				Cache.erase(lruNode->key); //vs Cache.erase(key)
			}
			
		}
		
};
