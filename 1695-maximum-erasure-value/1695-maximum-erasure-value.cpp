class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        queue<int> q;
        set<int> st;
        int sum = 0, ans = 0;
        for(int &x : nums) {
            while(q.size() and st.count(x)) {
                st.erase(q.front());
                sum -= q.front();
                q.pop();
            }
            sum += x;
            q.push(x);
            st.insert(x);
            ans = max(ans, sum);
        }
        return ans;
    }
};