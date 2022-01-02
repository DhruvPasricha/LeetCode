class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& nums) {
        int ans = 0;
        map<int,int> mp;
        for(int &num : nums) {
            int m = num % 60;
            int l = (60 - m) % 60;
            ans += mp[l];
            mp[m]++;
        }
        return ans;
    }
};

