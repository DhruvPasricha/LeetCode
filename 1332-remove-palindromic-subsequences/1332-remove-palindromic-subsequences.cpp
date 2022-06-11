class Solution {
public:
    int removePalindromeSub(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        if(temp == s)
            return 1;
        return 2;
    }
};
