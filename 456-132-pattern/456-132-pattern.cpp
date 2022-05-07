class Solution {
    
    
    vector<int> getPrevGreater(vector<int> &nums) {
        
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        
        for(int i = 0;i < n; i++) {
            
            while(st.size() and nums[st.top()] <= nums[i])
                st.pop();
            
            if(st.size())
                ans[i] = st.top();
            
            st.push(i);
        }
        
        return ans;
        
    }
    
    
    
    vector<int> getFirstSmaller(vector<int> &nums) {
        
        int n = nums.size();
        vector<int> seq;
        vector<int> ans(n, -1);
        
        for(int i = 0;i < n; i++) {
            
            int l = -1;
            int r = seq.size();
            
            while(r - l > 1){
                
                int m = (l + r) / 2;
                
                if(nums[seq[m]] < nums[i])
                    r = m;
                else
                    l = m;
                
            }
            
            if(r == seq.size())
                seq.push_back(i);
            else
                ans[i] = seq[r];
            
        }
        
        return ans;
        
    }
    
    
public:
    bool find132pattern(vector<int>& nums) {
        
        auto prevGreater = getPrevGreater(nums);
        auto firstSmaller = getFirstSmaller(nums);
        
        int n = nums.size();
        bool ans = false;
        
        for(int k = 0; k < n; k++)
        {
            int j = prevGreater[k];
            int i = firstSmaller[k];
            
            if(i == -1 or j == -1) 
                continue;
            
            ans = ans or (i < j and j < k);
        }
        
        return ans;
    }
};