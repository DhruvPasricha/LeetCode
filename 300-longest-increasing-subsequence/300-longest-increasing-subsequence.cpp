class Solution {
    map<int,int> mp;
    int ans = 0;
    void insert(int x) {
        
        if(mp.count(x)) return;
        
        auto itr = mp.upper_bound(x);
        
        if(itr == mp.end()) {
            itr--;
            mp[x] = itr->second + 1;   
        } else {
            int cur = itr->second;
            mp.erase(itr);
            mp[x] = cur;
        }
        ans = max(ans, mp[x]);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        mp[INT_MIN] = 0;
        vector<int> LIS;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            insert(nums[i]);
        }
        return ans;
    }
};

// 1 2 -1 10 100



// 1 -> 1
// 2 -> 2

// -1 -> 1
