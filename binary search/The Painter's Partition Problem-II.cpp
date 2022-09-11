The Painter's Partition Problem-II
https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1?page=1&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions

/*
Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.

Example 1:
Input:
    n = 5
    k = 3
    arr[] = {5,10,30,20,15}
    Output: 35
    Explanation: The most optimal way will be:
    Painter 1 allocation : {5,10}
    Painter 2 allocation : {30}
    Painter 3 allocation : {20,15}
    Job will be done when all painters finish
    i.e. at time = max(5+10, 30, 20+15) = 35
    
Your task: Your task is to complete the function minTime() which takes the integers n and k and the array arr[] as input and returns the minimum time required to paint all partitions.

Expected Time Complexity: O(n log m) , m = sum of all boards' length
Expected Auxiliary Space: O(1)
*/


class Solution
{
  public:
  
    bool isDivide(long long int mid,int arr[], int n, int k){
        
        int cnt=1;
        long long int sum=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]>mid){
                return false;
            }
            
            sum+=arr[i];
            
            if(sum>mid){
                sum = arr[i];
                cnt++;
            }
            
        }
        
        if(cnt> k)
            return false;
        return true;
        
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        long long int sum =0, high=0, ans;
        long long int low=0, mid;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        
        high = sum;
        
        while(low<=high){
            
            mid = (low+high)/2;
            
            if(isDivide(mid,arr,n,k)){
                ans = mid;
                high= mid-1;
            }
            else{
                low=mid+1;
            }
            
            
        }
        
        return ans;
        
    }
};
