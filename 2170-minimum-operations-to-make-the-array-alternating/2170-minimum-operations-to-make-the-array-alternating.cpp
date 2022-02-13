class Solution {
    
    void f(map<int, int> &mp, int &mx, int &sm) 
    {
        for(auto itr : mp)
            if(mp.count(mx) == 0)
                mx = itr.first;
            else if(itr.second >= mp[mx]) {
                sm = mx;
                mx = itr.first;
            } else if(mp.count(sm) == 0 or itr.second > mp[sm])
                sm = itr.first;
    }
public:
    int minimumOperations(vector<int>& nums) {
        
        map<int, int> mp1;
        map<int, int> mp2;
        
        int len1 = 0;
        int len2 = 0;
        
        int n = nums.size();
        
        for(int i = 0;i < n; i+= 2)
            mp1[nums[i]]++, len1++;
        
        for(int i = 1;i < n; i+= 2)
            mp2[nums[i]]++, len2++;
        
        
        int mx1 = -1;
        int sm1 = -1;
        int mx2 = -1;
        int sm2 = -1;
        
        f(mp1, mx1, sm1);
        f(mp2, mx2, sm2);
        
        int ans = n;
        
        // mx1, mx2
        if(mx1 != mx2) {
            ans = len1 - mp1[mx1] + len2 - mp2[mx2];
        } else{
            // mx1, sm2
            int ans1 = len1 - mp1[mx1] + len2 - mp2[sm2];
            // sm1, mx1
            int ans2 = len1 - mp1[sm1] + len2 - mp2[mx2];
            ans = min(ans1, ans2);
        }
        
        return ans;

        

        
    }
};