// first lady of software

/*

Grace Hopper is widely known as the "First Lady of Software." She is primarily known for helping to create the first all-electrical digital computer: UNIVAC (Universal Automatic Computer). NASA's tracking stations for the Apollo moon missions used UNIVAC hardware to communicate with the astronauts.
While developing UNIVAC, one of Hopper's tasks was to come up with a process synchronization solution for ensuring that the never-ending processes must suffer a bounded wait. A never- ending process is defined as a process that never completes. For this, she devised an algorithm wherein one process cannot occupy consecutive time slots.
To estimate the algorithm performance, Hopper needed to find the number of ways to allocate n_processes in n_intervals at different time intervals by obeying the algorithm. Since the number of ways can be very large, return the answer in modulo 109+7.

Example
  Suppose that n processes = 2 and n_intervals = 3. The schedule allocation can look like (A, B, A) or (B, A, B).
  Answer: 2

Note: all the processes are never-ending, so even if n_intervals are very large, the processes will not be complete.

Function Description
  Complete the function findNumberOfWays in the editor below. findNumberOfWays has the following parameters:
    n_intervals, an integer representing distinct time intervals
    n_processes; an integer representing the number of processes
    Result: integer 
*/

// formula = !(n_processes) * pow(n_processes-1, n_intervals- n_processes);

// solution
#include <bits/stdc++.h>
using namespace std;

int solution(int  n_processes, int n_intervals){
    if( n_processes > n_intervals)
        return 0;
    int mod = 1000000007;
    long long int ans = 1;
    for(int i=2;i<=n_processes;i++){
        ans *= i;
        ans %= mod;
    }
    if(n_processes < n_intervals){
        ans *= pow(n_processes-1, n_intervals- n_processes);
        ans %= mod;
    }
    return ans;
}

int main() {
    
    int n_processes, n_intervals;
    cout<<"\nn_precesses: ";
    cin>>n_processes;
    cout<<"\nn_intervals: ";
    cin>>n_intervals;
    cout<<"\nAns "<<solution( n_processes, n_intervals);

    return 0;
}
    
