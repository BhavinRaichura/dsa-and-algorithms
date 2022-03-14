### leetcode - 1695. Maximum Erasure Value
# You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

# Return the maximum score you can get by erasing exactly one subarray.

# An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).


## Example 2:
# Input: nums = [5,2,1,2,5,2,1,2,5]
# Output: 8
# Explanation: The optimal subarray here is [5,2,1] or [1,2,5].



class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        # optimised sliding window problem
        maxsum=0
        left =0
        arrset=set()
        c=0
        for i in range(len(nums)):
            while nums[i] in arrset:
                arrset.remove(nums[left])
                maxsum-=nums[left]
                left+=1
                
            arrset.add(nums[i])
            maxsum+=nums[i]
            c=max(c,maxsum)
 
        return c
                
