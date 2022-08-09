#include <bits/stdc++.h>
using namespace std;

size_t myHashFunc(const size_t & key)
{
    return key;
}

template<class K,class V,size_t hashfunc(const size_t&)>
class HashTable
{
    public:
    vector<shared_ptr<pair<K,V>>>HashRecord;
    HashTable(int buckets):HashRecord(buckets) {};
    bool empty() const
    {
      return true;    
    }
    size_t size() const
    {
      return 0;
    }
    void put(const K&key,const V&value)
    {
        int HashRecordSize = HashRecord.size();
        for(size_t Loop = 0; Loop < HashRecordSize ; Loop++)
        {
            size_t Index = ((size_t)hashfunc + Loop)%HashRecordSize ;
            if (!HashRecord[Index] || HashRecord[Index]->first == key)
            {
                auto ptr = make_pair(key,value);
                HashRecord[Index] = make_shared<pair<K,V>>(ptr);
                return ;
            }
        }
    }
    bool get (const K&key,const V&value) const
    {
        int HashRecordSize = HashRecord.size();
        for(size_t Loop = 0 ; Loop < HashRecordSize ; Loop++)
        {
            size_t Index = ((size_t)hashfunc + Loop)%HashRecordSize ;
            if ( !HashRecord[Index] )
            {
                return false;
            }
            if ( HashRecord[Index]->first == key)
            {
                HashRecord[Index]->second = value;
                return true;
            }
        }
        return false;
    }
    bool erase(const K&key)
    {
        return false;
    }
};

int main()
{
    HashTable<int,string,myHashFunc> Hash(10);
    Hash.put(5,"five");
    Hash.put(6,"six");
    auto result = Hash.get(6,"six");
    cout<<"result:"<<boolalpha<<result<<endl;
    result = Hash.get(18,"eighteen");
    if(result)
    {
        cout<<"Key Found:"<<endl;
    }
    else
    {
        cout<<"Not Found:"<<endl;
    }
    return 0;
}
