class Solution {
    private:
        int FindSet(vector<int>&TraversalSet, int index) ;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int RowSize_ = edges.size() ;
        int NumberOfComponents = n;
        vector<int>TraversalSet(n,0);
        for(int i =0;i<n;i++)
        {
            TraversalSet[i] = i;
        }
        for(int i=0;i<RowSize_;i++)
        {
            
          int Index1 = FindSet(TraversalSet,edges[i][0]);
          int Index2 = FindSet(TraversalSet,edges[i][1]);
          if ( Index1 != Index2 )
          {
             NumberOfComponents -= 1;
             TraversalSet[Index1] = Index2;
                    
          }
            
        }
        return NumberOfComponents ;
        
    }
};
int Solution::FindSet(vector<int>&TraversalSet,int index)
{
    while ( TraversalSet[index] != index )
    {
        index = TraversalSet[index];
    }
    return index;
}
