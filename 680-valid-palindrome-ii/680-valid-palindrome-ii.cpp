class Solution {
    
    
    bool isPalindrome(string &s, int start, int end) {
        
        while(start < end and s[start] == s[end])
            start++, end--;
        
        return start >= end;
    }
    
public:
    bool validPalindrome(string s) {
        
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j and s[i] == s[j])
            i++, j--;
        
        return isPalindrome(s, i, j - 1) or isPalindrome(s, i + 1, j); 
    }
};