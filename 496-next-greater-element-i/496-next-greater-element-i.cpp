class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        
        int n = nums2.size();
        vector<int> nextGreater(1e4 + 1, -1);
        
        stack<int> st;
        
        for(int i = n - 1;i >= 0;i--) {
            
            while(st.size() and st.top() <= nums2[i])
                st.pop();
            
            if(st.size())
                nextGreater[nums2[i]] = st.top();
            
            st.push(nums2[i]);
            
        }
        
        vector<int> Ans = nums1;
        
        for(int &x : Ans)
            x = nextGreater[x];
        
        return Ans;
        
    }
};