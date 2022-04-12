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
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        for (int i =0;i<matrix.size();i++){
            if(matrix[i][n-1]>=target){
                int j =0;
                while(j<n){
                    if(matrix[i][j]==target)
                        return true;
                    j++;
                }
                break;
            }
        }
        return false;
    }
};


