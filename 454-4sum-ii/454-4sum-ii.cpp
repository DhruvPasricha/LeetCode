class Solution {
    
    void generateAllPairSum(vector<int> &A, vector<int> &B, unordered_map<int, int> &freq) {
        
        for(int &a : A)
            for(int &b : B)
                freq[a + b]++;
        
    }
    
    
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        
        unordered_map<int,int> A;
        unordered_map<int,int> B;
        
        generateAllPairSum(nums1, nums2, A);
        generateAllPairSum(nums3, nums4, B);
        
        int ans = 0;
        
        for(auto &a : A) 
            ans += (a.second * B[-a.first]);
        
        return ans;
    }
};