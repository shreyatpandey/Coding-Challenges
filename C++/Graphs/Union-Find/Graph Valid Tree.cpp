class Solution {
    private:
        vector<int>TraversalSet ;
        vector<int>Size ;
        int Find ( int Index);
        bool Union(int Root1,int Root2);
public:
    bool validTree(int n, vector<vector<int>>& edges){
        if ( edges.size() != n-1 )
            return false;
        /* Make the array */
        for(int i=0;i<n;i++)
        {
            TraversalSet.emplace_back(i);
            Size.emplace_back(i);
        }
        for  (const auto edge:edges)
        {
            if ( Union(edge[0],edge[1]) == false)
                return false;
        }
        return true;
    }
};
bool Solution::Union(int Root1,int Root2)
{
    int FindRoot1 = Find(Root1);
    int FindRoot2 = Find(Root2) ;
    if (FindRoot1 == FindRoot2)
    {
        return false;
    }
    if ( Size[FindRoot1] < Size[FindRoot2] )
    {
        TraversalSet[FindRoot1] = FindRoot2 ;
        Size[FindRoot2] += Size[FindRoot1] ; // why this
    }
    else
    {
        TraversalSet[FindRoot2] = FindRoot1;
        Size[FindRoot1] += Size[FindRoot2];
        
    }
    return true;
    
}

int Solution::Find(  int Index )
{
    int Root = Index ;
    while ( TraversalSet[Root] != Root)
    {
        Root = TraversalSet[Root] ;
    }
    while ( Index != Root)
    {
        int OldRoot = TraversalSet[Index];
        TraversalSet[Index] = Root;
        Index = OldRoot;
    }
    return Root;
}
