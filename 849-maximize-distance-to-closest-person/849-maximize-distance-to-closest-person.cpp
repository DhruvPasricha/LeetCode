class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        
        int prev = -1e6;
        
        for(int i = n - 1;i >= 0;i--) {
            if(seats[i] == 1) {
                seats[i] = i;
            } else if(i < n - 1) {
                seats[i] = seats[i + 1];
            } else {
                seats[i] = 1e6;
            }
        }
        
        int ans = 0;
        
        for(int i = 0;i < n;i++) {
            
            if(seats[i] == i){ 
                seats[i] = 1;
                prev = i;
                continue;
            }
            int l = i - prev;
            int r = seats[i] - i;
            
            ans = max(ans, min(l, r));
            
            seats[i] = 0;
        }
        return ans;
    }
};

