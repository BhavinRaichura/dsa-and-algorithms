Find the number of islands
https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:
    Input: grid = {{0,1},{1,0},{1,1},{1,0}}
    Output: 1
    Explanation:
        The grid is-
        0 1
        1 0
        1 1
        1 0
        All lands are connected.

Example 2:

    Input: grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
    Output: 2
    Expanation:
        The grid is-
        0 1 1 1 0 0 0
        0 0 1 1 0 1 0 
        There are two islands :- one is colored in blue and other in orange.

Your Task:You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as an input parameter and returns the total number of islands.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints: 1 ≤ n, m ≤ 500
*/

class Solution {
    
    vector<int>row = {1,-1,0,0,-1,-1,1,1};
    vector<int>col = {0,0,1,-1,-1,1,-1,1};  
  public:
    // Function to find the number of islands.
    
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n = grid.size(), m = grid[0].size();
        
        stack<pair<int,int>>s;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        
        int island =0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1'){
                    
                    s.push({i,j});
                    vis[i][j]=0;
                }
            }
        }
        
        
        //cout<<s.size();
        
        while(!s.empty()){
            
            
            pair<int,int>temp = s.top();
            s.pop();
            
            if(vis[temp.first][temp.second]==1)
                continue;
            
            //cout<<temp.first<<temp.second<<"  ";
            
            q.push(temp);
            
            vis[temp.first][temp.second]=1;
            island++;
            
            while(!q.empty()){
            
                auto curr = q.front();
                q.pop();
                
                int a = curr.first, b = curr.second;
                
                
                for(int i=0;i<8;i++){
                    
                    int x = a + row[i];
                    int y = b + col[i];
                    
                    if(x>=0 and y>=0 and x<n and y<m and vis[x][y]==0){
                        q.push({x,y});
                        vis[x][y]=1;
                    }
                }
            }
           
        }
        
 
        return island;
        
        
    }
};
