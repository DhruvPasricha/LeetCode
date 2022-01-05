class Solution { 
    bool isIntersecting(vector<int> &a, vector<int> &b) {
        return a[1] >= b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<int> prev(2);
        prev[0] = intervals[0][0];
        prev[1] = intervals[0][1];
        vector<vector<int>> Ans;
        for(int i = 1;i < n;i++) {
            if(isIntersecting(prev, intervals[i])) {
                prev[1] = max(prev[1], intervals[i][1]);
            } else {
                Ans.push_back(prev);
                prev = intervals[i];
            }
        }
        Ans.push_back(prev);
        return Ans;
    }
};