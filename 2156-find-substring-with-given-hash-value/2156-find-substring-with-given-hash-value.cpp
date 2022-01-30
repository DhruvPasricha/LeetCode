#define ll long long
class Solution {
    
    ll val(string &s, int i) {
        
        if(i < 0 or i >= s.size())
            return 0;
        
        return s[i] - 'a' + 1;
    }
    
public:
    string subStrHash(string &s, ll p, ll m, ll k, ll hashValue) {
        
        ll prev = 0;
        ll v = 1;
        ll n = s.size();
        
        for(int i = n - k;i < n;i++) {
            prev = (prev + (v * val(s, i)) % m) % m;
            v = (v * p) % m;
        }
        
        int ans = (prev == hashValue) ? n - k : n;
        
        for(int j = n - 2, i = n - k - 1; i >= 0; i--, j--) {
            
            ll cur = ((prev * p) % m - (v * val(s, j + 1)) % m) % m; // removing (j + 1) th
            cur = (cur + m) % m;
            cur = (cur + val(s, i)) % m; // including ith
            if(cur == hashValue)
                ans = i;
            prev = cur;
        }
        
        return s.substr(ans, k);
    }
};