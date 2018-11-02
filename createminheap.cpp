#include<bits/stdc++.h>
using namespace std;

/* priority queue is for max heap and not min heap*/

int main()
{
	//srand(time(0));
	priority_queue<int,vector<int>,greater<int>> pq = {5,10,2,8,4};
	//for(int i=0;i <5;i +=1)
	//pq.push(rand()%10);
	cout<<"[";
	while(!pq.empty())
	{
	 cout<<pq.top()<<",";
	 pq.pop();
	}
	cout<<"]"<<endl;
	return 0;
}
