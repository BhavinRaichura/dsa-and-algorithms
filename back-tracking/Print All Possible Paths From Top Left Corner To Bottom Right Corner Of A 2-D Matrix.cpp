Print All Possible Paths From Top Left Corner To Bottom Right Corner Of A 2-D Matrix 
https://www.codingninjas.com/codestudio/problems/print-all-possible-paths-from-top-left-corner-to-bottom-right-corner-of-a-2-d-matrix_1171152?leftPanelTab=0
/*

You are given an ‘M*N’ Matrix, You need to print all possible paths from its top left corner to the bottom right corner if given that you can either move right i.e from (i,j) to (i,j+1) or down i.e from (i, j) to (i+1, j).
For Example :
    1 2 3
    4 5 6
For the above 2*3 matrix , possible paths are (1 2 3 6) , (1 2 5 6) , (1 4 5 6).

Note : You can return the paths in any order.
Input Format : The first line contains two space-separated integers, ‘M’ and ‘N’ denoting the number of rows and columns of the given matrix. Each of the following ‘M’ lines contains N space-separated numbers.
Output Format : Print all the paths in a new line.
Note : You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints : 1 <= M, N <= 10

Sample Input 1 :
      2 2
      1 2 
      3 4
  Sample Output 1 :
      1 3 4
      1 2 4
  Explanation Of Sample Input 1 : All the possible paths on moving right and down are (1 3 4) and (1 2 4).

Sample Input 2 :
      3 2
      5 10 
      15 20
      25 30
  Sample Output 2 :
      5 15 25 30
      5 15 20 30
      5 10 20 30

*/


void searchPath(int row,int col,vector<int>&curr,vector<vector<int>>&arr,int n,int m,vector<vector<int>>&ans){

        if(row >=n|| col>=m) return;

        curr.push_back(arr[row][col]);

        if(row==n-1 and col ==m-1){
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        searchPath(row+1,col,curr,arr,n,m,ans);
        searchPath(row,col+1,curr,arr,n,m,ans);
        curr.pop_back();
}

vector<vector <int> > printAllpaths(vector<vector<int> > & mat , int m , int n)
{
    vector<vector<int> >ans;
    vector<int>curr;
    searchPath(0,0,curr,mat,m,n,ans);
    return ans;
}
