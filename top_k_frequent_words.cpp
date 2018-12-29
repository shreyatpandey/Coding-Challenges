class Solution {
private:
    struct compare_two
{
    bool operator()(pair<int,string>&first_part,pair<int,string>&second_part)
        {
            return (first_part.first == second_part.first ? first_part.second < second_part.second : first_part.first > second_part.first);           
                
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>final_result;
        unordered_map<string,int>hash_map;
        for(int i=0;i<words.size();i++)
            ++hash_map[words[i]];
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare_two>pq;
        unordered_map<string,int>::iterator it;
        for(auto const& p:hash_map)
        {
            pq.push(make_pair(p.second,p.first));
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty())
        {
            final_result.insert(final_result.begin(), pq.top().second);
            pq.pop();
        }
     return final_result;        
    }
};
