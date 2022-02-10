class Solution {
    
    bool good(vector<int> &A, int k, int mxSum) {
        
        
        int cur = 0;
        
        for(int &x : A) {
            if(cur + x <= mxSum) {
                cur += x;
            } else if(x > mxSum){
                return false;
            }else{
                cur = x;
                k--;
            }
        }
        
        return k > 0;
    
    }
    
    
public:
    int splitArray(vector<int>& nums, int k) {
        
        int64_t l = - 1;
        int64_t r = INT_MAX;
        
        
        while(r - l > 1) {
            
            int64_t m = (l + r) / 2;
            
            
            if(good(nums, k, m))
                r = m;
            else
                l = m;
            
        }
        
        return r;
    }
};