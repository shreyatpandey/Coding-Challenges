'''
Simple Max Difference:
int px[n] : an array of stock prices(quotes)
Returns:
  the maximum difference between two prices as described above

For array sorted in descending manner, return -1

Constraints:
1<=n<=10^5
-10^5<=px[i]<=10^5
'''
def maxDifference(px):
  maxProfit = -1
  buyPrice = float('inf')
  for i,val in enumerate(px):
    if val < buyPrice:
      buyPrice = val
     elif val - buyPrice > maxProfit:
      maxProfit = val - maxProfit
  
  return maxProfit
  
