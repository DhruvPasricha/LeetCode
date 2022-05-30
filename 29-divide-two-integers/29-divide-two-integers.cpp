class Solution {
    
    int64_t solve(int64_t num, int64_t den) {
        
        if(num < den)
            return 0;
        
        int64_t temp = den;
        int64_t ans = 1;
        while(num - (den << 1ll) >= 0) {
            den <<= 1ll;
            ans <<= 1ll;
        }
        
        ans += solve(num - den, temp);
        
        return ans;
    }
    
    
    
public:
    int divide(int64_t dividend, int64_t divisor) {
        
        int64_t ans = solve(abs(dividend), abs(divisor));
        
        int64_t x = dividend ^ divisor;
        
        if(x < 0) ans = -ans;
        
        ans = min(ans, (int64_t)INT_MAX);
        ans = max(ans, (int64_t)INT_MIN);
        
        return ans;
    }
};