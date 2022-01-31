class Solution {
    int getWealth(vector<int> &arr) {
        int wealth = 0;
        for(auto &itr : arr) 
            wealth += itr;
        return wealth;
    }
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(auto &account : accounts) {
            int wealth = getWealth(account);
            ans = max(ans, wealth);
        }
        return ans;
    }
};