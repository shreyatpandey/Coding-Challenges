/*
Given a circular array (the next element of the last element is the first element of the array), 
print the Next Greater Number for every element. 
The Next Greater Number of a number x is the first greater number to its traversing-order next in the array,
which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
*/

using Stack = std::stack<int> ;
using NextGreaterArray = std::vector<int>; 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        Stack st;
        NextGreaterArray Array(nums.size(),0);
        for(int i=2*nums.size()-1;i>=0;--i)
        {
          while(st.size()>0 && nums[st.top()]<=nums[i%nums.size()])
          {
              st.pop();
          }
          Array[i%nums.size()] = st.size() == 0? -1:nums[st.top()];
          st.push(i%nums.size());
        }
        return Array;
    }
};
