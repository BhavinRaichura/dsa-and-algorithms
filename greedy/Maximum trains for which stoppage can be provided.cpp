Maximum trains for which stoppage can be provided
https://www.codingninjas.com/codestudio/problems/maximum-trains-for-which-stoppage-can-be-provided_1169456?leftPanelTab=0
/*
You are given the ‘n’ number of trains and ‘m’ number of a platform for a station. Every train has an associate with ‘arrival time’, ‘departure time’, and ‘platform’ number.
Your task is to determine the maximum number of trains for which you can provide a stoppage at the station.
You can provide stoppage to only one train at platform ‘x’ between ‘arrival time’ to ‘departure time’ of the current train.
If ‘arrival time’ and ‘departure time’ is 1015 then consider as 10:15.

The first line of each test case contains two space-separated integers ‘n’ and ‘m’, where ‘n’ denotes the number of trains and ‘m’ denotes the number of platforms.
Next ‘n’ lines contain three space-separated integers ‘arrival time’, ‘departure time’, and ‘platform’ number.

Task : You do not need to print anything; it has already been taken care of. Just implement the given function.

Where ‘T’ represents the number of test cases, ‘N’ is the number of trains, ‘M’ is the number of platforms, and ‘Arrival Time’ and ‘Departure Time’ is ‘HH:MM’ time of arrival and departure time of trains.

Sample Input 1:

  2
    5 2
    0950 1005 1
    1000 1030 1
    1015 1030 1
    1200 1205 2
    1215 1230 2
    4 1
    1200 1210 1
    1205 1220 1
    1215 1230 1
    1215 1240 1

Sample Output 1:
    4
    2

*/

#include <bits/stdc++.h>

int maxStop(vector<vector<int>> &trains, int n, int m)
{
    // trains ( arrival_time,dept_time, plateform_no )
    sort(trains.begin(),trains.end(),[](vector<int>a,vector<int>b){
       if(a[2]==b[2])
           return a[1]<b[1];
       return a[2]<b[2];
    });
    
    // suppose we always include the 1st train
    int cnt =1;
    int prev = 0;

    for(int i =1; i<n; i++){
        if(trains[prev][2] == trains[i][2]){
            if(trains[prev][1]<=trains[i][0]) {
                cnt++;
                prev = i;
            }
        }
        else{
            cnt++;
            prev = i;
        }

    }

    return cnt;
}
