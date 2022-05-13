// gfg
//  Job Sequencing Problem 
// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

error
// Isme ek condition missed ho gayi hai
// isme jo job me profit jyada hai vo job priority ke sath hogi but
// agar kisi job ki deadline near hai aur us time pr koi aur job ki current deadline nahi hai to 
// jiski deadline near hai use pahele complete kr sakta hu bhale uska profit km ho   




class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        stack<pair<int,int>>st;
        vector<pair<int, int>> a;
        for (int i=0;i<n;i++){
            a.push_back({arr[i].profit,arr[i].dead});
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        int cnt =0;

        for (int i=0;i<n;i++){
            
            if(!st.empty()){
                if (cnt < a[i].second){
                    st.push(a[i]);
                    cnt++;
                    
                }
            }
            else{
                st.push(a[i]);
                cnt++;
            }
            
            
        }
        vector<int>ans(2);
        ans[0]=0;
        ans[1]=0;

        while(!st.empty()){
            ans[0]++;
            ans[1]+=st.top().first;
            st.pop();
        }
         

        return ans;

    }
};

