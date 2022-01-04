class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int64_t> Pre(n);
        stack<int64_t> st;
        Pre[0] = nums[0];
        for(int i = 1;i < n;i++) Pre[i] = Pre[i-1] + nums[i];
        st.push({0});
        map<int64_t,int> mp;
        mp[0] = -1;
        int ans = INT_MAX;
        for(int i = 0;i < n;i++) {
            int64_t req = Pre[i] - k;
            auto itr = mp.upper_bound(req);
            if(itr != mp.begin()) {
                itr--;
                ans = min(ans, i - itr->second);
            }
            int64_t cur = Pre[i];
            while(st.size() > 0 and cur <= st.top()) {
                mp.erase(st.top());
                st.pop();
            }
            st.push(cur);
            mp[cur] = i;
        }
        return (ans != INT_MAX) ? ans : -1;
    }
};