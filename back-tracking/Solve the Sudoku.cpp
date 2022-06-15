Solve the Sudoku
https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
/*
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.
Sample Sudoku for you to get the logic for its solution:

Example 1:
Input:
      grid[][] = 
      [[3 0 6 5 0 8 4 0 0],
      [5 2 0 0 0 0 0 0 0],
      [0 8 7 0 0 0 0 3 1 ],
      [0 0 3 0 1 0 0 8 0],
      [9 0 0 8 6 3 0 0 5],
      [0 5 0 0 9 0 6 0 0],
      [1 3 0 0 0 0 2 5 0],
      [0 0 0 0 0 0 0 7 4],
      [0 0 5 2 0 6 3 0 0]]
    Output:
      3 1 6 5 7 8 4 9 2
      5 2 9 1 3 4 7 6 8
      4 8 7 6 2 9 5 3 1
      2 6 3 4 1 5 9 8 7
      9 7 4 8 6 3 1 2 5
      8 5 1 7 9 2 6 4 3
      1 3 8 9 4 7 2 5 6
      6 9 2 3 5 1 8 7 4
      7 4 5 2 8 6 3 1 9


Your Task:
You need to complete the two functions:
SolveSudoku(): Takes a grid as its argument and returns true if a solution is possible and false if it is not.
printGrid(): Takes a grid as its argument and prints the 81 numbers of the solved Sudoku in a single line with space separation.


Expected Time Complexity: O(9N*N).
Expected Auxiliary Space: O(N*N).
*/

#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0  
#define N 9  


class Solution 
{
    public:
     
    
    bool isNumPossible(int num,int r,int c,int grid[N][N]){
        
        
        for(int i=0;i<N;i++){
            if(grid[r][i]==num)
                return false;
            if(grid[i][c]==num)
                return false;
            if(grid[(3*(r/3))+(i/3)][(3*(c/3))+(i%3)]==num)
                return false;
        }
        return true;
    }
    
    bool solve(int r,int c,int grid[N][N]){
        
        if(r==N){
            return true;
        }
        
        if(c==N)
            return solve(r+1,0,grid);
        
        if(grid[r][c]==0){
            for(int k=1;k<10;k++){
                if(isNumPossible(k,r,c,grid)==1){
                    grid[r][c]=k;
                    if(solve(r,c+1,grid)){
                        return true;
                    }
                    grid[r][c]=0;
                }
            }
        }
        else if(solve(r,c+1,grid))
            return true;
        
        return false;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return solve(0,0,grid);
        
        
        
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
            
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends
