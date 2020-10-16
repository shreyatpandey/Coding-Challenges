/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

 

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
        { 
            return {}; 
        }
        
        int N=matrix.size();
        int M=matrix[0].size();
        vector<int>res(N*M,0);
        map<int,vector<int>>dict ;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                int sum=i+j;
                if(dict.count(sum) == 0)
                {
                    dict.insert(make_pair(sum, vector<int>{}));
                }
                dict[sum].emplace_back(matrix[i][j]);
            }
        }
        int ctr = 0;
        for(auto &entry:dict)
        {
            vector<int>temp_list; 
            if((entry.first%2)==0)
            {
                temp_list= entry.second;
                reverse(temp_list.begin(),temp_list.end());
            }
            else
            {
                 temp_list= entry.second;
            }
            for(int i=0;i<temp_list.size();i++)
            {
                res[ctr++] = temp_list[i];
            }
        }
        return res;
    }
};
