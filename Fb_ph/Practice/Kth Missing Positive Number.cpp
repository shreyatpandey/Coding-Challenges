/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int LeftIndex = 0, RightIndex = arr.size();
        while(LeftIndex < RightIndex)
        {
            int MidValue = LeftIndex + (RightIndex - LeftIndex)/2;
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
