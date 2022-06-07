Combination Sum
https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1

/*
Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.

Example 1:
Input:
N = 4
arr[] = {7,2,6,5}
B = 16
Output:
    (2 2 2 2 2 2 2 2)
    (2 2 2 2 2 6)
    (2 2 2 5 5)
    (2 2 5 7)
    (2 2 6 6)
    (2 7 7)
    (5 5 6)

Example 2:
Input:
N = 11
arr[] = {6,5,7,1,8,2,9,9,7,7,9}
B = 6
Output:
    (1 1 1 1 1 1)
    (1 1 1 1 2)
    (1 1 2 2)
    (1 5)
    (2 2 2)
    (6)


Your Task:
Your task is to complete the function combinationSum() which takes the array A and a sum B as inputs and returns a list of list denoting the required combinations in the order specified in the problem description. The printing is done by the driver's code. If no set can be formed with the given set, then  "Empty" (without quotes) is printed.


Expected Time Complexity: O(X2 * 2N), where X is average of summation B/arri for every number in the array.
Expected Auxiliary Space: O(X * 2N)
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    
    void dfs(int start ,vector<int>&curr,int sum,vector<int> &arr,vector<vector<int>>&ans,int x){
            if(sum==x){
                ans.push_back(curr);
                return;
            }
            if(sum>x || start==arr.size()) return;
            
            int i=start;
            
            //including i;th element
            curr.push_back(arr[i]);
            dfs(i,curr,sum+arr[i],arr,ans,x);
                
            // without i'th element
            curr.pop_back();
            dfs(i+1,curr,sum,arr,ans,x);
            
        };
    
    vector<vector<int> > combinationSum(vector<int> &nums, int x) {

        vector<vector<int>>ans;
    
        sort(nums.begin(),nums.end());
        
        vector<int>arr;
        arr.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]!=nums[i])
                arr.push_back(nums[i]);
        }
            
        vector<int>curr;
        dfs(0,curr,0,arr,ans,x);
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends
