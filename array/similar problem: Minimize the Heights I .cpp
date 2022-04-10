// GFG
// similar problem: Minimize the Heights I 
// https://practice.geeksforgeeks.org/problems/minimize-the-heights-i/1/#

/*
    similer problem: Minimize the Heights II 
    https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

    article: https://www.geeksforgeeks.org/how-to-find-the-minimum-and-maximum-element-of-an-array-using-stl-in-c/
*/


/*
Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once.
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.
Note: Assume that height of the tower can be negative.
A slight modification of the problem can be found here. 


Example 1:
    Input:
    K = 2, N = 4
    Arr[] = {1, 5, 8, 10}
    Output:5
    Explanation:
    The array can be modified as 
    {3, 3, 6, 8}. The difference between 
    the largest and the smallest is 8-3 = 5.

Example 2:
    Input:
    K = 3, N = 5
    Arr[] = {3, 9, 12, 16, 20}
    Output:11
    Explanation:
    The array can be modified as
    {6, 12, 9, 13, 17}. The difference between 
    the largest and the smallest is 17-6 = 11. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function getMinDiff() which takes the arr[], n and k as input parameters and returns an integer denoting the minimum difference.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(N)
*/


#include <bits/stdc++.h>
using namespace std;


class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int ans=arr[n-1]-arr[0];
       int mi,ma;
       for(int i=1;i<n;i++)
       {
           mi=min(arr[0]+k,arr[i]-k);
           ma=max(arr[i-1]+k,arr[n-1]-k);
           ans=min(ans,ma-mi);
       }
       return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  
