class Solution {
    // nums[i] : k > 0  | nums[i] + k
    //                    nums[i] - k 
    //         : k = 0  | nums[i]
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(int &num : nums)    
            mp[num]++;
    
        int ans = 0;
        
        for(auto &itr : mp) {
            int req = itr.first + k;
            if(req == itr.first) 
                ans += itr.second > 1;
            else if(mp.count(req)) 
                ans++;
        }
        
        return ans;    
    }
};