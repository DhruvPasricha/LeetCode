class Solution {
    
    const int mod = 1e9 + 7;
    
    void calculate(vector<int> &nums, int start, int finalValue, int step, vector<int> &Ans, function<bool(int, int)> f) {
        
        int n = nums.size();
        int defaultValue = (step == 1) ? -1 : n;
        Ans.assign(n, defaultValue);
        stack<int> st;
        for(int i  = start; i != finalValue; i += step) {
            
            while(st.size() > 0 and f(nums[st.top()], nums[i])) st.pop();
            
            if(st.size() > 0) Ans[i] = st.top();
            st.push(i);
        }
    }
    
    
public:
    int sumSubarrayMins(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> prevSmaller;
        vector<int> nextSmallerOrEqual;
    
        calculate(nums, 0, n, 1, prevSmaller, [](int a, int b)->bool {return a >= b;});
        calculate(nums, n - 1, -1, -1, nextSmallerOrEqual, [](int a, int b)->bool {return a > b;});
        
        int64_t ans = 0;
        for(int i = 0;i < n; i++) {
            int64_t minContribution = (int64_t)(i - prevSmaller[i]) * (int64_t)(nextSmallerOrEqual[i] - i);
            int64_t netContribution = (minContribution) * nums[i];
            ans = (ans + netContribution) % mod;
        }
       
        return  ans;
    }
};