// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    int dp[501][501];
    
    
    bool isPalindrome(string &s, int left, int right) {
        
        while(left < right)
            if(s[left++] != s[right--])
                return false;
        
        return true;
    }
    
    int solve(string &s, int left, int right){
        
        if(left > right)
            return 1000;
            
        int &ans = dp[left][right];
        
        if(ans == -1 and isPalindrome(s, left, right))
            ans = 0;
        
        if(ans != -1)
            return ans;
        
        ans = 1000;
        
        for(int i = left;i < right;i++) {
            
            int leftAns = solve(s, left, i);
            int rightAns = solve(s, i + 1, right);
            
            int cur = leftAns + rightAns + 1;
            
            ans = min(ans, cur);
        }
            
        return ans;
        
        
        
    }
    
public:
    int palindromicPartition(string str)
    {
        
        memset(dp, -1, sizeof(dp));
        
        return solve(str, 0, str.length() - 1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends