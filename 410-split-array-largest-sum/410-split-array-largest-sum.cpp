class Solution {
    
    
    bool good(vector<int> &A, int k, int x) {
        
        
        int cur = 0;
        int n = A.size();
        
        for(int i = 0; i < n; i++) {
            
            if(cur + A[i] > x) {
                cur = 0;
                k--;
            }
            
            cur += A[i];
            
            if(cur > x) return false;
            
        }
        
        return k >= 0;
        
    }
    
    
public:
    int splitArray(vector<int>& nums, int k) {
        
        int l = -1;
        int r = 1e9;
        
        
        while(r - l > 1) {
            
            int m = l + (r - l) / 2;
            
            if(good(nums, k - 1, m))
                r = m;
            else
                l = m;
            
        }
        
        return r;
    }
};
