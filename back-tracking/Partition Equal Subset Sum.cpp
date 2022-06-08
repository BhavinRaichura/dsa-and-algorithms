Partition Equal Subset Sum 
https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:
Input: N = 4
  arr = {1, 5, 11, 5}
  Output: YES
  Explanation:  The two parts are {1, 5, 5} and {11}.

Example 2:
Input: N = 3
  arr = {1, 3, 5}
  Output: NO
  Explanation: This array can never be partitioned into two such parts.

Your Task: You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.

Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)
*/

class Solution{
    
public:
    
    bool isEqualToMid(int pos,int sum,int a[],int n,int mid){
        if(sum == mid){
            return true;
        }
        if(pos>=n || sum > mid) return false;
        
        if(isEqualToMid(pos+1,sum+a[pos],a,n,mid))
            return true;
        
        return isEqualToMid(pos+1,sum,a,n,mid);
        
    }
    
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum= 0;
        
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        if(sum%2==1){
            return 0;
        }
        
        int mid = sum/2;
        
        return isEqualToMid(0,0,arr,N,mid);
     }
     
};
