/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let hashMap = new Map();
    let result = [];
    var arrayLength = nums.length;
    for(let i=0;i<arrayLength;i++)
    {
        if(hashMap.has((target - nums[i])))
        {
            result.push(hashMap.get((target-nums[i])));
            result.push(i);
            return result;
        }
        hashMap.set(nums[i],i);
    }
    return result;
};
let input = [2,7,11,15];
let target = 9;
var result = twoSum.call(this,input, target);
console.log(result);
