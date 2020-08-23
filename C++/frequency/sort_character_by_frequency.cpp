class Solution {
public:
    string frequencySort(string s) {
        string result= "";
        if(s.length() == 0)
            return result;
        vector<int>frequency_store;
        map<char,int>hash_map;
        for(size_t i=0;i<s.length();i++)
        {
            hash_map.emplace(s[i],0);
            auto it = hash_map.find(s[i]);
            ++it->second;
            hash_map.emplace(s[i],it->second);
            
        }
        for(auto&x:hash_map)
        {
            frequency_store.emplace_back(x.second);
        }
        
        sort(frequency_store.begin(),frequency_store.end(),greater<int>());
        
        for(int i=0;i<frequency_store.size();i++)
        {
            for(auto&x:hash_map)
            {
                if(x.second == frequency_store[i])
                {
                    size_t found = result.find(x.first);
                    if(!(found != string::npos))
                    {
                        int z = 0;
                        while(z<frequency_store[i])
                        {
                            result += x.first;
                            z++;
                        }
                    }
                }
            }
           
        }
        
    return result;
        
        
    }
};
