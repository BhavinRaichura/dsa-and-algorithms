
// Geeks for Geeks :
// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1          
// given Constraints: 1 ≤ N ≤ 500       -102 ≤ Arri ≤ 102
// so we only need to change "int" to "long long" and all code is same for both



// leetcode
// https://leetcode.com/problems/maximum-product-subarray/



/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
A subarray is a contiguous subsequence of the array.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
 
        int n = nums.size();
        int max_count =INT_MIN;
        int mult =1;

        for  (int i =0;i<n;i++){
            mult*=nums[i];
            max_count = max(mult,max_count);
            if (mult==0)
                mult=1;
        }
        mult =1;
        for (int i =n-1;i>=0;i--){
            mult*=nums[i];
            max_count =max(mult,max_count);
            if (mult==0)
                mult=1;
        }
        return max_count;

    }
};
