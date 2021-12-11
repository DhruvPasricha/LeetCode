class Solution {
    int64_t LCM;
    int64_t mod = 1e9 + 7;
public:
    
    int64_t gcd(int64_t a,int64_t b)
    {
        return (b == 0) ? a : gcd(b, a%b);
    }
    
    
    int64_t g(int64_t x,int64_t a, int64_t b)
    {
        return x/a + x/b - x/LCM;
    }
    
    
    int64_t f(int n, int a, int b)
    {
        int64_t l = 0;
        int64_t r = n + 1;
        
        while(r - l > 1)
        {
            int64_t m = (l + r) >> 1ll;
            
            if(g(m * a, a, b) <= n) l = m;
            else r = m;
        }
        
        return l;
    }
    
    int64_t nthMagicalNumber(int n, int a, int b) {
        if(a < b) swap(a, b);    
        LCM = (a / gcd(a, b)) * b;
        int64_t ans = f(n, a, b);
        ans *= a;
        if(g(ans, a, b) == n) return ans % mod;
        ans = f(n, b, a);
        ans *= b;
        return ans % mod;
    }
};
