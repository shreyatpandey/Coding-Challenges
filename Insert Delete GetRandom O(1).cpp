/*
Design a data structure that supports all following operations in average O(1) time.

1.insert(val): Inserts an item val to the set if not already present.
2.remove(val): Removes an item val from the set if present.
3.getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

*/
class RandomizedSet {
    map<int,int>dictionary;
    vector<int>values;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dictionary.count(val)>0)
        {
            return false;
        }
        values.emplace_back(val);
        dictionary[val] = values.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
       
        if (dictionary.count(val) == 0)
            return false;
        int valueslastelement = values[values.size()-1];
        int indexofinputvalue = dictionary[val];
        dictionary[valueslastelement] = indexofinputvalue;
        swap(values[indexofinputvalue],values[values.size()-1]);
        values.pop_back();
        dictionary.erase(val);
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return values[rand()%values.size()];
        
    }
};
