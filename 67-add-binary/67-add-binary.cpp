class Solution {
public:
    string addBinary(string a, string b) {
        
        string ans = "";
        int n1 = a.length();
        int n2 = b.length();
        int carry = 0;
        
        while(n1 > 0 or n2 > 0 or carry) {
            
            int bit1 = (n1 > 0) ? a[n1 - 1] - '0' : 0;
            int bit2 = (n2 > 0) ? b[n2 - 1] - '0' : 0;
            int resultantBit = (bit1 + bit2 + carry) % 2;
            carry = (bit1 + bit2 + carry) / 2;
            
            ans += (char)(resultantBit + '0');
            n1--;
            n2--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};