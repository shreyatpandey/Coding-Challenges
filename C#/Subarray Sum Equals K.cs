public class Solution {
    public int SubarraySum(int[] nums, int k) {
        Dictionary<int,int> sumToFreq = new Dictionary<int,int>();
        int totalNoOfSubarrays = 0;
        int numsLength = nums.Length;
        int sumTotal = 0;
        for(int i=0;i<numsLength;i++)
        {
            sumTotal += nums[i];
            if(sumTotal == k)
            {
                totalNoOfSubarrays += 1;
            }
            if (sumToFreq.ContainsKey(sumTotal-k))
            {
                totalNoOfSubarrays += sumToFreq[sumTotal-k];
            }
            if(sumToFreq.ContainsKey(sumTotal))
            {
                sumToFreq[sumTotal] += 1;
            }
            else
            {
                sumToFreq.Add(sumTotal,1);
            }
        }
        return totalNoOfSubarrays;
    }
}
