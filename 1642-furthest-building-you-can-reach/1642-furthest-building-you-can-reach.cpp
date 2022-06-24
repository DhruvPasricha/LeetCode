class Solution {
    
    bool good(vector<int> &heights, int k, int bricks, int ladders) { 
        int cur = INT_MAX;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; ++i) {
            int next = heights[i];
            if(next > cur) {
                pq.push(next - cur);
            }
            cur = next;
        }
        while(pq.size() > ladders) {
            bricks -= pq.top();
            if(bricks < 0)
                return false;
            pq.pop();
        }
        return true;
    }
    
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int l = 0;
        int r = heights.size() + 1;
        
        while(r - l  > 1) {
            
            int m = (l + r) >> 1;
            
            if(good(heights, m, bricks, ladders))
                l = m;
            else
                r = m;
        }
        return l - 1;
    }
};