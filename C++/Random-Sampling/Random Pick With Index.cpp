class Solution {
    private:
        vector<int>SumOfWeights;
public:
    Solution(vector<int>& nums) {
         this->SumOfWeights = nums;
    }
    
    int pick(int target) {
       int count = 0, res = -1;
      for (int i = 0; i <SumOfWeights.size(); ++i)
      {
          if(SumOfWeights[i] == target && (!(rand()%++count))) 
          {
              std::cout<<"rand()%count:"<<rand()%count<<std::endl;
              res=i;
          }
      }
    return res;    
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
