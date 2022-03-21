class Solution {
    
    vector<int> lengthOfMergedIntervals(vector<pair<int,int>> &intervals) {
        
        vector<int> Ans;
        
        int i = 0;
        int n = intervals.size();
        
        while(i < n) {
            
            auto [l, r] = intervals[i];
            
            while(i < n and intervals[i].first <= r) {
                r = max(r, intervals[i].second);
                i++;
            }
            
            Ans.push_back(r - l + 1);
            
        }
        
        return Ans;
        
    }
    
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> firstOccurence(26, INT_MAX);
        vector<int> lastOccurence(26, INT_MIN);
        
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            
            auto &first = firstOccurence[s[i] - 'a'];
            auto &last = lastOccurence[s[i] - 'a'];
            
            first = min(first, i);
            last = max(last, i);
        }
        
        vector<pair<int,int>> intervals;
        
        for(int i = 0; i < 26; i++) {
            
            auto &first = firstOccurence[i];
            auto &last = lastOccurence[i];
            
            if(first == INT_MAX) continue;
            
            intervals.push_back({first, last});
        }
        
        sort(intervals.begin(), intervals.end());
        
        return lengthOfMergedIntervals(intervals);
    }
};

