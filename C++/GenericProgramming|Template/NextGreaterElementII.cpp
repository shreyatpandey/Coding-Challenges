#include<bits/stdc++.h>
using namespace std;
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
          cout<<"Array[i modulo nums.size()]:"<<Array[i%nums.size()]<<endl;
          st.push(i%nums.size());
        }
        
        return Array;
    }
};
using UniquePtr = std::unique_ptr<Solution>;
int main()
{
    NextGreaterArray InputVector{1,2,1} ;
    UniquePtr Unique(new Solution);
    auto Result = Unique->nextGreaterElements (InputVector);
    return 0;
}
