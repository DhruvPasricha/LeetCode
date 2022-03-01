class Solution {
    
    int setBits(int n) {
        
        int ans = 0;
        
        while(n) {
            n &= n - 1; 
            ans++;
        }
        
        return ans;
    }
    
    
public:
    vector<int> countBits(int n) {
        
        vector<int> Ans(n + 1);
        
        for(int i = 0; i <= n; i++) {
            Ans[i] = setBits(i);
        }
        
        return Ans;
    }
};