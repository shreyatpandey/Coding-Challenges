public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int,int>ValToIndex = new ();
        int arrayLength = nums.Length;
        for(int i=0;i<arrayLength;i++)
        {
            if (ValToIndex.ContainsKey(target-nums[i]))
            {
                return new[] {ValToIndex[target-nums[i]],i};
            }
            ValToIndex[nums[i]] = i;
        }
        return Array.Empty<int>();
    }
}
