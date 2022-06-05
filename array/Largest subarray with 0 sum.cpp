// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/
/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
  
Example 1:
Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with sum 0 will be -2 2 -8 1 7.

Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

// loop laga kr hr ek value ko sum karenge aur check karenge ki koi sum pahele hi aa chuka hai ya nahi 
// if aa gaya hai to us i'th iteration pr hamara sum 0 hoga 
/* ex.: sum = 1+2 =2
        sum = sum+(-2)=1
        yaha 2+(-2)=0 so iske baad same value aa rahi hai jo pahele hi calculate ho chuki hai 
        */

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int ans=0;
        int sum=0;
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                ans = max(ans,i+1);
            }
            else if(m[sum]){
                ans = max(ans,i-m[sum]+1);
            }
            else{
                m[sum]=i+1;
            }
//            cout<<sum<<"   ";
        }
       
        
        return ans;
    }
};
