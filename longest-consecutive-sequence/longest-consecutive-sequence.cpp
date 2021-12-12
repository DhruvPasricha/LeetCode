class Solution {
public:
    
    int solve(map<int,int> &mp, int x){
        if(mp.count(x) == 0) return 0;
        if(mp[x] != -1) return mp[x];
        return mp[x] = 1 + solve(mp, x + 1);
    }
    
    
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        for(int num : nums) mp[num] = -1;
        for(int num : nums) if(mp[num] == -1) solve(mp, num);
        int ans = 0;
        for(auto itr : mp) ans = max(ans, itr.second);
        return ans;
    }
};