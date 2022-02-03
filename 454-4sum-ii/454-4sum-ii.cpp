class Solution {
    
    vector<int> getAllPairSum(vector<int> &A, vector<int> &B) {
        
        vector<int> Ans;
        
        for(int &a : A)
            for(int &b : B)
                Ans.push_back(a + b);
        
        return Ans;
        
    }
    
    
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        
        vector<int> A = getAllPairSum(nums1, nums2);
        vector<int> B = getAllPairSum(nums3, nums4);
        
        unordered_map<int, int> mp;
        
        for(int &b : B) mp[b]++;
        
        int ans = 0;
        
        for(int &a : A) ans += mp[-a];
        
        return ans;
    }
};