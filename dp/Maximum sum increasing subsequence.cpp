Maximum sum increasing subsequence
https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
/*
Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence. 

Example 1:
    Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
    Output: 106
    Explanation:The maximum sum of a increasing sequence is obtained from {1, 2, 3, 100}

Example 2:
    Input: N = 3, arr[] = {1, 2, 3}
    Output: 6
    Explanation:The maximum sum of a increasing sequence is obtained from {1, 2, 3}

Your Task: You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the maximum value.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)
  */
  
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int size =0;
	    for(int i=0;i<n;i++){
	        size = max(size,arr[i]);
	    }
	    vector<int>dp(size+1,0);
	    
	    int maxi = INT_MIN;
	    
	    for(int i=0;i<n;i++){
	        maxi = 0;
	        for(int j=0;j<i;j++){
	            if(arr[j]>=arr[i])
	                continue;
	            
	            maxi = max(maxi,dp[arr[j]]);
	        }
	        dp[arr[i]] = max(maxi+arr[i],dp[arr[i]]);
	        
	    }
	    
	    maxi = INT_MIN;
	    
	    for(int i=0;i<n;i++){
	        maxi = max(maxi,dp[arr[i]]);
	        
	    }
	    
	    return maxi;
	    
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
