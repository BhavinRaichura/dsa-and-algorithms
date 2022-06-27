Number of Coins 
https://practice.geeksforgeeks.org/problems/number-of-coins1824/1/?page=2#

/*
Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.

Example 1:
    Input: V = 30, M = 3, coins[] = {25, 10, 5}
    Output: 2
    Explanation: Use one 25 cent coin and one 5 cent coin

Example 2:
    Input: V = 11, M = 4,coins[] = {9, 6, 5, 1} 
    Output: 2 
    Explanation: Use one 6 cent coin and one 5 cent coin

Your Task:  
You don't need to read input or print anything. Complete the function minCoins() which takes V, M and array coins as input parameters and returns the answer.

Expected Time Complexity: O(V*M)
Expected Auxiliary Space: O(V)

Constraints:
    1 ≤ V*M ≤ 106
    All array elements are distinct
*/

class Solution{
      //  int mincnt =0;
	public:
	
  // tabulation
	int minCoins(int arr[], int n, int v) 
	{ 
	    vector<int>dp(v+1,INT_MAX);
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]>v) continue;
	        
	        dp[arr[i]]=1;
	        
	        for(int j=0;j<v;j++){
	            
	            if(j%arr[i]==0){
	                dp[j] = min(dp[j], j/arr[i]);
	            }
	            if(dp[j]!=INT_MAX and arr[i]+j<=v){
	                
	                dp[arr[i]+j] = min(dp[arr[i]+j],dp[j]+1);
	                
	            }
	        }
	    }
	    if(dp[v]!=INT_MAX){
	        return dp[v];
	    }else{
	        return -1;
	    }
	} 
  
  // recursion
  	/*
	void fn(int i, int sum, int cnt, int coins[], int n, int v){
	    if(sum == v){
	        mincnt = min(mincnt,cnt);
	        return;
	    }
	    if(i==n || sum>v){
	        return;
	    }
	    
	    fn(i,sum+coins[i],cnt+1, coins, n ,v);
	    fn(i+1,sum+coins[i],cnt+1, coins, n ,v);
	    fn(i+1,sum,cnt, coins, n ,v);
	    fn(i,sum,cnt, coins, n ,v);
	}
19 6
7 12 2 9 5 3
39 8
9 2 11 5 14 17 8 18
	*/
	  
};
