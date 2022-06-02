
#include <bits/stdc++.h>
using namespace std;



class Solution{
    public:
    
    bool isSafe(vector<vector<int>> &m,int x,int y, int n){
        if(x<n and y<n and m[x][y]==1) return true;
        return false;
    }
    
    
    bool path(vector<vector<int>> &m,int x,int y, int n,vector<vector<int>> &ans){
        
        if(x==n-1 and y==n-1){
            ans[x][y]=1;
            return true;
        }
        
        if(isSafe(m,x,y,n)){
            ans[x][y]=1;
            if(path(m,x+1,y,n,ans)){
                return true;
            }
            if(path(m,x,y+1,n,ans)){
                return true;
            }
            ans[x][y]=0;
            return false;
        }
        return false;
    }
    
    
    vector<vector<int>> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> ans(n, vector<int> (n,0));
        
        path(m,0,0,n,ans);
        
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        
        Solution obj;
        vector<vector<int>> result = obj.findPath(m, n);
  
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<result[i][j]<<"   ";
            }
            cout<<endl;
        }
        
        
    }
    return 0;
}  // } Driver Code Ends
