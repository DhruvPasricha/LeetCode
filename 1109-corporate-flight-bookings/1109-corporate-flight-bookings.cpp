class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int> Ans(n);
        
        for(auto &booking : bookings) {
            int l = booking[0] - 1;
            int r = booking[1];
            int v = booking[2];
            Ans[l] += v;
            if(r < n) Ans[r] -= v;
        }
        
        for(int i = 1;i < n;i++) 
            Ans[i] += Ans[i - 1];
        
        return Ans;
    }
};