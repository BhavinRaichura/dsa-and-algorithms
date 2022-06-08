79. Word Search
https://leetcode.com/problems/word-search/

/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:
    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board and word consists of only lowercase and uppercase English letters.

*/
class Solution {
    bool found =0;
public:
    
    void searchWord(int r,int c,int start,vector<vector<char>>& arr, string word,int m,int n){
        if(start == word.size()){
            found=1;
            return;
        }
        if(r>=m || c>=n || r<0 || c<0 || arr[r][c]!=word[start]) return;
        
        char ch = arr[r][c];
            
        if(arr[r][c]== word[start]){
            start++;
            arr[r][c] = '0';
        }
        else 
            start =0;
        
        
        
        searchWord(r+1,c,start,arr,word,m,n);
        searchWord(r-1,c,start,arr,word,m,n);
        searchWord(r,c+1,start,arr,word,m,n);
        searchWord(r,c-1,start,arr,word,m,n);
        
        arr[r][c] = ch;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                searchWord(i,j,0,board,word,m,n);
                if(found) return found;
            }
        }
        return found;
    }
};
