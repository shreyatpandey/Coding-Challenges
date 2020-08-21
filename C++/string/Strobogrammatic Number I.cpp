class Solution {
public:
    bool isStrobogrammatic(string num) 
    {
        map<int,int> m = {{0,0},{1,1},{6,9},{8,8},{9,6}};
        int end = (num.size()+1)/2;
        //cout<<"end_value:"<<end;
        int n = num.size()-1;
        for(int i = 0;i<end;i++)
        {
            int a = num[i] - '0';
            int b = num[n-i] -'0';
            if(! (m.find(a) != m.end()))
            {
                return false;
            }
            if(m[a]!=b)
            {
                return false;
            }
        }
        return true;
    }
        
};
