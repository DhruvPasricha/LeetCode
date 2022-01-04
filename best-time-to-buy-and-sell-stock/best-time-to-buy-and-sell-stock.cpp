class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minPrice = INT_MAX;
        for(auto &price : prices) {
            minPrice = min(minPrice, price);
            ans = max(ans, price - minPrice);
        }
        return ans;
    }
};