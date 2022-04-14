
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void prm(string s, int n,vector <string> &permutStr){
  
  // base condition 
    if (n==1){
        permutStr.push_back(s);
        return ;
    }
  
  // recursive condition 
    int len = s.size();
  
    for(int i=len-n;i<len;i++){
        char temp = s[len-n];
        s[len-n]=s[i];
        s[i]=temp;
      
      // check if permutation is already exist or not in vector
        if (std::find(permutStr.begin(),permutStr.end(),s)!=permutStr.end())
            continue;
      
       // if permutation is not exist in vector then we continue
        prm(s,n-1,permutStr);
    }
}

vector <string> find_permutations(string s){
  
    vector <string> permutStr;
  
    prm(s,s.size(),permutStr);
  
    sort(permutStr.begin(),permutStr.end());
      
    return permutStr;
}


int main(){
    vector <string> permutStr;
    string s1= "abba";
  
    permutStr=find_permutations(s1);
  
    cout<<"size  "<<permutStr.size()<<endl;
  
  //print vector
    for (int i =0 ;i<permutStr.size();i++){
        cout<<permutStr[i]<<"     ";
}
