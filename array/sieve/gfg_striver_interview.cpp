/*
Given N and M, find the minimum no. of primes required to make N.
  M is range of prime numbers
  
  example 1:
    input: N=10 and M=1
    output: 5
    explanation: minimum we rquired 5 primes 2+2+2+2+2=10 
                 we cannot use 5+5 =10 because then we get out of the range of prime numbers which is " M "
      
      */

class Solution{
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

    int minimumPrimes(int n, int m){

        vector<int> prime = sieve(n);
      
        vector<int>dp(n+1,INT_MAX);

        for(int i=0;i<m;i++){

            dp[prime[i]] = 1;

            for(int j=1;j<=n;j++){
                if( dp[j]!=INT_MAX and j+prime[i]<=n){
                    //cout<<dp[j]<<"  ";
                    dp[j+prime[i]] = min(dp[j+prime[i]],dp[j]+1);
                }
            }
        }
        return dp[n];
    }


};


int main(){

    Solution sol;
    cout<<endl<<sol.minimumPrimes(11,2);

    return 0;
}
