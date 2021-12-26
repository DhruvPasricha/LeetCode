#define node pair<int,vector<int>>
#define dist(x, y) (x*x) + (y*y)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<node, vector<node>> pq;
        
        for(auto &point : points) {
            int d = dist(point[0], point[1]);
            pq.push({d, point});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> Ans;
        while(pq.size() > 0) {
            Ans.push_back(pq.top().second);
            pq.pop();
        }
        return Ans;
    }
};