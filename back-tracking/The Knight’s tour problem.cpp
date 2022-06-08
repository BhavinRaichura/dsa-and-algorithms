The Knight’s tour problem

/*

Problem Statement:
Given a N*N board with the Knight placed on the first block of an empty board. Moving according to the rules of chess knight must visit each square exactly once. Print the order of each cell in which they are visited.

Example:
Input : 
  N = 8
  Output:
      0  59  38  33  30  17   8  63
      37  34  31  60   9  62  29  16
      58   1  36  39  32  27  18   7
      35  48  41  26  61  10  15  28
      42  57   2  49  40  23   6  19
      47  50  45  54  25  20  11  14
      56  43  52   3  22  13  24   5
      51  46  55  44  53   4  21  12

*/

#define n 8

class Solution{

public:

    bool isSafe(int i,int j,vector<vector<int>>&arr){
        return (i<n && j<n && i>=0 && j>=0 && arr[i][j]==-1);

    }

    bool searchPath(int x,int y,int cnt, int total,vector<vector<int>>&arr,vector<int>xMove,vector<int> yMove){

        if(cnt == total){
            return 1;
        }
        
        int next_x;
        int next_y;
        
        for(int k=0;k<8;k++){
            next_x = x + xMove[k];
            next_y = y + yMove[k];
            if (isSafe(next_x, next_y, arr)) {
                arr[next_x][next_y] = cnt;
                
                if (searchPath(next_x, next_y, cnt+ 1,total, arr,xMove, yMove)==1)
                    return 1;
                else
                    // backtracking
                    arr[next_x][next_y] = -1;
            }
        }
        return 0;
    }



    int knightPath(){
        vector<vector<int>>arr(n,vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                arr[i][j] = -1;
            }

        }

        vector<int> xMove{ 2, 1, -1, -2, -2, -1, 1, 2 };
        vector<int> yMove{ 1, 2, 2, 1, -1, -2, -2, -1 };

        arr[0][0]=0;
        
        bool f =searchPath(0,0,1,n*n,arr,xMove,yMove);

        cout<<"\n\n---------------------------------------\n\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<"\t";

            }
            cout<<endl;
        }

        if(f)
            return 1;

        return 0;
    }



};

int main(){


    Solution ob;

    cout<<endl<<endl<<ob.knightPath();
    return 0;
}
