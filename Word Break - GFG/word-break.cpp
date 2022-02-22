// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
        
    unordered_set<string> st;
        
    int dp[1101];
        
    int solve(string &s, int pos) {
        
        int n = s.size();
        
        if(pos == s.size()) 
            return 1;
        
        int &ans = dp[pos];
        
        if(ans != -1)
            return  ans;
        
        ans = 0;
        
        string cur = "";
        
        // cut at i if possible
        
        for(int i = pos; i < n; i++) {
            
            cur += s[i];
            
            if(st.count(cur)) {
                ans += solve(s, i + 1);
            }
        }
        
        return ans;
        
    }
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        for(auto b : B)
            st.insert(b);
        
        memset(dp, -1, sizeof(dp));
        
        return solve(A, 0);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends