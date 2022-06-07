
N-Queen Problem
https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1


/*
The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].

Example 1:
Input: 1
Output: [1]
Explaination: Only one queen can be placed in the single cell available.

Example 2:

Input: 4
Output: [2 4 1 3 ] [3 1 4 2 ]
Explaination: These are the 2 possible solutions.

Your Task: You do not need to read input or print anything. Your task is to complete the function nQueen() which takes n as input parameter and returns a list containing all the possible chessboard configurations in sorted order. Return an empty list if no solution exists.

Expected Time Complexity: O(n!)
Expected Auxiliary Space: O(n2) 
*/

// ------------------------------------------------------------------------- method -1
// time:  n! (it required extra time for checking the position is safe or not because we have used 3 while loop)
#include <bits/stdc++.h>
using namespace std;


class Solution{
    vector<vector<int>>ans;
public:

    bool isSafe(int row, int col,int n,vector<vector<int>>&arr ){

        if(row ==n || col==n) return false;

        int i=row,j=col;

        // checking all left-side columns in a row
        while(j>=0){
            if(arr[i][j]==1){
                return false;
            }
            j--;
        }
        
        i=row;j=col;
        
        // checking top-left-diagonal
        while(j>=0 && i>=0){
            if(arr[i][j]==1){
                return false;
            }
            j--;
            i--;
        }

        i=row;j=col;
        
        //checking for bottom-left-diagonal
        while(j>=0 && i<n){
            if(arr[i][j]==1){
                return false;
            }
            j--;
            i++;
        }

        return true;

    }

    void queenPos(int col,vector<int>&curr,int n ,vector<vector<int>>&arr){

        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        if(col >= arr.size()) return;

        for(int row =0;row<n;row++){
            if(isSafe(row,col,n,arr)){
                arr[row][col]=1;
                curr.push_back(row+1);
                queenPos(col+1,curr,n,arr);
                arr[row][col]=0;
                curr.pop_back();

            }
        }
        return;

    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>arr(n,vector<int>(n,0));
        vector<int>curr;
        queenPos(0,curr,n,arr);


        return ans;
    }
};
