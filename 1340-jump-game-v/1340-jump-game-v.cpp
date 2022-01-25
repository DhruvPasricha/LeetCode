class Solution {
    #define v vector
    v<int> dp;
    
    int solve(v<int> &arr, int pos, const int &d) {
        
        if(dp[pos] != -1) return dp[pos];
        
        int ans = 0;
        int n = arr.size();
        
        for(int x = pos + 1;x  <= pos + d and x < n;x++) {
            if(arr[x] >= arr[pos]) break;
            ans = max(ans, solve(arr, x, d));
        }
        
        for(int x = pos - 1;x >= 0 and x >= pos - d;x--) {
            if(arr[x] >= arr[pos]) break;
            ans = max(ans, solve(arr, x, d));
        }
        
        return dp[pos] = 1 + ans;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        
        int n = arr.size();
        dp.assign(n, -1);
        
        int ans = 0;
        
        for(int i = 0;i < n;i++) {
            if(dp[i] == -1) {
                ans = max(ans, solve(arr, i, d));
            }
        }
        
        return ans;
    }
};