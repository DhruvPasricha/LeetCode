class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        queue<int> q;
        map<int,int, greater<int>> mp;
        int ans = -1e5;
        for(int i = 0;i < n;i++){
            int cur = nums[i];
            auto itr = mp.begin();
            if(itr != mp.end()) {
                cur = max(cur, cur + itr->first);
            }
            mp[cur]++;
            q.push(cur);
            if(q.size() > k) {
                mp[q.front()]--;
                if(mp[q.front()] == 0) mp.erase(q.front());
                q.pop();
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};