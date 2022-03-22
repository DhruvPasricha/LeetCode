class Solution {
    
    int weight(char ch) {
        return ch - 'a' + 1;
    }
    
public:
    string getSmallestString(int n, int k) {
        
        string ans = "";
        
        for(int i = 0; i < n; i++) {
            
            for(char ch = 'a'; ch <= 'z'; ch++) {
                
                int rem = k - weight(ch);
                
                if(rem <= 26 * (n - i - 1)) {
                    ans += ch;
                    k -= weight(ch);
                    break;
                }
            }
        }
        
        return ans;
    }
};