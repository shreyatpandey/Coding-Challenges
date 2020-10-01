/*
Approach - 1
TC: O(n^2) solution
*/
class Solution {
    private:
        int NumberOfOnes(int num);
public:
    vector<int> sortByBits(vector<int>& arr) {
        for ( int i = 0;i<arr.size()-1;i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                int first = NumberOfOnes(arr[i]);
                int second = NumberOfOnes(arr[j]);
                if( first > second )
                {
                        swap(arr[j],arr[i]);
                }
                if ((first == second) && arr[j]<arr[i])
                    swap(arr[j],arr[i]);
            }
        }
        return arr;
    }
};
int Solution::NumberOfOnes(int num)
{
    int Count = 0;
    while ( num )
    {
        num = num & (num-1);
        Count += 1;
    }
    return Count;
}
