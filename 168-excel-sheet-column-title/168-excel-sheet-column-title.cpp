class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string ans = "";
        
        while(columnNumber > 0) {
            int rem = columnNumber % 26;
            char letter = (rem == 0) ? 'Z' : 'A' + rem - 1; 
            ans += letter;
            columnNumber -= (letter - 'A' + 1);
            columnNumber /= 26;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};