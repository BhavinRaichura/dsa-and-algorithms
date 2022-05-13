//gfg

// Maximum sum of absolute difference of any permutation
// https://www.geeksforgeeks.org/maximum-sum-absolute-difference-array/

// swap and Maximize
// https://practice.geeksforgeeks.org/problems/swap-and-maximize5859/1

/*
Given an array a[ ] of N elements. Consider array as a circular array i.e. element after an is a1. The task is to find maximum sum of the absolute difference between consecutive elements with rearrangement of array elements allowed i.e. after any rearrangement of array elements find |a1 – a2| + |a2 – a3| + …… + |an-1 – an| + |an – a1|.

Example 1:
Input:
N = 4
a[] = {4, 2, 1, 8}
Output: 
18
Explanation: Rearrangement done is {1, 8, 
2, 4}. Sum of absolute difference between 
consecutive elements after rearrangement = 
|1 - 8| + |8 - 2| + |2 - 4| + |4 - 1| = 
7 + 6 + 2 + 3 = 18.

Example 2:
Input:
N = 2
a[] = {10, 12}
Output: 
4

Your Task:
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function maxSum() that takes array a[ ] and its size N as input parameters and return the maximum sum using above method.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    vector<int>array;
    int i =0,j=n-1;
    
    for (i =0 ;i<n/2;i++){
        array.push_back(arr[i]);
        array.push_back(arr[j]);
        j--;
    }
    if (n%2==1){
        array.push_back(arr[j]);
    }
    int ans=0;
    int val=0;
 
    i=0;
    for(i ; i<n;i++){
        if (i+1==n){
            val = array[i] - array[0];
            ans+=val;
            break;
        }
        
        val = array[i+1]-array[i];
        
        if (val<0){
            val=val*(-1);
        }
        
        ans += val;
    }
    return ans;
    
}

