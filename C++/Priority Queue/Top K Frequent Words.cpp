/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/

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
