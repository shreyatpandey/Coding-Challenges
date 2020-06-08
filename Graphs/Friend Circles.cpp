/*
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. 
For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. 
And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, 
then the ith and jth students are direct friends with each other, otherwise not. 
And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
*/

//Recursion
//TC: O(TotalFriends + NumberOfFriends) ; O(V+E)
//SC: O(1)
class Solution {
    private:
        int i_MatrixSize ;
        int i_NumberOfFriends ;
        void HelperFriendCircle(vector<vector<int>>&Input, int Index);
public:
    int findCircleNum(vector<vector<int>>& M) {
        i_MatrixSize = M.size();
        for(int i=0;i<i_MatrixSize;i++)
        {
            for(int j=0;j<i_MatrixSize;j++)
            {
                if (M[i][j] == 1)
                {
                    i_NumberOfFriends += 1;
                    HelperFriendCircle(M,i);
                }
            }
        }
        return i_NumberOfFriends ;         
    }
};
void Solution::HelperFriendCircle(vector<vector<int>>&Input, int Index)
{
    for(int i=0;i<i_MatrixSize;i++)
    {
        if ( Input[Index][i] == 1)
        {
            Input[Index][i] = 0;
            HelperFriendCircle(Input,i);
        }
    }
    
}
