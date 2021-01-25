/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Find the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
*/
//using Set
//Approach-1
//SC:- O(n)

using Set = std::set<int>;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        Set set(arr.begin(),arr.end());
        int current = 1;
        while(k)
        {
            if ( set.find(current) == set.end() ) 
            {
                k -= 1;
            }
            current +=1 ;
        }
        return current - 1;
    }
};

//Approach-2
//Binary Search
//TC:- O(Log(N))
//SC:- O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int LeftIndex = 0, RightIndex = arr.size();
        while(LeftIndex < RightIndex)
        {
            int MidValue = (RightIndex+LeftIndex)>>1;
            if(arr[MidValue]-MidValue>k)
            {
                RightIndex = MidValue ;
            }
            else
            {
                LeftIndex = MidValue + 1;
            }
        }
        return LeftIndex + k;
    }
};
