class UnionFind
{
    public:
        void MakeSet(vector<int>&Parent,int N)
        {
            for(int i = 0;i<N;i++)
            {
                Parent[i] = i;
            }
        }
    int Find(vector<int>&Parent,int x)
    {
        if ( Parent[x] == x)
            return x;
        else
            return Find(Parent,Parent[x]);
    }
    void Union(vector<int>&Parent,int x,int y)
    {
        int _index1 = Find(Parent,x);
        int _index2 = Find(Parent,y);
        if (_index1 == _index2)
        {
            return;
        }
        else 
        {
            Parent[_index2] = _index1;
        }
    }
    bool isConnect(vector<int>&Parent,int x,int y)
    {
        return Find(Parent,x) == Find(Parent,y) ;
    }
    
    
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int RowSize = board.size();
        int ColumnSize = board[0].size();
        UnionFind uf;
        vector<int>Parent(RowSize*ColumnSize+1,0);
        uf.MakeSet(Parent,RowSize*ColumnSize+1);
        int DummyValue = RowSize*ColumnSize;
        
        
        for(int i=0;i<RowSize;i++)
        {
            for(int j=0;j<ColumnSize;j++)
            {
                if ( board[i][j] == 'O')
                {
                    if(i==0 || i==RowSize-1 || j==0 || j==ColumnSize-1) /* Boundary Edge Case */
                    {
                            uf.Union(Parent,i*ColumnSize+j, DummyValue);
                    }
                    else
                    {
                        if(i>0 && board[i-1][j]=='O') 
                        {
                            uf.Union(Parent,i*ColumnSize+j, (i-1)*ColumnSize+j);
                        }
                        if(i<RowSize-1 && board[i+1][j]=='O') 
                        {
                            uf.Union(Parent,i*ColumnSize+j, (i+1)*ColumnSize+j);
                        }
                        if(j>0 && board[i][j-1]=='O') 
                        {
                            uf.Union(Parent,i*ColumnSize+j, i*ColumnSize+j-1);
                        }
                        if(j<ColumnSize-1 && board[i][j+1]=='O') 
                        {
                            uf.Union(Parent,i*ColumnSize+j, i*ColumnSize+j+1);
                        }
                    }
                }
            } //end of inner for-loop
        } //end of outer for-loop
        
        
        for(int i=0; i<RowSize; ++i) {
            for(int j=0; j<ColumnSize; ++j) {
                if(board[i][j]=='O'){
                    if(uf.isConnect(Parent,i*ColumnSize+j,DummyValue) == false) board[i][j] = 'X';
                }
            }
        }
    }
};
