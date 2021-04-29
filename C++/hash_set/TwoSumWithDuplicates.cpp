#include <bits/stdc++.h>
using namespace std;

//Return indexes
//Sc:- O(n), 
//Tc:- O(n)
//Q-1] Return Indices and Indices has to be unique
vector<pair<int,int>>TwoSumTarget(vector<int>&Input,int target)
{
   unordered_set<int> seen;
	unordered_set<int> UniqueValues ;
	vector<pair<int,int>>Result;
	unordered_map<int,int>HashMap;
	int count = 0;
    for(int i=0;i<Input.size();i++)
    {
        auto ptr = make_pair(Input[i],i);
        HashMap.insert(ptr);
        UniqueValues.insert(Input[i]);
    }
	for (int i=0;i<Input.size();i++){
		int complement = target - Input[i];
		if ( HashMap.count(complement))
		{
		if (UniqueValues.find(complement) != UniqueValues.end()){ 
			
			if(seen.find(complement) == seen.end()){ 
				auto pair = make_pair(i,HashMap[complement]);
				Result.emplace_back(pair);
			}
			seen.insert(Input[i]); 
			seen.insert(complement); 	 
		}
		}
		
	}
	return Result;
}

int main()
{
    vector<int>Input = {1,1,2,45,46,46}; //Sorted or unsorted does not matter <=> rather conver them into Sorted
    int target = 47;
    auto Result = TwoSumTarget(Input,target);
    for(auto x:Result)
    {
        cout<<x.first<<","<<x.second<<endl;
    }
    cout<<"====TestCase-1 Ends===="<<endl;
    Input={3,3};
    Result= TwoSumTarget(Input,6); //Will fail in this case
    for(auto x:Result)
    {
        cout<<x.first<<","<<x.second<<endl;
    }
    cout<<"====TestCase-2 Ends===="<<endl;
    return 0;
}
