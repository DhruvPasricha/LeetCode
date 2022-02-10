class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]++;
        int ans = 0;
        int pre = 0;
        for(int &num : nums) {
            pre += num;
            ans += mp[pre - k];
            mp[pre]++;
        }
        return ans;
    }
};