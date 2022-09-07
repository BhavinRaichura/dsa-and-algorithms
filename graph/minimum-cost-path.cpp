// https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1?page=4&status[]=unsolved&curated[]=1&sortBy=submissions
// minimum-cost-path
// BFS -solution

/*

Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). 

Note: It is assumed that negative cost cycles do not exist in the input matrix.
 
Example 1:
    Input: grid = {{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}}
    Output: 43
    Explanation: The grid is-
        9 4 9 9
        6 7 6 4
        8 3 3 7
        7 4 9 10
        The minimum cost is- 9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.

Your Task: You don't need to read or print anything. Your task is to complete the function minimumCostPath() which takes grid as input parameter and returns the minimum cost to react at bottom right cell from top left cell.
 
Expected Time Compelxity: O(n2*log(n))
Expected Auxiliary Space: O(n2) 
 

*/

class Solution
{
    vector<int>row={-1,1,0,0};
    vector<int>col={0,0,-1,1};
    
    int n,m;
    
    public:
   
   
    bool issafe(int x, int y){
        if(x<0 || y<0 || x>=m || y>=n )
            return 0;
        return 1;
    }
	
	
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        
        m= grid.size();
        n= grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> heap;
        
        heap.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        
        
        while(!heap.empty()){
            auto curr = heap.top();
            heap.pop();
            
            int a=curr.second.first;
            int b = curr.second.second;
            int dist = curr.first;
             
             if(a==m-1 and b==n-1){
                 return dist; 
             }
            
            
            for(int i=0;i<4;i++){
                
                a=curr.second.first;
                b = curr.second.second;
                
                a+= row[i];
                b+= col[i];
                
                
                if(issafe(a,b)){
                    if(vis[a][b]==0){
                        heap.push({dist+grid[a][b],{a,b}});
                        
                    }
                    
                    vis[a][b]=1;
                }
                
               
            }
           
        }
        
        return -1;
    }
};
