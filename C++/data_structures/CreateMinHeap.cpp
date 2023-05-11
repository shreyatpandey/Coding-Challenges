#include<bits/stdc++.h>
using namespace std;

/* priority queue is for max heap and not min heap*/

int main()
{
	//srand(time(0));
	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(5);
	pq.push(10);
	pq.push(2);
	pq.push(8);
	pq.push(4);
	cout<<"[";
	while(!pq.empty())
	{
	 cout<<pq.top()<<",";
	 pq.pop();
	}
	cout<<"]"<<endl;
	return 0;
}
