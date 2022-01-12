class Solution {
    
    bool possible(vector<int> &A, int prev, int idx) {
        int n = A.size();
        while(idx < n) {
            if(A[idx] <= prev) return false;
            prev = A[idx++];
        }
        return true;
    }
    
public:
    bool canBeIncreasing(vector<int>& nums) {
        
        int n = nums.size();
        int choice1 = -1;
        int choice2 = -1;
        for(int i = 1;i < n;i++) {
            
            if(nums[i] <= nums[i - 1]) {
               
                // i will be removed or i - 1 will be removed
                int prev = (i - 2 >= 0) ? nums[i - 2] : INT_MIN;
                int next = (i + 1 < n) ? nums[i + 1] : INT_MAX;
                
                // can remove i ?
                if(prev < nums[i - 1] and nums[i - 1] < next)
                    return possible(nums, next, i + 2);
                // can remove i - 1 ?
                else if(prev < nums[i] and nums[i] < next)
                    return possible(nums, next, i + 2);
                else
                    return false;
            }
        }
        return true;
    }
};

// 2 3 1 4 5 6
//     x

// 1 2 1000 3 4 5
//       x

