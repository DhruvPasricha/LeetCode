class Solution {
    
    int dp[601][101][101];
    
    int solve(vector<vector<int>> &arr, int n, int zero, int one) {
        
        if(n == 0)
            return 0;
        
        int &ans = dp[n][zero][one];
        
        if(ans != -1)
            return ans;
        
        ans = solve(arr, n - 1, zero, one);
        
        if(arr[n - 1][0] <= zero and arr[n - 1][1] <= one)
            ans = max(ans, 1 + solve(arr, n - 1, zero - arr[n - 1][0], one - arr[n - 1][1]));
        
        return ans;
       
    }
    
    vector<int> getCount(string &s) {
        
        vector<int> ans(2);
        
        for(char &ch : s)
            ans[ch - '0']++;
        
        return ans;
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        
        memset(dp, -1, sizeof(dp));
        
        vector<vector<int>> arr;
        
        for(string &str : strs) 
            arr.push_back(getCount(str));
        
        int ans = solve(arr, arr.size(), m, n);
        
        return ans;
    }
};