0 - 1 Knapsack Problem 
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/?page=1&difficulty[]=0&difficulty[]=1&difficulty[]=2&category[]=Dynamic%20Programming&sortBy=submissions#

/*

You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Example 1:
    Input:
    N = 3
    W = 4
    values[] = {1,2,3}
    weight[] = {4,5,1}
    Output: 3

Example 2:
    Input:
    N = 3
    W = 3
    values[] = {1,2,3}
    weight[] = {4,5,6}
    Output: 0

Your Task: Complete the function knapSack() which takes maximum capacity W, weight array wt[], value array val[], and the number of items n as a parameter and returns the maximum possible value you can get.

Expected Time Complexity: O(N*W).
Expected Auxiliary Space: O(N*W)

Constraints:
    1 ≤ N ≤ 1000
    1 ≤ W ≤ 1000
    1 ≤ wt[i] ≤ 1000
    1 ≤ v[i] ≤ 1000
    
    */
class Solution
{
    //int maxVal = INT_MIN;
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       
       //fn(0,0,0,W,wt,val,n);
       //return maxVal;
       
        vector<int>dp(W+1,0),temp(W+1,0);
        
        
        for(int i=0;i<n;i++){
            if(wt[i]<=W)
                // here the error occurse 
                    // because i was updating this value without comparing with previous value
                // It needs to choose maximum value between previous value as per weight and given value 
                dp[wt[i]] = max(temp[wt[i]],val[i]);
            for(int j=0;j<=W;j++){
                if(temp[j]>0 and j+wt[i]<=W){
                    dp[j+wt[i]]=max(dp[j+wt[i]],temp[j]+val[i]);
                }
                //cout<<dp[j]<<"  ";
            }
            //cout<<endl;
            temp= dp;
        }
        int cnt =0;
        
        for(int i=0;i<=W;i++){
            cnt=max(cnt,dp[i]);
        }
        
        return cnt;
    }
    /*
    
    //---- backtracking
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        if(W==0 || n==0)
            return 0;
        if(wt[n-1]>W){
            return knapSack(W,wt,val,n-1);
        }
        return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
    }
    
    */
    
    /*
    //--- recursive approach
    
    void fn(int i, int cnt, int value, int W, int wt[], int val[], int n) 
    { 
       if(i>n || cnt>W) return;
       
       maxVal = max(maxVal, value);
       
       fn(i+1,cnt+wt[i],value+val[i],W,wt,val,n);
       fn(i+1,cnt,value,W,wt,val,n);
       
    }
    */
    
    
    
};
