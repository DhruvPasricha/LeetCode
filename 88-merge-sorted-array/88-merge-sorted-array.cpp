class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while(k >= 0) {
            
            int option1 = (i >= 0) ? nums1[i] : INT_MIN;
            int option2 = (j >= 0) ? nums2[j] : INT_MIN;
            
            if(option1 >= option2) {
                nums1[k] = option1;
                i--;
            }
            else {
                nums1[k] = option2;
                j--;
            }
            
            k--;
        }
    }
};