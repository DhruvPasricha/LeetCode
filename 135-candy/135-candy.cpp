class Solution {
public:
    int candy(vector<int>& A) {
        int n = A.size();
        vector<int> pre(n, 1), suf(n, 1);
        for(int i = 1; i < n; ++i) 
            if(A[i] > A[i - 1])
                pre[i] = 1 + pre[i - 1];
        for(int i = n - 2; i >= 0; --i)
            if(A[i] > A[i + 1])
                suf[i] = 1 + suf[i + 1];
        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans += max(pre[i], suf[i]);
        return ans;
    }
};
