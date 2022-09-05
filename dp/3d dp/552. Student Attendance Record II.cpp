leetcode: https://leetcode.com/problems/student-attendance-record-ii/
552. Student Attendance Record II
/*
An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

    'A': Absent.
    'L': Late.
    'P': Present.

Any student is eligible for an attendance award if they meet both of the following criteria:

    The student was absent ('A') for strictly fewer than 2 days total.
    The student was never late ('L') for 3 or more consecutive days.

Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

 

Example 1:
    Input: n = 2
    Output: 8
    Explanation: There are 8 records with length 2 that are eligible for an award:
    "PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
    Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).

Example 2:
    Input: n = 1
    Output: 3

Constraints:  1 <= n <= 105

*/

class Solution {
    int cnt=0;
    int d = 1000000007;
public:
    
    int find(int n, int a, int l,vector<vector<vector<int>>>&dp){
        if(a>1 || l>2)
            return 0;
            
        if(n==0){
            //cout<<s<<"   ";  
            return 1;
        }
        
        if(dp[n][a][l]!=-1){
            return dp[n][a][l]%d;
        }
        
        dp[n][a][l] = find(n-1,a,0,dp)%d;
        
        if(a==0)
            dp[n][a][l] = ( dp[n][a][l]%d + find(n-1,a+1,0,dp)%d)%d;
        
        if(l<2)
            dp[n][a][l] = ( dp[n][a][l]%d + find(n-1,a,l+1,dp)%d)%d;
        
        return dp[n][a][l]%d;
        
    }
    
    int checkRecord(int n) {
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return dp[n][0][0]=find(n,0,0,dp)%d;
    }
};
