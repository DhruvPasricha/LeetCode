class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        int n = differences.size();
        vector<int64_t> A(n);
        A[0] = differences[0];
        for(int i = 1;i < n;i++) {
            A[i] = differences[i];
            A[i] += A[i - 1];
        }
        
        int64_t mn = *min_element(A.begin(), A.end());
        int64_t mx = *max_element(A.begin(), A.end());
        
        if(mx < 0) mx = 0;
        if(mn > 0) mn = 0;
        
        mn = (int64_t)lower - mn;
        mx = (int64_t)upper - mx;
        
        if(mn > mx) return 0;
        
        return mx - mn + 1;
        
    }
};