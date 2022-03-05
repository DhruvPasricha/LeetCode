class Solution {
    
    vector<int> dp;
    vector<pair<int,int>> arr;
    map<int, int> mp;
        
    int solve(int pos) {
        
        if(pos == arr.size())
            return 0;
        
        int &ans = dp[pos];
        
        if(ans != -1)
            return dp[pos];
        
        int ans1 = solve(pos + 1);
        
        int nextPos = pos + 1;
        
        if(pos + 1 < arr.size() and arr[pos + 1].first == arr[pos].first + 1)
            nextPos++;
        
        int ans2 = arr[pos].first * arr[pos].second + solve(nextPos);
        
        
        return ans = max(ans1, ans2);
        
    }
    
    
public:
    int deleteAndEarn(vector<int>& nums) {
        
        for(int &num : nums)
            mp[num]++;
        
        for(auto &itr : mp)
            arr.push_back({itr.first, itr.second});
        
        dp.assign(arr.size(), -1);
        
        int ans = solve(0);
        
        return ans;
        
    }
};
