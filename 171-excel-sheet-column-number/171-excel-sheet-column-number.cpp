class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int64_t ans =  0;
        int64_t placeValue = 1;
        int n = columnTitle.size();
        
        for(int i = n - 1; i >= 0;i--) {
            ans += (columnTitle[i] - 'A' + 1) * placeValue;
            placeValue *= 26ll;
        }
        
        return ans;
    }
};
