class Solution {
    
    set<int> nums;
    map<int, int64_t> dp;
    const int64_t mod = 1e9 + 7;
    
    int64_t solve(int x) {
        
        if(dp.count(x))
            return dp[x];
        
        int64_t ans = 1;
        
        for(int64_t i = 2;i * i <= x;i++) {
            
            if(x % i == 0) {
                
                int f1 = i;
                
                int f2 = x / i;
                
                if(nums.count(f1) == 1 and nums.count(f2) == 1) {
                    
                    int64_t cur =  (solve(f1) * solve(f2)) % mod;
                    ans = (ans + cur) % mod;
                    if(f1 != f2)
                        ans = (ans + cur) % mod;
            
                }
                
            }
            
        }
        
        return dp[x] = ans;
        
        
    }
    
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        for(int num : arr)
            nums.insert(num);
        
        int64_t ans = 0;
        
        for(int num : nums) {
            ans = (ans + solve(num)) % mod;
        }
        
        return ans;
    }
};