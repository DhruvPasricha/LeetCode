class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
           
            if(a[0] == b[0])
                return a[1] > b[1];
            
            return a[0] < b[0];
            
        });
        
        int n = intervals.size();
        int maxCoveredInRight = 0;
        int coveredIntervals = 0;
        
        for(auto &interval : intervals) {
            
            bool isCovered = maxCoveredInRight >= interval[1];
            coveredIntervals += isCovered;
            maxCoveredInRight = max(maxCoveredInRight, interval[1]);
            
        }
        
        return n - coveredIntervals;
        
    }
};