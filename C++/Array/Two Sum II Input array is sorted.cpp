class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start_index = 0;
        int last_index = numbers.size()-1;
        while(start_index < last_index)
        {
            if ( numbers[start_index] + numbers[last_index] == target)
            {
                return {start_index+1,last_index+1};
            }
            else if (numbers[start_index] + numbers[last_index] < target)
            {
                start_index ++;
            }
            else
            {
                last_index --;
            }
        }
        return {0,0};
    }
};
