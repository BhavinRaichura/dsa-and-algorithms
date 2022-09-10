// leetcode
// 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/
/*

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

Example 1:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true
      
Example 2:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false

      
*/
class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        // code here 
        
        int i=0 , j= m-1;
        while(i<n and j>=0){
            if(matrix[i][j]==x)
                return 1;
            else if(matrix[i][j]<x){
                i++;
            }
            else{
                j--;
            }
        }
        return 0;
    }
};
