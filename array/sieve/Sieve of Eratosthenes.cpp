// Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number. 
  /*
    Input : n =10
    Output : 2 3 5 7 

    Input : n = 20 
    Output: 2 3 5 7 11 13 17 19
   */


#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
  vector<int>sieve(int n){
        vector<int>ans;

        vector<bool>prime(n+1,true);

        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for (int j = i*i; j <= n; j += i)
                    prime[j] = false;

            }
        }

        for (int p = 2; p <= n; p++) {
            if (prime[p]) {
                ans.push_back(p);
                //cout << p << " ";
            }
        }

        return ans;

    }

};

int main(){
  
    Solution sol;

    vector<int>arr = sol.sieve(30);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"    ";
    }
    return 0;

}
