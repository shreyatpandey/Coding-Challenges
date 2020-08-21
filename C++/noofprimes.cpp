/* use sieve of erastothenes */
#include<bits/stdc++.h>
using namespace std;

class Solution
{ 
  public:
    int countPrimes(int n)
   {
     vector<int>primes(n+1,1);
     for(int p=2;pow(p,2)<=n;p++)
      {
       if(primes[p]!=0)
        {
           for(int i=p*2;i<=n;i+=p)
           {
              primes[i]=0;
           }
        }
     }
   int noofprimes =0;
    for(int k=2;k<=n;k++)
     {
       if(primes[k]!=0)
        {
         noofprimes+=1;
       }
     }
    return noofprimes;
}
};
int main()
{
   Solution s;
   cout<<"No of primes:"<<s.countPrimes(30)<<endl;
   return 0;
}
