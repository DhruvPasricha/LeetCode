class Solution {
    
    const int64_t mod = 1e9 + 7;
    map<int,int> mp;
    
    int64_t twoSum(int target) {
        
        int64_t ans = 0;
        
        for(auto &it : mp) {
            
            int cur = it.first;
            int rem = target - cur;
            
            if(cur == rem)
                continue;
            
            if(mp.count(rem)) {
                ans = (ans + (int64_t)it.second * (int64_t)mp[rem]) % mod; 
            }
        }
        
        ans /= 2;
        
        if(target % 2 == 0 and mp.count(target / 2)) {
            
            int64_t f = mp[target / 2];
            
            ans = (ans + (f * (f - 1)) / 2) % mod;
        }
        
        return ans;
        
    }
    
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int64_t ans = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            ans += twoSum(target - arr[i]);
            ans %= mod;
            mp[arr[i]]++;
        }
        
        return ans;
    }
};
