class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        vector<int> freq(1001, 0);
        
        for(int x : nums1)
            freq[x]++;
        
        for(int x : nums2)
            if(freq[x])
                freq[x]--, ans.push_back(x);
        
        return ans;

    }
};