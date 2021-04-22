//TC:- O(nLog(n))
//Using Priority Queue
/*
Input:-
A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

 

Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.
*/
using Map = unordered_map<char,int>  ;
using PQ = priority_queue<int> ;
class Solution {
public:
    int minDeletions(string s) {
        Map map ;
        PQ pq;
        for(char x:s)
        {
            map[x] += 1;
        }
        for(auto x:map)
        {
            pq.push(x.second);
        }
        int ReqNoOfDeletion = 0 ;
        while ( pq.size())
        {
            int CurrentCount = 0;
            CurrentCount = pq.top() ;
            pq.pop();
            if( pq.empty()) return ReqNoOfDeletion ;
            if ( CurrentCount == pq.top() )
            {
                if ( CurrentCount - 1 > 0)
                {
                    pq.push(CurrentCount-1) ;
                }
                ReqNoOfDeletion +=1 ;
            }
        }
        return ReqNoOfDeletion ;    
    }
};
