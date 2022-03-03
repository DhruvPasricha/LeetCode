class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        
        int i = 0;
        int n = t.size();
        
        for(char ch : s) {
            
            while(i < n and t[i] != ch)
                i++;
            
            if(i == n)
                return false;
            else
                i++;
        
        }
        
        return true;
    }
};