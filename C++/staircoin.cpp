#include<bits/stdc++.h>
using namespace std;


int main()
{
   int n=8;
   int firstlevel=1;
   int sum=0;
   for(int sum=0;sum<=n;firstlevel++)
   {
     sum+=firstlevel;
     cout<<sum<<endl;
     for(int j=1;j<=firstlevel;j++)
      {
        cout<<"c";
      }
     cout<<endl;
     
   }
  if((firstlevel-2)>0)
    cout<<"Value that remains"<<(firstlevel-2)<<endl;
  else
  cout<<"No value remains"<<endl;
   
return 0;

//return max(firstlevel-2,0);
  
}
