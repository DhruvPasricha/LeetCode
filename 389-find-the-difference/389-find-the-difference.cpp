class Solution {
public:
    char findTheDifference(string s, string t) {
        
        char ans = 0;
        
        for(auto &ch : s) ans ^= ch;
        for(auto &ch : t) ans ^= ch;
        
        return ans;
    }
};