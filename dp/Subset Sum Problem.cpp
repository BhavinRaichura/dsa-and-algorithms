Subset Sum Problem 
https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/?page=1&category[]=Dynamic%20Programming&sortBy=submissions#

/*
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

Example 1:
    Input:
    N = 6
    arr[] = {3, 34, 4, 12, 5, 2}
    sum = 9
    Output: 1 
    Explanation: Here there exists a subset with
    sum = 9, 4+3+2 = 9.

Example 2:
    Input:
    N = 6
    arr[] = {3, 34, 4, 12, 5, 2}
    sum = 30
    Output: 0 
    Explanation: There is no subset with sum 30.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isSubsetSum() which takes the array arr[], its size N and an integer sum as input parameters and returns boolean value true if there exists a subset with given sum and false otherwise.
The driver code itself prints 1, if returned value is true and prints 0 if returned value is false.

Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum*N)
 
Constraints:
1 <= N <= 100
1<= arr[i] <= 100
1<= sum <= 105
*/


class Solution{ 
    
public:
  
    // backtracking
    /*
    bool findSubset(int i, int add,vector<int>&arr, int sum){
        if(i >= arr.size()) return false;
        if(add == sum) return true;
        return (findSubset(i+1,add+arr[i],arr,sum) || findSubset(i+1,add,arr,sum));
    }
    */
  
    // DP - Tabulation with space optimization
    bool isSubsetSum(vector<int>arr, int sum){
        // recusive call
        //return findSubset(0,0,arr,sum);
        
        vector<bool>dp(sum+1,0),temp(sum+1,0);
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>sum){
                    continue;
                }
            dp[arr[i]]=1;
            
            for(int j=0;j<=sum;j++){
                
                if(temp[j]==1){
                    //dp[j]=1;
                    
                    if(arr[i]+j <=sum)
                        dp[arr[i]+j]=1;
                        
                    //cout<<arr[i]+j<<"  ";
                }
                
            }
            temp = dp;
        }
        
        return dp[dp.size()-1];
        
    }
};
