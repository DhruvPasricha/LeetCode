class Solution {
    
    bool isLowerCase(char ch) {
        return ch >= 'a' and ch <= 'z';
    }
    
public:
    bool detectCapitalUse(string word) {
        
        int n = word.size();
        
        int lowerCase = 0;
        int upperCase = 0;
        
        for(int i = 1;i < n;i++) 
            if(isLowerCase(word[i])) 
                lowerCase++;
            else 
                upperCase++;
        
        
        if(isLowerCase(word[0])) 
            return lowerCase == n - 1;
        
        
        return lowerCase == n - 1 or upperCase == n - 1;
        
        
    }
};