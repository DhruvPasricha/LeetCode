class Solution {
public:
    
    
    int insert(map<int,int> &mp, int x){
        if(mp.count(x)) return mp[x];
        
        auto itr = mp.lower_bound(x);
        
        if(itr != mp.begin()) itr--;
        int cur = 1 + itr->second;
        
        if(itr != mp.end()) itr++;
        
        if(itr != mp.end()){
            if(itr->second == cur) mp.erase(itr);
        }
        
        return mp[x] = cur;
    } 
    
    
    int lengthOfLIS(vector<int>& nums) {
     
        map<int,int> mp;
        int ans = 0;
        mp[INT_MIN] = 0;
        for(int num : nums){
            ans = max(ans, insert(mp, num));
        }
        return ans;
    }
};

// 10 -> 1
    