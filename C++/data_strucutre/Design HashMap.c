typedef struct {
    int *hashmap
    
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap *obj = (MyHashMap*)malloc(sizeof(MyHashMap));
    obj->hashmap = (int*)malloc(sizeof(int)*1000000);
    
    for(int i=0;i<1000000;i++)
    {
        obj->hashmap[i] = -1;
    }
    
    return obj;
    
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->hashmap[key] = value;
  
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    if(obj->hashmap[key] != -1)
        return (obj->hashmap[key]);
    
    return -1; 
  
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    obj->hashmap[key] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
