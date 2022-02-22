// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
class Solution 
{
    vector<int> solve(Job A[], int n) {

        pair<int,int> dp[2][101];
        
        for(int pos = n; pos >= 0;pos--) {
            
            for(int taken = 100; taken >= 0;taken--) {
            
                pair<int,int> &ans = dp[pos & 1][taken];
                
                if(pos == n or taken == 100)
                    ans.first = 0, ans.second = taken;
                else {
                    
                    ans = dp[(pos + 1) & 1][taken];
                    
                    if(taken < A[pos].dead) {
                        pair<int,int> ans2 = dp[(pos + 1) & 1][taken + 1];
                        ans2.first += A[pos].profit;
                        if(ans2.first > ans.first)
                            ans = ans2;
                    }
                }
            }
            
        }
        
        vector<int> ans(2);
        
        ans[0] = dp[0][0].second;
        ans[1] = dp[0][0].first;
        
        return ans;
        
    }
    
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        
        sort(arr, arr + n, [&](Job &a, Job &b){
            return a.dead < b.dead;
        });
        
        return solve(arr, n);
    } 
};


 
// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends