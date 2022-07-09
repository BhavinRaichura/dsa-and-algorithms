Groovy's Walk
/*
Problem Description
Groovy likes to have moming walks daily. He walks on an Ax A matrix from start to finish The start is at the top left cell of the matrix and the end is at the bottom right cell. He can only ever walk downwarts or nightwards. That is from the cell (1), he can only go to (l+1,1) or (1, j+1). He cannot go out of bounds of the array A is guaranteed to be an odd integer But there is a problem, night at the centre of the matrix, there is a machine set up that produces a toxic gas that has spread to B outer rings apart from the center cell That is to say if I then all calls adjacent to the centre block, excluding
which touch it on comers the whole outer ringl are also toxic Your task is to determine the number of ways Groovy has, to reach the ending block from the starting block while avoiding the toxic cells. Since the number can be very large output it monu 197 For example, if A-5 and 8-1, the grid will took like: 10 are passable cells while X are toxic cells)
  0 0 0 0 0
  0 x x x 0
  0 x x x 0
  0 x x x 0
  0 0 0 0 0

Problem Constraints
  A is guaranteed to be odd
  3<=A<=1e5
  0<=B<=|A/2|-1 where | | stands for foor of value

Input Format
  The fest argument is the integer A 
  Second argument the anger B

Output Format
  Return a single integer per the green problem
*/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    int cnt =0;
    
  public:
  
    void findPath(int i,int j, int n, vector<vector<int>>&arr){
        if(i==n-1 && j== n-1){
            cnt++;
            return;
        }
        else if(i>=n || j>=n || arr[i][j]==0)
            return;
            
        arr[i][j]=0;
        findPath(i+1,j,n,arr);
        findPath(i,j+1,n,arr);
        arr[i][j]=1;
        
    }
    
    void blockPath(int n,int b,vector<vector<int>>&arr){
        int r =0;
        if(n%2==1)
            r=n/2;
        else
            r=n/2 +1;
            
        arr[r][r] =0;
        
        while(b>0){
            arr[r][r+1] = 0;
            arr[r][r-1]=0;
            arr[r+1][r]=0;
            arr[r-1][r]=0;
            arr[r-1][r-1]=0;
            arr[r-1][r+1]=0;
            arr[r+1][r+1]=0;
            arr[r+1][r-1]=0;
            b--;
        }
        
        
    }
    
    int cntPath(int n, int b){
        vector<vector<int>>arr(n,vector<int>(n,1));
        blockPath(n,b,arr);
        findPath(0,0,n,arr);
        return cnt;
        
    }
    
};



int main() {
    // Write C++ code here
    Solution s;
    int n,b;
    cout<<"enter size of matrix 'n' and machine range 'b' : ";
    cin>>n>>b;
    cout<<endl;
    cout<<s.cntPath(n,b);

    return 0;
}
