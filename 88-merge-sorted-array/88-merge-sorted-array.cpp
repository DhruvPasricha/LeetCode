class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        vector<int> merged(m + n);
        
        int i = 0;
        int j = 0;
        
        while(i < m or j < n) {
            
            int option1 = (i < m) ? nums1[i] : INT_MAX;
            int option2 = (j < n) ? nums2[j] : INT_MAX;
            
            if(option1 <= option2) {
                merged[i + j] = option1;
                i++;
            }
            else {
                merged[i + j] = option2;
                j++;
            }
        }
        
        nums1 = merged;
    }
};