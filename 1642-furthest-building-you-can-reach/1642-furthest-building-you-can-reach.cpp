class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i + 1 < n; ++i) {
            int cur =  heights[i];
            int next = heights[i + 1];
            if (next > cur) {
                pq.push(next - cur);
                if (pq.size() > ladders) {
                    bricks -= pq.top();
                    pq.pop();
                }
                if (bricks < 0) {
                   return i; 
                }
            }
        }
        return n - 1;
    }
};
