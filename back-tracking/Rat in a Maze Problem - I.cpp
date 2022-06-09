Rat in a Maze Problem - I
https://practice.geeksforgeeks.org/problems/rotate-matrix-elements-clockwise2336/1/?page=3&difficulty[]=0&difficulty[]=1&curated[]=1&sortBy=submissions

error solved : // every time we needs to block previous path,
                      m[x][y]=0;
               // otherwise code will goes to infinity loop
               // and after the process will done we clear the path       
                      m[x][y]=1;



/*

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:
Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output: -1
Explanation: No path exists and destination cell is blocked.

Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    bool isSafe(vector<vector<int>> &m,int x,int y, int n){
        if(x<n and y<n and x>=0 and y>=0 and m[x][y]==1) return true;
        return false;
    }
    
    
    void path(vector<vector<int>> &m,int x,int y, int n,vector<string> &ans,string& ch){
        
        if(x<0 || y<0 || x>=n || y>=n || m[x][y]==0 ) return;
        
        if(x==n-1 and y==n-1){
            ans.push_back(ch);
            return;
        }
        
        if(isSafe(m,x,y,n)){
            
          
            // it's is blocking current path till this 
            m[x][y]=0;
            
          
          // for left right up and down notation
            ch+="D";
            path(m,x+1,y,n,ans,ch);
            ch.pop_back();
            
            ch+="R";
            path(m,x,y+1,n,ans,ch);
            ch.pop_back();
            
            ch+="L";
            path(m,x,y-1,n,ans,ch);
            ch.pop_back();
            
            ch+="U";
            path(m,x-1,y,n,ans,ch);
            ch.pop_back();
            
            // back tracking 
          // it's is openning the blocked path 
            m[x][y]=1;

        }
        return;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[n-1][n-1]==0) return {};
        
        vector<string> ans;
        
        string ch ="";
        
        path(m,0,0,n,ans,ch);
        
        
        
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
