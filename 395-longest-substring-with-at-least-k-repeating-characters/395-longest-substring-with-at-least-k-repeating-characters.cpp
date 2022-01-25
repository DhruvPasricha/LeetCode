class Solution {
    
    int solve(string &s, int l, int r, int k) {
        
        if(l > r)
            return 0;
    
        vector<int> freq(26);
        
        for(int i = l;i <= r;i++)
            freq[s[i] - 'a']++;
        
        int count = 0;
        for(int i = 0;i < 26;i++)
            if(freq[i] > 0 and freq[i] < k)
                freq[i] = -1, count++;
        
        if(count == 0)
            return r - l + 1;
        
        int i = l;
        int ans = 0;
        
        while(i <= r) {
            
            while(i <= r and freq[s[i] - 'a'] == -1)
                i++;
            
            int left = i; 
            
            while(i <= r and freq[s[i] - 'a'] > 0)
                i++;
            
            int right = i - 1;
            
            ans = max(ans, solve(s, left, right, k));
            
        }
        
        return ans;
    }
    
    
    
public:
    int longestSubstring(string s, int k) {
        
        int n = s.size();
        int ans = solve(s, 0, n - 1, k);
        return ans;
    }
};