class Solution {
    
    bool possible(vector<int> &A,  int idx) {
        int n = A.size();
        for(int i = idx;i < n;i++) {
            if(A[i] <= A[i-1]) return false;
        }
        return true;
    }
    
public:
    bool canBeIncreasing(vector<int>& nums) {
        
        int n = nums.size();

        for(int i = 1;i < n;i++) {
            
            if(nums[i] <= nums[i - 1]) {
               
                // i will be removed or i - 1 will be removed
                int prev = (i - 2 >= 0) ? nums[i - 2] : INT_MIN;
                int next = (i + 1 < n) ? nums[i + 1] : INT_MAX;
                
                // can remove i ?
                if(prev < nums[i - 1] and nums[i - 1] < next)
                    return possible(nums, i + 2);
                // can remove i - 1 ?
                else if(prev < nums[i] and nums[i] < next)
                    return possible(nums, i + 2);
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

