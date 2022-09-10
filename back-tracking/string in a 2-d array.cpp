Count occurences of a given word in a 2-d array
https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1
/*
Find the number of occurrences of a given search word in  a 2d-Array of characters where the word can go up, down, left, right and around 90 degree bends.


Example 1:
Input: 
    R = 4, C = 5
    mat = {{S,N,B,S,N},
           {B,A,K,E,A},
           {B,K,B,B,K},
           {S,E,B,S,E}}
    target = SNAKES
    Output: 3
    Explanation: 
    S N B S N
    B A K E A
    B K B B K
    S E B S E
    Total occurrence of the word is 3 and denoted by color.

Example 2:
Input:
    R = 3, C = 3 
    mat = {{c,a,t},
           {a,t,c},
           {c,t,a}}
    target = cat
    Output: 5
    Explanation: Same explanation as first example.


Your task: You dont need to read input or print anything. Your task is to complete the function findOccurrence() which takes the mat contaning N*M 2-d array of character and target as input parameters and returns thethe number of occurrences of target.


Expected Time Complexity: O(R*C*22*len), Where len is length of target String.
Expected Auxiliary Space: O(1)

*/

class Node{
    public:
    int i, j , pos;
    
    Node(int a,int b ,int c){
        i=a;
        j=b;
        pos=c;
    }
    
};

class Solution{
    
    int n,m;
    
    vector<int> row ={0,0,1,-1};
    vector<int>col = {1,-1,0,0};
    
    public:

    bool issafe(int x, int y, int pos, vector<vector<int>>&vis,vector<vector<char> > &mat,string target){
        if(x<0 || y<0 || x>=n || y>=m || pos>=target.size() || target[pos]!=mat[x][y] || vis[x][y]==1){
            return 0;
        }
        return 1;
    }
    
    int dfs(int x, int y, int pos, vector<vector<int>>&vis,vector<vector<char> > &mat,string target){
        if(pos==target.size()-1){
            return 1;
        }
        
        int ans=0;
        
        for(int i=0;i<4;i++){
            
            if(issafe(row[i]+x,col[i]+y, pos+1,vis,mat,target)){
                vis[row[i]+x][col[i]+y] =1;
                
                ans+=dfs(row[i]+x,col[i]+y, pos+1,vis,mat,target);
                
                vis[row[i]+x][col[i]+y] =0;
            }
        }
        return ans;
            
        
    }
    
    int findOccurrence(vector<vector<char> > &mat, string target){
        
        stack<pair<int,int>>s;
        queue<Node>q;
        
        n = mat.size();
        m= mat[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==target[0]){
                    s.push({i,j});
                }
            }
        }
        
        int cnt= 0;
        
        //cout<<s.size();
        
        while(!s.empty()){
            auto curr = s.top();
            s.pop();
            
            
            vis[curr.first][curr.second]=1;
            
            cnt+= dfs(curr.first, curr.second,0,vis,mat,target);
            vis[curr.first][curr.second]=0;
        }
        
       
        return cnt;
        
        
    }
};
