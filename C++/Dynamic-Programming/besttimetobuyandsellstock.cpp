#include<bits/stdc++.h>
using namespace std;


class Solution1
{
   public: 
    int maxProfit(vector<int>&prices)
     {
      
      int buy_price  = INT_MAX, sell_price = 0;
      for(size_t i=0;i<prices.size();i++)
      {
         buy_price = min(buy_price,prices[i]);
         sell_price = max(sell_price,prices[i] - buy_price);
     }
          
     return sell_price;
      }
};

class Solution2
{
   public: 
    int maxProfit(vector<int>&prices)
 {
   int max_profit = 0;
   for(size_t i = 0;i<prices.size();i++)
   {
     for(size_t j = i+1;j<prices.size();j++)
      
{
         
         if((prices[j] - prices[i])>max_profit)
        {
            max_profit = prices[j] - prices[i];
         }
      }
   }
 return max_profit;

}

};



int main()
{
 Solution1 s;
 Solution2 s2;
 vector<int>input;
 input.push_back(7);
 input.push_back(1);
 input.push_back(5);
 input.push_back(3); 
  
 input.push_back(6); 
 input.push_back(4);

 cout<<"Maximum_profit_dp:"<<s.maxProfit(input)<<endl;
 cout<<"Maximum_profit_brute:"<<s2.maxProfit(input)<<endl;
 
return 0;

} 
 
    

  
 
  
