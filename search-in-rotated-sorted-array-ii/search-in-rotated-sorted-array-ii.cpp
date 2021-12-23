class Solution {
public:
    
    
    
    bool search(vector<int> &A, int x, int l, int r) {
        
        if(l > r) return false;
        
        int m = (l + r) / 2;
        
        
        if(A[m] == x) return true;
        
        // increase A[m]
        if(A[m] < x) {
            
            if(A[l] < A[m]) return search(A, x, m + 1, r);
            
            if(A[l] >= A[m]) return search(A, x, l, m - 1) or search(A, x, m + 1, r);
            
        }
        
        
        // decrease A[m]
        
        if(A[l] > A[m]) return search(A, x, l, m - 1);
        
        return search(A, x, l, m - 1) or search(A, x, m + 1, r);
        
    }
    
    bool search(vector<int>& nums, int target) {
        return search(nums, target, 0, (int)nums.size() - 1);
    }
};