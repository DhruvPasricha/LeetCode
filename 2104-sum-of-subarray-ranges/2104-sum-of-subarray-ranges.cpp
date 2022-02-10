class Solution {
   
    void calculate(vector<int> &nums, int start, int end, vector<int> &Ans, function<bool(int, int)> f) {
        
        int n = nums.size();
        int step = 1;
        int defaultValue = -1;
        int finalValue = n;
        if(start > end) {
            step = -1;
            defaultValue = n;
            finalValue = -1;
        }
        Ans.assign(n, defaultValue);
        stack<int> st;
        for(int i  = start; i != finalValue; i += step) {
            
            while(st.size() > 0 and f(nums[st.top()], nums[i])) st.pop();
            
            if(st.size() > 0) Ans[i] = st.top();
            st.push(i);
        }
    }
    
    
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> prevSmaller, prevGreater;
        vector<int> nextSmallerOrEqual, nextGreaterOrEqual;
    
        calculate(nums, 0, n - 1, prevSmaller, [](int a, int b)->bool {return a >= b;});
        calculate(nums, 0, n - 1, prevGreater, [](int a, int b)->bool {return a <= b;});
        calculate(nums, n - 1, 0, nextSmallerOrEqual, [](int a, int b)->bool {return a > b;});
        calculate(nums, n - 1, 0, nextGreaterOrEqual, [](int a, int b)->bool {return a < b;});
        
        int64_t ans = 0;
        for(int i = 0;i < n; i++) {
            
            int64_t minContribution = (int64_t)(i - prevSmaller[i]) * (int64_t)(nextSmallerOrEqual[i] - i);
            int64_t maxContribution = (int64_t)(i - prevGreater[i]) * (int64_t)(nextGreaterOrEqual[i] - i);
            
            int64_t netContribution = (maxContribution - minContribution) * nums[i];
            ans += netContribution;
        }
       
        return  ans;
    }
};