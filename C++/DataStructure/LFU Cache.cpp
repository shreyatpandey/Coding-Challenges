class LFUCache {
    private:
        int size;
        int count;
        unordered_map<int,pair<int,int>>frequencyCache;
        unordered_map<int,list<int>>freqList; 
/*
 position key should be called to delete elements in list, 
 why the value of list<int> for lru because list<int> is based upon double link list
 */
        unordered_map<int,list<int>::iterator>positionKey;
        //deleting list is not like deleting or erasing an element in unordered_map

public:
    LFUCache(int capacity) {
        size = capacity;
        count = 0;
    }
    
    int get(int key) {
        /* if key does not exist in lfucache, remove it*/
        if(frequencyCache.find(key) == frequencyCache.end())
        {
            return -1;
        }
        /* if key exists in lfucache */
        else
        {
            int value = frequencyCache[key].first;
            freqList[frequencyCache[key].second].erase(positionKey[key]);
            frequencyCache[key].second ++;;
            freqList[frequencyCache[key].second].push_back(key);
            positionKey[key] = --freqList[frequencyCache[key].second].end();
            if (freqList[count].empty())
            {
                count += 1;
            }
            return value;
        }
        return 0;
    }
    
    void put(int key, int value) {
        /* If capacity is zero then return it from here*/
        if (size == 0)
        {
            return;
        }
        /* If key already exists in cache*/
        if (frequencyCache.find(key) != frequencyCache.end())
        {
            frequencyCache[key].first = value;
            freqList[frequencyCache[key].second].erase(positionKey[key]);
            frequencyCache[key].second++;
            freqList[frequencyCache[key].second].push_back(key);
            positionKey[key] = --freqList[frequencyCache[key].second].end();
            if(freqList[count].empty())
            {
                count += 1;
            }
            return;
        }
        /* if the cache size is full */
         if (frequencyCache.size() == size)
        {
            int lfuKey = freqList[count].front();
            frequencyCache.erase(lfuKey);
            positionKey.erase(lfuKey);
            freqList[count].pop_front();
        }
        /* update the cache*/
        frequencyCache[key] = {value,1};
        freqList[1].push_back(key);
        positionKey[key] = --freqList[1].end(); /* this is the thing that I didn't understand*/
        count = 1;
        return ;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
