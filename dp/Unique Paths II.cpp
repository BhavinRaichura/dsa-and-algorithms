leetcode: 63. Unique Paths II
https://leetcode.com/problems/unique-paths-ii/

DP + Backtracking solution

/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
  Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
  Output: 2
  Explanation: There is one obstacle in the middle of the 3x3 grid above.
    There are two ways to reach the bottom-right corner:
    1. Right -> Right -> Down -> Down
    2. Down -> Down -> Right -> Right

Example 2:
  Input: obstacleGrid = [[0,1],[0,0]]
  Output: 1
*/

class Solution {
    int cnt=0;
public:

//------------------------------------------------------------------------------backtracking solutionn--------------------------------------------------------
    // backtracking
    
    bool isSafe(int r, int c,int n,int m,vector<vector<int>>& arr ){
        if(r>=n|| c>=m || arr[r][c]==1) 
            return false;
        return true;
    }
    
    void findPath(int r, int c, int n,int m,vector<vector<int>>& arr){
        
        if(r==n-1 and c==m-1 and isSafe(r,c,n,m,arr)){
            cnt++;
            return;
        }
        if(isSafe(r,c,n,m,arr)){
            arr[r][c]=1;
            findPath(r+1,c,n,m,arr);
            findPath(r,c+1,n,m,arr);
            arr[r][c]=0;
        }
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        findPath(0,0,obstacleGrid.size(),obstacleGrid[0].size(),obstacleGrid);
        return cnt;
    }
    
 //---------------------------------------------------------------------------------DP Solution------------------------------------------------------
    // dp - memoization
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){

        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int left =0,up =0;
        
        // base case
        dp[0][0]=1;
        
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
            
                left =0,up =0;
                
                // base case
                if(i==0 and j==0){
                    continue;
                }
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                
                // iterative cases
                if(j>=1){
                    left+= dp[i][j-1];
                }
                if(i>=1){
                    up +=dp[i-1][j];
                }
                
                dp[i][j]=left+up;
            }
        }
        return dp[n-1][m-1];
    }
    
    
};

