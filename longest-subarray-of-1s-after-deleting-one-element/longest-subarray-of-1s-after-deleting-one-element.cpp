class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int ans = 0;
        queue<int> q;
        vector<int> mp(2);
        
        int n = nums.size();
        for(int num : nums){
            mp[num == 1]++;
            q.push(num == 1);
            while(mp[0] >= 2){
                mp[q.front()]--;
                q.pop();
            }
            ans = max(ans, (int)q.size() - 1);
        }
        return ans;
    }
}; 