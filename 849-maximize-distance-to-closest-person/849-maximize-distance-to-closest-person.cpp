class Solution {
    vector<int> pre;
    vector<int> suf;
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        
        pre.assign(n, -1e6);
        suf.assign(n, 1e6);
        
        for(int i = 0;i < n;i++) {
            if(seats[i] == 1) {
                pre[i] = i;
            } else if(i > 0) {
                pre[i] = pre[i-1];
            }
        }
        
        for(int i = n - 1;i >= 0;i--) {
            if(seats[i] == 1) {
                suf[i] = i;
            } else if(i < n - 1) {
                suf[i] = suf[i+1];
            }
        }
        
        int ans = 0;
        
        for(int i = 0;i < n;i++) {
            
            if(seats[i] == 1) continue;
            
            int l = i - pre[i];
            int r = suf[i] - i;
            
            ans = max(ans, min(l, r));
        }
        return ans;
    }
};