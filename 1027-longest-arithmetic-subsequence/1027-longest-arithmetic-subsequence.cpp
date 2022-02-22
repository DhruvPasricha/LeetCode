class Solution {
    
    
    int dp[501][1001];
    vector<int> mp[501]; 
    
    int solve(vector<int> &nums, int pos, int diff) {
        
        int &ans = dp[diff][pos];
        
        if(ans != -1) 
            return ans;
        
        ans = 1;
        
        int nextTerm = nums[pos] + diff;
        
        if(nextTerm <= 500) {
            auto pos_ = upper_bound(mp[nextTerm].begin(),mp[nextTerm].end(), pos);
            
            if(pos_ != mp[nextTerm].end())
                ans += solve(nums, *pos_, diff); 
        
        }
        
        return ans;
        
    }
    
    int solve(vector<int> &nums) {
        
        int n = nums.size();
        int ans = 0;        
        
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0;i <= 500;i++)
            mp[i].clear();
        
        
        for(int i = 0;i < n; i++)
            mp[nums[i]].push_back(i);
        
        for(int diff = 0; diff <= 500; diff++) {
            for(int i = 0; i < n; i++) { 
                int cur = solve(nums, i, diff);
                ans = max(ans, cur);
            }    
        }
        
        return ans;
    }
    
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int ans1 = solve(nums);
        reverse(nums.begin(), nums.end());
        int ans2 = solve(nums);
        return max(ans1, ans2);
        
    }
};
