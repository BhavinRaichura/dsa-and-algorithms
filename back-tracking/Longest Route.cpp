// Longest Route 
https://www.codingninjas.com/codestudio/problems/longest-route_1170525?leftPanelTab=0

/*

You are given a 2-D binary matrix "Mat" of dimensions N x M consisting only of 0s and 1s. The cell consisting of 0 means that the cell is blocked and it cannot be visited whereas a cell with 1 as a value means it can be visited.
You are given a source cell and a destination cell. You need to find the length of the longest possible path from source to destination, given you can only move in 4 possible directions north(i.e from (i,j) to (i-1,j)), south(i.e from (i,j) to (i+1,j)), east(i.e from (i,j) to (i,j-1)), and west(i.e from (i,j) to (i,j+1)), and without visiting a cell twice.

Note: 1. If the move isn’t possible you remain in that cell only.

Input Format:
The first line of the input contains two space-separated integers 'N' and ‘M’, denoting the number of rows and columns of the matrix respectively.
Next, there will be N lines each containing M space-separated integers denoting the description of the matrix.
The next line contains two space-separated integers ‘Sx’, ‘Sy’ denoting the indexes of the source cell
The next line contains two space-separated integers ‘Dx’, ‘Dy’ denoting the indexes of the destination cell

Output Format: If a path exists then print the length of the longest possible path from source to destination. Otherwise, print -1.

Note : You do not need to print anything, it has already been taken care of. Just implement the given function.


Sample Input 1:
    3 3
    1 1 0
    0 1 1
    1 0 1
    0 0
    2 2
    Sample Output 1: 4
    Explanation for Sample Input 1: The only and longest path is  :  (0,0) -> (0,1) -> (1,1) -> (1,2) -> (2,2) 

Sample Input 2:
    3 3
    0 1 0
    0 1 1
    1 0 1
    0 0
    2 2
    Sample Output 2: -1


*/


void findLongestPath(vector<vector<int>>&arr,int i,int j, int ipos,int jpos,int n,int m,int &ans,int cnt){

    if(i>=n || j>=m || i<0 || j<0 || arr[i][j]==0) return;

    cnt+=1;
    if(i==ipos && j== jpos){
        ans = max(ans,cnt);
        return;
    }

    arr[i][j]=0;

    findLongestPath(arr, i+1, j, ipos, jpos,n,m,ans,cnt);       // right
    findLongestPath(arr, i, j+1, ipos, jpos,n,m,ans,cnt);       // bottom
    findLongestPath(arr, i, j-1, ipos, jpos,n,m,ans,cnt);       // top
    findLongestPath(arr, i-1, j, ipos, jpos,n,m,ans,cnt);       // left

    arr[i][j]=1;

}

int longestPath(int n, int m, vector<vector<int>> &mat, int sx, int sy, int dx, int dy) {
	// Write your code here
    int ans=0;
    findLongestPath(mat, sx,sy, dx, dy,n,m,ans,0);
    return ans-1;
}

