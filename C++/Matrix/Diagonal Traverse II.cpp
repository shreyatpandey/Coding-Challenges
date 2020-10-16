//Given a list of lists of integers, nums, return all elements of nums in diagonal order.
//Rows and Columns can vary , it is not a square matrix
lass Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
         if(matrix.size()==0)
        { 
            return {}; 
        }
        
        int N=matrix.size();
        vector<int>res;
        map<int,vector<int>>dict ;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                int sum=i+j;
                if(dict.count(sum) == 0)
                {
                    dict.insert(make_pair(sum, vector<int>{}));
                }
                dict[sum].emplace_back(matrix[i][j]);
            }
        }
        int ctr=0;
        for(auto &entry:dict)
        {
            vector<int>temp_list; 
            temp_list= entry.second;
            reverse(temp_list.begin(),temp_list.end());   
            for(int i=0;i<temp_list.size();i++)
            {
                res.emplace_back(temp_list[i]);
            }
        }
        return res;
    }
        
};
