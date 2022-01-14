class MyHashMap {
public:
    /** Initialize your data structure here. */
    int size = 10000;
    vector<pair<int, int>> record;
    MyHashMap() {
        record.resize(size, make_pair(-1, -1));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        for (int i = 0; i < size; i++) {
            int k = (key + i) % size;
            if (record[k].first == -1 || record[k].first == key) {
                record[k] = make_pair(key, value);
                return;
            }
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for (int i = 0; i < size; i++) {
            int k = (i + key) % size;
            if (record[k].first == key) return record[k].second;
            if (record[k].first == -1) return -1;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        for (int i = 0; i < size; i++) {
            int k = (i + key) % size;
            if (record[k].first == key) {
                record[k].first = -2;
                return;
            }
            if (record[k].first == -1) return;
        }
        return;
    }
};
