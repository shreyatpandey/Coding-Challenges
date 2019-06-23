class Solution 
{
    map<char,char> m;
    void util(vector<string> &res, string subres, int start, int end)
    {
         if(start > end)
        {
            res.push_back(subres);
            return;
        }
        for(auto &itr : m)
        {
            if(itr.first == '0' && start == 0 && start != end) 
                continue;
            if(start != end)
            {
                subres[start] = itr.first ;
                subres[end] = itr.second ;
                util(res, subres, start+1, end-1);
            }
            else if(itr.first != '6' && itr.first != '9')
            {
                subres[start] = itr.first;
                util(res, subres, start+1, end);
            }
        }
    }
public:
    vector<string> findStrobogrammatic(int n) 
    {
         m = {{'6', '9'},{'9', '6'},{'1', '1'}, {'8','8'},
                                     {'0', '0'}};
        string subres(n,' '); //simply subres = "" or subres(n,'') will not work
        vector<string> res;
        util(res, subres, 0, n-1);
        return res; 
        
    }
};
