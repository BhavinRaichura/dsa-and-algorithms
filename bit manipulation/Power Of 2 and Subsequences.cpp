Power Of 2 and Subsequences
https://practice.geeksforgeeks.org/problems/power-of-2-and-subsequences0759/1
/*
Given is an array A[] of size N. Return the number of non-empty subsequences such that the product of all numbers in the subsequence is Power of 2. Since the answer may be too large, return it modulo 109 + 7.

Example 1:
    Input:
    N = 3
    A[] = {1, 6, 2}
    Output: 3
    Explanation: The subsequence that an be chosen is {1}, {2} and {1,2}.

Example 2:
    Input:
    N = 3
    A[] = {3, 5, 7}
    Output: 0
    Explanation:  No subsequences exist.

Your Task:  You don't need to read input or print anything. Your task is to complete the function numberOfSubsequences() which takes an integer N and an array A and returns the number of subsequences that exist. As this number can be very large return the result under modulo 109+7.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

class Solution{   
public:

    bool ispowoftwo(long long num){
        if(num & (num-1))
            return false;
        return true;
    }
    long long numberOfSubsequences(int N, long long A[]){
        // code here 
        
        long long cnt =0;
        int mod = 1000000007;
        
        for(int i=0;i<N;i++){
            if(ispowoftwo(A[i])){
                cnt = ((cnt%mod) + 1)%mod;
            }
        }
        
        
        long long ans=1;
        for(int i=0;i<cnt;i++)
            ans = (ans * 2)%mod;
            
        return ans-1;
        
        
    }
};
