//Damnit C++ does not have split functions
class Solution {
    private:
        vector<string>Split(const string &Input,const char &delim);
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> Result(n,0);
        stack<int> stk;
        int prev = 0;
        for (const auto& log : logs) {
            vector<string> tokens = Split(log, ':');
            if (tokens[1] == "start") {
                if (!stk.empty()) {
                    Result[stk.top()] += stoi(tokens[2]) - prev;
                }
                stk.emplace(stoi(tokens[0]));
                prev = stoi(tokens[2]);
            } else {
                Result[stk.top()] += stoi(tokens[2]) - prev + 1;
                stk.pop();
                prev = stoi(tokens[2]) + 1;
            }
        }
        return Result;
    }
};
vector<string> Solution :: Split(const string& Input, const char &delim)
{
    stringstream ss(Input);
    vector<string>Tokenizer;
    string Trial;
    while (getline(ss,Trial,delim))
    {
        
        Tokenizer.emplace_back(Trial);
    }
    
    
    return Tokenizer;
}
