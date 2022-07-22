Longest Increasing Subsequence
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
/*
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.
Example 1:

Input:
    N = 16
    A[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
    Output: 6
    Explanation:Longest increasing subsequence 0 2 6 9 13 15, which has length 6

Example 2:
    Input:
    N = 6
    A[] = {5,8,3,7,9,1}
    Output: 3
    Explanation:Longest increasing subsequence 5 7 9, with length 3

Your Task: Complete the function longestSubsequence() which takes the input array and its size as input parameters and returns the length of the longest increasing subsequence.

Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)
*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    /*
    // backtrcking
    
    int maxCnt = 1;
    public:
    //Function to find length of longest increasing subsequence.
    
    void fn(int idx, int cnt, int last, int a[]){
        maxCnt = max(cnt,maxCnt);
        
        if(idx<0) return;
        
        if(last>a[idx]){
            fn(idx-1, cnt+1, a[idx],a);
        }
        fn(idx-1, cnt, last,a);

    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       fn(n-1,0,INT_MAX,a);
       return maxCnt;
    }
    */
    
    public:
    int longestSubsequence(int n, int arr[]){
        int maxele= INT_MIN;
        
        for(int i=0;i<n;i++){
            maxele = max(maxele,arr[i]);
        }
        
        vector<int>dp(maxele+1,0);
        int j=0;
        int m =INT_MIN;
        
        for(int i=0;i<n;i++){
            
            if(arr[i]==0){
                dp[0]=1;
                continue;
            }
            
            m=INT_MIN;
            for(j=0;j<arr[i];j++){
                m = max(m ,dp[j]);
            }
            dp[arr[i]]= max(dp[arr[i]],m+1);
        }
        
        int ans =0;
        for(int i=0;i<dp.size();i++){
            ans= max(ans,dp[i]);
            //cout<<i<<"  "<<dp[i]<<endl;
        }
        
        return ans;
        
        
    }
};
