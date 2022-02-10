class Solution {
    
    void solve(vector<int> &nums, int pos, int n, int sum, int k, set<int> st[]) {
        
        if(pos >= n) {
            st[k].insert(sum);
            return;
        }
        
        solve(nums, pos + 1, n, sum + nums[pos], k + 1, st);
        solve(nums, pos + 1, n, sum, k, st);
        
    }
    
    
    bool possible(int sum, int k, set<int> A[], int size1, set<int> B[], int size2) {
        
        for(int k1 = 0; k1 <= k; k1++) {
            if(k1 >= size1) break;
            int k2 = k - k1;   
            if(k2 >= size2) continue;
            for(int a : A[k1]) {
                if(B[k2].count(sum - a))
                    return true;
            }
            
        }
        
        return false;
    }
    
    
public:
    bool splitArraySameAverage(vector<int>& nums) {
        
        int n = nums.size();
        int m = n / 2;
        
        int t = 0;
        
        for(int &num : nums) 
            t += num;
        
        
        set<int> A[m + 2];
        set<int> B[n - m];
    
        solve(nums, 0, m + 1, 0, 0, A);
        solve(nums, m + 1, n, 0, 0, B);
        
        
        for(int k = 1; k < n; k++) {
            
            if((t * k) % n) continue;
            
            int s = (t * k) / n;
            
            if(possible(s, k, A, m + 2, B, n - m))
                return true;
        }
        
        return false;
        
    }
};
