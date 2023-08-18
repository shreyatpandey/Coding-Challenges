/*
Input: original = [1,2,3,4], m = 2, n = 2
Output: [[1,2],[3,4]]
Explanation: The constructed 2D array should contain 2 rows and 2 columns.
The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.
Example 2:

Input: original = [1,2,3], m = 1, n = 3
Output: [[1,2,3]]
Explanation: The constructed 2D array should contain 1 row and 3 columns.
Put all three elements in original into the first row of the constructed 2D array.
*/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>Result(m,vector<int>(n,0));
        if ( m*n != original.size())
            return vector<vector<int>>();
        int totalLength = m*n ;
        int index = 0;
        while(index < original.size())
        {
            int rowIndex = index/n;
            int colIndex = index%n;
            Result[rowIndex][colIndex] = original[index];
            index += 1;
        }
        return Result;
    }
};

//vt - solution
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
{
    vector<vector<int>> res;
    if (m * n == original.size())
        for (auto i : original) {
            if (res.empty() || res.back().size() == n)
                res.push_back({});
            res.back().push_back(i);
        }
    return res;
}

//Square matrix without giving m and n would not work
/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original) {
        vector<vector<int>>Result(original.size(),vector<int>(original.size(),0));
        int index = 0;
        const int size = original.size();
        while(index < original.size())
        {
            int rowIndex = index/size;
            int colIndex = index%size;
            Result[rowIndex][colIndex] = original[index];
            index += 1;
        }
        return Result;
    }
};

int main()
{
    vector<int>Mat = {{2,4,6,8,10,11,1,5,7}};
    Solution s;
    auto Result = s.construct2DArray(Mat);
    for(int i=0;i<Result.size();i++)
    {
        for(int j=0;j<Result[i].size();j++)
        {
            cout<<Result[i][j]<<",";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
----| Output |----
2,4,6,8,10,11,1,5,7,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0
*/
