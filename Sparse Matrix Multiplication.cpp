#include<bits/stdc++.h>
using namespace std;


class Solution
{
    private:
        int Arowlength = 0;
        int Acolumnlength = 0;
        int Bcolumnlength = 0;
        int Browlength = 0;
    public:
        vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B)
        {
            Arowlength = A.size();
            Acolumnlength = A[0].size();
            Bcolumnlength = B[0].size();
            vector<vector<int>> Resultmatrix(Arowlength, vector<int>(Bcolumnlength, 0));
            for(int i=0;i<Arowlength;i++)
            {
                for(int j=0;j<Acolumnlength;j++)
                {
                    if(A[i][j] == 0)
                        continue;
                        for(int k=0;k<Bcolumnlength;k++)
                        {
                            Resultmatrix[i][j] += A[i][j]*B[j][k];
                        }
                }
            }
            return Resultmatrix;
            
    }
    
};
 int main()
 {
     Solution S;
     vector<vector<int>>A = {{ 1, 0, 0},{-1, 0, 3}};
     vector<vector<int>>B = {{ 7, 0, 0},{ 0, 0, 0 },{ 0, 0, 1 }};
     vector<vector<int>>Resultmatrix = S.multiply(A,B);
     for(int i=0;i<Resultmatrix.size();i++)
     {
         for(int j=0;j<Resultmatrix[0].size();j++)
         {
             cout<<Resultmatrix[i][j];
             if( j != Resultmatrix[0].size() - 1)
                { cout<<",";}
            
         }
         cout<<endl;
     }
     return 0;
 }

