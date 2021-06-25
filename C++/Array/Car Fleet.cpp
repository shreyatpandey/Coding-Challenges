bool SortVector(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.first<b.first ;
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>Vec;
        for(int i=0;i<position.size();i++)
        {
            auto MakePair = make_pair(position[i],speed[i]);
            Vec.emplace_back(MakePair);
        }
        vector<double>Result;
        sort(Vec.begin(),Vec.end(),SortVector);
        for(int Reverse = position.size()-1;Reverse>=0;Reverse--)
        {
            int P = Vec[Reverse].first;
            int S = Vec[Reverse].second;
            double ArrivalTime = (double)(target-P)/S;
            if (Result.size() == 0 || ArrivalTime > Result.back())
            {
                Result.emplace_back(ArrivalTime);
            }
        }
        return Result.size();
    }
};
