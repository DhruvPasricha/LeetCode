class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        auto getPrevGreater = [&] () {
            
            vector<int> ans(n, -1);
            stack<int> st;
            
            for(int i = 0;i < n;i++) {
                
                while(st.size() and nums[st.top()] <= nums[i])
                    st.pop();
                
                if(st.size())
                    ans[i] = st.top();
                
                st.push(i);
            }
            
            return ans;
            
            
        };
        
        
        auto getNextSmaller = [&]() {
            
            
            vector<int> ans(n, -1);
            stack<int> st;
            
            for(int i = n - 1;i >= 0;i--) {
                
                while(st.size() and nums[st.top()] >= nums[i])
                    st.pop();
                
                if(st.size())
                    ans[i] = st.top();
                
                st.push(i);
            }
            
            return ans;
            
            
            
        };
        
        
        auto nextSmaller = getNextSmaller();
        auto prevGreater = getPrevGreater();
        
        int l = 0;
        int r = n - 1;
        
        while(l < n and nextSmaller[l] == -1) 
            l++;
        
        while(r >= 0 and prevGreater[r] == -1) 
            r--;
        
        
        
        return max(r - l + 1, 0);
    }
};

// next smaller to the right

// next greater to the left
